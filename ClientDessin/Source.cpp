#pragma once
#include <iostream>
#include "Trait.h"
#include "Cercle.h"
#include "Polygone.h"
#include "Vecteur2D.h"
#include "Communication.h"
#include "Matrice2D.h"
#include "Plan2D.h"
#include "Dessin.h"
#include "Triangle.h"
#include "Enregistreur.h"
#include "ChargeurCercle.h"
#include "ChargeurTrait.h"
#include "ChargeurGroupe.h"
#include "ChargeurPolygone.h"
#include "Chargeur.h"


/* NOTES
* Main qui présente des exemples de tests des différentes fonctionnalités de l'application
* Le code permettant d'appliquer des opération aux formes, d'enregistrer et de charger une forme sont en commentaires par défaut
* Enlever les commmentaires pour tester les opérations
*/ 
int main() {

	try {
		//TEST DU DESSIN DE FORMES


		Plan2D Plan;
		Vecteur2D p1(1, 1);
		Vecteur2D p2(1, 4);
		Vecteur2D p3(5, 4);
		Vecteur2D p4(5, 1);
		vector<Vecteur2D> v;
		v.push_back(p1);
		v.push_back(p2);
		v.push_back(p3);
		v.push_back(p4);
		Polygone rectangle(v, Couleur::Blue());
		Vecteur2D p5(10.5, 12);
		Cercle cercleRouge(p5, 3, Couleur::Red());
		Vecteur2D p6(1.5, 10);
		Vecteur2D p7(-1.5, 11);
		Vecteur2D p8(0, 14.2);
		Triangle triangleNoir(p6, p7, p8, Couleur::Black());
		GroupeForme groupe(Couleur::Yellow());
		Trait trait(Vecteur2D(5, 17.2), Vecteur2D(7, 10.7), Couleur::Red());
		Cercle cercle(Vecteur2D(10.2, -4.5), 3.8, Couleur::Cyan());
		groupe.ajouterForme(&trait);
		groupe.ajouterForme(&cercle);
		GroupeForme groupe2(Couleur::Cyan());
		Trait trait2(Vecteur2D(-6, 17.2), Vecteur2D(-2, 10.7), Couleur::Red());
		groupe2.ajouterForme(&trait2);
		groupe2.ajouterForme(&groupe);
		Vecteur2D p11(-1, -1);
		Vecteur2D p12(-1, -5);
		Vecteur2D p13(-5, -5);
		Vecteur2D p14(-5, -1);
		vector<Vecteur2D> v2;
		v2.push_back(p11);
		v2.push_back(p12);
		v2.push_back(p13);
		v2.push_back(p14);
		Couleur couleurAleatoire(127, 196, 24);
		Polygone carre(v2, couleurAleatoire);



		//TEST DES OPERATION 


	/*	rectangle.rotation(Vecteur2D(0, 0), 1.78);
		triangleNoir.translation(Vecteur2D(10, 10));
		cercleRouge.homothetie(cercleRouge.getCentre(), 5);*/



		//AJOUT DES FORMES AU PLAN



		Plan.ajouterForme(&rectangle);
		Plan.ajouterForme(&cercleRouge);
		Plan.ajouterForme(&triangleNoir);
		Plan.ajouterForme(&groupe2);
		Plan.ajouterForme(&carre);



		//ENREGISTREMENT



		//Enregistreur e("test.txt");
		//e.EnregistrerPlan(Plan); // enregistrement d'un plan
		//Enregistreur e2("test2.txt");
		//cercleRouge.accept(&e2); // enregistrement d'une forme simple


		//CHARGEMENT



		/*Chargeur c;
		Plan2D PlanCopie(*c.chargerPlan("test.txt"));
		Cercle cercleCopie(*c.chargerCercle("test2.txt"));
		Dessin d2(PlanCopie, 1000, 800);*/

		//DESSIN 



		Dessin d(Plan, 1000, 800); 
		d.Dessiner(); //remplacer d par d2 si on veut dessiner le plan d2 qui a ete charger
		Communication::getInstance()->FermerConnexion();


	}
	catch(Erreur e) {
		cout << "ERREUR : " << endl;
		cout << e.what() << endl;
	}
}

