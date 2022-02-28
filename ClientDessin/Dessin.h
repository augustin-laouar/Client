#pragma once
#include "VisitorForme2D.h"
#include "Plan2D.h"
#include "Communication.h"
#include "Matrice2D.h"
class Dessin :public VisitorForme2D
{
private : 
	int x;
	int y;
	Plan2D Monde;
public:
	/**
	* @brief Construction d'un dessin 
	* @param Monde le plan a dessiner avec les coordonnees monde reel 
	* @param x la largeur de la fenetre voulu (200 par defaut)
	* @param y la hauteur de la fenetre voulu (200 par defaut)
	*
	*/
	Dessin(const Plan2D& Monde,int x = 200, int y = 200) {
		this->Monde = Monde;
		this->x = x;
		this->y = y;
	}
	/**
	* @return Largeur de la fenetre a dessiner
	*/
	int getX()const {
		return x;
	}
	/**
	* @return hauteur de la fenetre a dessiner
	*/
	int getY()const {
		return y;
	}
	/**
	* @brief setter de largeur
	*/
	void setX(int x) {
		if (x >= 50) {
			this->x = x;
		}
	}
	/**
	* @brief setter de Hauteur
	*/
	void setY(int y) {
		if (y >= 50) {
			this->y = y;
		}
	}
	/*
	* @brief methode qui associe une couleur au format necessaire pour une requete
	*/
	string associerCouleur(Couleur c)const {

		return c.toString(); 
	}
	/**
	* @brief methode pour le design pattern visitor pour le dessin d'un polygone format requete : 3;nombreDePoints;coordonnees;couleur
	*/

	virtual void visit(const Polygone* f) const{
		
		int nbp = f->getNbPoint();
		string requete = "3;";
		requete = requete + to_string(nbp) + ";"+ MondeEcran(f) + associerCouleur(f->getCouleur()) + "\n"; //requete avec les coordonnes recalcule (passage monde->ecran

		try {
			Communication* comm = comm->getInstance();

			const char* R = requete.c_str();
			comm->Envoyer(R); //envoi de la requete 
			cout << "Requete dessin de polygone envoyé : " << requete << endl;

		}
		catch (Erreur e)
		{
			cout << e.what(); // on affiche echec de connexion si celle ci echoue

		}

	}
	/**
	* @brief methode pour le design pattern visitor pour le dessin d'un Trait format requete :1;nombreDePoints;coordonneesSepareeParDesVirgules;couleur
	*/

	virtual void visit(const Trait* f) const{
		
		int nbp = 2;
		string requete = "1;";
		requete = requete + to_string(nbp) + ";" + MondeEcran(f) + associerCouleur(f->getCouleur()) + "\n";

		

		//envoi de la requete pour dessin 
		try {
			Communication* comm = comm->getInstance();

			const char* R = requete.c_str();
			comm->Envoyer(R);
			cout << "Requete dessin de trait envoyé : " << requete << endl;

		}

		catch (Erreur e)
		{
			cout << e.what(); // on affiche echec de connexion si celle ci echoue

		}

		
	}

	/**
	* @brief methode pour le design pattern visitor pour le dessin d'un Cercle format requete :2;nombreDePoints;rayon;centre(x,y);couleur
	*/
	virtual void visit(const Cercle* f)const {
		
		//pour un cercle on envoi sous forme  : 2;nbPoints;rayon;centre;color
		
		string requete;
		Vecteur2D bordMonde(f->getCentre().x + f->getRayon(), f->getCentre().y);
		cout << " rayon : " << f->getRayon() << endl;
		Vecteur2D bordEcran(MondeEcranVecteur(bordMonde));
		Vecteur2D centreEcran(MondeEcranVecteur(f->getCentre()));
		Vecteur2D rayonEcran(bordEcran - centreEcran);
		cout << "rayon ecran : " << rayonEcran << endl;
		int newRayon = rayonEcran.norme();
		cout << " rayon apres : " << newRayon<< endl;
		requete = "2;1;" + to_string(newRayon)+ ";" + MondeEcran(f);
		
		requete = requete +  associerCouleur(f->getCouleur()) + "\n";


		//envoi de la requet pour dessin 
		try {
			Communication* comm = comm->getInstance();

			const char* R = requete.c_str();
			comm->Envoyer(R);
			cout << "Requete dessin de cercle envoyé : " << requete << endl;

		}
		catch (Erreur e)
		{
			cout << e.what(); // on affiche echec de connexion si celle ci echoue

		}
	}

	/**
	* @brief methode pour le dessin d'une forme simple
	*/

	virtual void visit(const FormeSimple* f)const {


		switch (f->whoAmI()) {
		case 10: {
			Cercle* c = (Cercle*)f;
			visit(c);
		}
			   break;
		case 11: {
			Polygone* p = (Polygone*)f;
			visit(p);
		}
			   break;
		case 12: {
			Trait* t = (Trait*)f;
			visit(t);
		}
		}
	
	}
	/**
	* @brief methode pour le dessin d'un groupe de formes
	*/
	virtual void visit(const GroupeForme* f)const {
		for (size_t i = 0; i < f->getNbForme(); i++) {
			visit(f->getForme(i));
		}
	}
	/**
	* @brief methode pour le dessin d'une forme2D en fonction du type de la forme 
	*/
	virtual void visit(const Forme2D* f)const {
		if (f->whoAmI() > 0) {
			FormeSimple* f2 = (FormeSimple*)f;
			visit(f2);
		}
		else {
			GroupeForme* f2 = (GroupeForme*)f;
			visit(f2);
		}
	}
//Plan2D(p5, 600, 300); //p1'(0,300) p2'(600,0) = rectangle ecran ( rect')
//rect p1(-0.3,-4.7) p2(7,5.2) ( rect )
	
	/**
	 * @brief methode pour le passage des coordonnes du monde reel a l ecran d'une forme simple 
	 * @return une chaine de caractere avec les nouvelles coordonnes au format voulu x1,y1;x2,y2 ...
	*/
	
	string MondeEcran(const FormeSimple *f)const {
		string res;
		double xMAX = Monde.xMAX();
		double xMIN = Monde.xMIN();
		double yMAX = Monde.yMAX();
		double yMIN = Monde.yMIN();
		Vecteur2D p1(xMIN,yMIN);
		Vecteur2D p2(xMAX,yMAX);
		Vecteur2D p1bis(0, y);
		Vecteur2D p2bis(x, 0);
		double lambda = min(abs(p2bis.x - p1bis.x) / abs(p2.x - p1.x), abs(p2bis.y - p1bis.y) / abs(p2.y - p1.y));
		int e1, e2;
		double a, b;
		if ((p2.x - p1.x) * (p2bis.x - p1bis.x) > 0) {
			e1 = 1;
		}
		else {
			e1 = 0;
		}
		if ((p2.y - p1.y) * (p2bis.y - p1bis.y) > 0) {
			e2 = 1;
		}
		else {
			e2 = -1;
		}
		Vecteur2D C((p1.x + p2.x) * 0.5, (p1.y + p2.y) * 0.5);
		Vecteur2D Cbis((p1bis.x + p2bis.x) * 0.5, (p1bis.y + p2bis.y) * 0.5);
		a = Cbis.x - (lambda * e1) * C.x;
		b = Cbis.y - (lambda * e2) * C.y;
		Vecteur2D AB(a, b);
		Matrice2D Mat(lambda * e1, 0, 0, lambda * e2);
		Vecteur2D New;
		int resX;
		int resY;
		for (int i = 0; i < f->getNbPoint(); i++) {
			New = (Mat * f->getPoint(i)) + AB;
			resX = New.x;
			resY = New.y;
			res += to_string(resX) + (string)",";
			res += to_string(resY) + (string)";";		}
		return res;
	}
	/**
	* @brief 
	*/
	Vecteur2D MondeEcranVecteur(const Vecteur2D v)const {
		double xMAX = Monde.xMAX();
		xMAX += xMAX * 0.1;
		double xMIN = Monde.xMIN();
		xMIN -= xMIN * 0.1;
		double yMAX = Monde.yMAX();
		yMAX += yMAX * 0.1;
		double yMIN = Monde.yMIN();
		yMIN -= yMIN * 0.1;
		Vecteur2D p1(xMIN, yMIN);
		Vecteur2D p2(xMAX, yMAX);
		Vecteur2D p1bis(0, y);
		Vecteur2D p2bis(x, 0);
		double lambda = min(abs(p2bis.x - p1bis.x) / abs(p2.x - p1.x), abs(p2bis.y - p1bis.y) / abs(p2.y - p1.y));
		int e1, e2;
		double a, b;
		if ((p2.x - p1.x) * (p2bis.x - p1bis.x) > 0) {
			e1 = 1;
		}
		else {
			e1 = 0;
		}
		if ((p2.y - p1.y) * (p2bis.y - p1bis.y) > 0) {
			e2 = 1;
		}
		else {
			e2 = -1;
		}
		Vecteur2D C((p1.x + p2.x) * 0.5, (p1.y + p2.y) * 0.5);
		Vecteur2D Cbis((p1bis.x + p2bis.x) * 0.5, (p1bis.y + p2bis.y) * 0.5);
		a = Cbis.x - (lambda * e1) * C.x;
		b = Cbis.y - (lambda * e2) * C.y;
		Vecteur2D AB(a, b);
		Matrice2D Mat(lambda * e1, 0, 0, lambda * e2);
		Vecteur2D New;
		New = (Mat * v) + AB;
		return New;
	}

	/*
	* @brief cette methode va envoyer une requete au serveur pour dessiner la forme voulu
	* format  d une requete  : numeroForme;nbpoint;x1,y1;x2,y2;....;couleur
	* la couleur est en format "r,g,b"
	*/

	void Dessiner()const {
		try {
			Communication* comm = comm->getInstance();
			string RDim = "0;" + to_string(x); //requete pour envoi des dimentions de la fenetre java
			RDim += ";" + to_string(y)+(string)";\n";
			const char* R = RDim.c_str();
			comm->Envoyer(R); // envoi de la premiere requete pour initialiser la hauteur et largeur de la fenetre cote java
			
			cout << "Taille de la fenetre envoye : " << R << endl;
			cout << "Dessin des formes du plan..." << endl;
			
			for (int i = 0; i < Monde.nbFormes(); i++) {
				Monde.getForme(i)->accept(this);
			}
			const char* R2 = "-1"; // marque la fin des envois
			comm->Envoyer(R2);
			cout << "Dessin des formes du plan terminé." << endl;
		}
		catch (Erreur e)
		{
			cout << e.what(); // on affiche echec de connexion si celle ci echoue

		}
		
	}
};

