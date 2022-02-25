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
	Dessin(const Plan2D& Monde,int x = 200, int y = 200) {
		this->Monde = Monde;
		this->x = x;
		this->y = y;
	}
	int getX()const {
		return x;
	}
	int getY()const {
		return y;
	}
	void setX(int x) {
		if (x >= 50) {
			this->x = x;
		}
	}
	void setY(int y) {
		if (y >= 50) {
			this->y = y;
		}
	}
	/*
	* fonction qui associe une couleur a son format necessaire pour une requete
	*/
	string associerCouleur(Couleur c)const {

		return c.toString();
	}

	/*
	* cette methode va envoyer une requete au serveur pour dessiner la forme voulu 
	* format  d une requete  : numForme;nbpoint;x,y;couleur
	* la couleur est en format "r,g,b"
	*/
	
	
	virtual void visit(const Polygone* f) const{
		
		int nbp = f->getNbPoint();
		string requete = "3;";
		requete = requete + to_string(nbp) + ";"+ MondeEcran(f) + associerCouleur(f->getCouleur()) + "\n";

		try {
			Communication* comm = comm->getInstance();

			const char* R = requete.c_str();
			comm->Envoyer(R);
			cout << "Requete dessin de polygone envoyé : " << requete << endl;

		}
		catch (Erreur e)
		{
			cout << e.what(); // on affiche echec de connexion si celle ci echoue

		}

		
		
	}


	virtual void visit(const Trait* f) const{
		
		int nbp = 2;
		string requete = "1;";
		requete = requete + to_string(nbp) + ";" + MondeEcran(f) + associerCouleur(f->getCouleur()) + "\n";

		

		//envoi de la requet pour dessin 
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


	virtual void visit(const Cercle* f)const {
		
		//pour un cercle on envoi sous forme  : 2;nbPoints;rayon;centre;color
		
		string requete;

		requete = "2;1;" + to_string((int)f->getRayon())+ ";" + MondeEcran(f);
		
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
	virtual void visit(const GroupeForme* f)const {
		for (size_t i = 0; i < f->getNbForme(); i++) {
			visit(f->getForme(i));
		}
	}
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
	string MondeEcran(const FormeSimple *f)const {
		string res;
		Vecteur2D p1 = Monde.getAxeI();
		Vecteur2D p2 = Monde.getAxeJ();
		Vecteur2D p1bis(0, y);
		Vecteur2D p2bis(x, 0);
		double lambda = min((p2bis.x - p1bis.x) / (p2.x - p1.x), (p2bis.y - p1bis.y) / (p2.y - p1.y));
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
		a = Cbis.x - lambda * C.x;
		b = Cbis.y - lambda * C.y;
		Vecteur2D AB(a, b);
		Matrice2D Mat(lambda * e1, 0, 0, lambda * e2);
		Vecteur2D New;
		for (int i = 0; i < f->getNbPoint(); i++) {
			New = Mat * f->getPoint(i) * AB;
			res += (int)New.x + ",";
			res += (int)New.y + ";";
		}
		return res;
	}
	void Dessiner()const {
		try {
			Communication* comm = comm->getInstance();
			string RDim = "0;" + x; //requete pour envoi des dimentions de la fenetre java
			RDim += "," + y+(string)";\n";
			const char* R = RDim.c_str();
			comm->Envoyer(R);
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

