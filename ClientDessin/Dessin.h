#pragma once
#include "VisitorForme2D.h"
#include "Plan2D.h"
#include "Communication.h"
class Dessin :public VisitorForme2D
{
public:
	/*
	* fonction qui associe une couleur en int au format qui lui correspond en rgb
	*/
	string associerCouleur(int c)const {


		switch (c)
		{
		case 1: return "0,0,0"; // black
			break;
		case 2: return "0,0,255"; //blue 
			break;
		case 3: return "255,0,0"; //red
			break;
		case 4: return "0,255,0"; //green
			break;
		case 5: return "255,255,0"; //yellow
			break;
		case 6: return "0,255,255"; //cyan
			break;
		}

	}

	/*
	* cette methode va envoyer une requete au serveur pour dessiner la forme voulu 
	* format  d une requete  : numForme;nbpoint;x,y;couleur
	* la couleur est en format "r,g,b"
	*/
	
	
	virtual void visit(const Polygone* f) const{
		
		int nbp = f->getNbPoint();
		string p;
		string requete = "3;";
		for (int i = 0; i < nbp; i++)
		{
			p = p + to_string((int)(f->getPoint(i).x)) + "," + to_string((int)(f->getPoint(i).y)) + ";";
		}
		requete = requete + to_string(nbp) + ";"+ p + associerCouleur(f->getCouleur()) + "\n";

		try {
			Communication* comm = comm->getInstance();

			const char* R = requete.c_str();
			comm->Envoyer(R);

		}
		catch (Erreur e)
		{
			cout << e.what(); // on affiche echec de connexion si celle ci echoue

		}

		
		
	}


	virtual void visit(const Trait* f) const{
		
		int nbp = f->getNbPoint();
		string p;
		string requete = "1;";


		for (int i = 0; i < nbp; i++) //construction de la chaine nbp conteant les coordonnes des points
		{
			p = p+ to_string((int)(f->getPoint(i).x)) + "," + to_string((int)(f->getPoint(i).y) )+ ";";
		}
		requete = requete + to_string(nbp) + ";" +p + associerCouleur(f->getCouleur()) + "\n";

		

		//envoi de la requet pour dessin 
		try {
			Communication* comm = comm->getInstance();

			const char* R = requete.c_str();
			comm->Envoyer(R);
			cout << endl;
			cout << R << endl;

		}

		catch (Erreur e)
		{
			cout << e.what(); // on affiche echec de connexion si celle ci echoue

		}

		
	}


	virtual void visit(const Cercle* f)const {
		
		//pour un cercle on envoi sous forme  : 2;nbPoints;rayon;centre;color
		
		string requete;

		requete = "2;1;" + to_string((int)f->getRayon())+ ";" + to_string((int)(f->getPoint(0).x)) + "," + to_string((int)(f->getPoint(0).y)) + ";";
		
		requete = requete +  associerCouleur(f->getCouleur()) + "\n";


		//envoi de la requet pour dessin 
		try {
			Communication* comm = comm->getInstance();

			const char* R = requete.c_str();
			comm->Envoyer(R);

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

	void Dessiner(const Plan2D& p)const {
		for (int i = 0; i < p.nbFormes(); i++) {
			p.getForme(i)->accept(this);
		}
	}
};

