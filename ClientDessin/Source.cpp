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

/* NOTES
Methode obligatoires dans une classe :
-constructeur et constructeur par copie
-destructeur ( uniquement si besoin )
-getter setter si données membres sont private
-methode ajouté et retiré si contient un vector
-getNb... si contient un vector ( doit renvoyé le nombre d'élément )
- toString et clone
-Operator string , == , = et + - dans le cas d'une classe avec vector
- operator <<

*/ 
int main() {
	//TEST CLASSE POINT2D
//
//	Point2D p1 (45, 58);
//	Point2D p2(48, 58);
//	Point2D p3(p2); //construction par copie 
//	Point2D p4 = p1;
//	cout << "TEST CLASSE POINT2D " << endl;
//	cout << "p1: " << p1 << endl;
//	
//	cout << "test operation == et construction par copie: ";
//	if (p3 == p2) cout << "p3==p2 test ok" << endl;
//	else cout << "p1 != p2 test non ok" << endl;
//	
//	if (p1 == p2) cout << "p1 == p2 test non ok" << endl;
//	else cout << "p1 != p2 test  ok" << endl;
//	
//
//	cout << "test affectation d'un point a un autre : ";
//	if (p4 == p1) cout << "p4==p1 test ok " << endl;
//	else cout << "p4!=p1 test non ok" << endl;
//
//
//	
//	cout << "==============================================================================================" <<endl;
//	cout << endl;
//
//	//TEST CLASSE Vecteur2D
//
//	Vecteur2D v1(150, 200);
//	Vecteur2D v2(25, 10);
//	
//	cout << "TEST CLASSE VECTEUR2D " << endl;
//	cout << "v1: " << v1 << endl;
//	cout << "v2: " << v2 << endl;
//
//	cout << "test addition de deux vecteurs :";
//	Vecteur2D v3 = v1 + v2;
//	cout << "test v3 =v1+ v2 : v3 => " << v3 << endl;
//
//	cout << "test multiplication : ";
//	Vecteur2D v4 = v1 * 2;
//	cout << "test v4=v1*2 : v4 =>" << v4 << endl;
//
//	cout << "test operator - : ";
//	Vecteur2D v5 = -v1;
//	cout << "test  v5 = -v1 : v5 => " << v5 << endl;
//
//
//	cout << "==============================================================================================" << endl;
//	cout << endl;
//
//	
//	//TEST CLASSE CERCLE  
//	Cercle c1(p1,120,2);
//	Cercle c2(p1, 110, 2);
//	Cercle c3(c2);
//	Cercle c4 = c1;
//	cout << "TEST CLASSE CERCLE" << endl;
//	cout << "c1 :" << c1 <<endl ;
//	
//	cout << "test operation == et construction par copie : ";
//	if (c3 == c2) cout << "c3==c2 test  ok" << endl;
//	else cout << "c3 != c2 test non ok" << endl;
//	if (c1 == c2) cout << "c1==c2  test non ok" << endl;
//	else cout << "c1!=c2 test ok" << endl;
//
//	
//	cout << "test affectation d'un cercle a un autre : ";
//	if (c4 == c1) cout << "c4==c1 test ok " << endl;
//	else cout <<"c4!=c1 test non ok" << endl;
//	
//	cout << "=============================================================================================="<< endl;
//	cout << endl;
//	
//	
//	cout << "TEST CLASSE TRAIT" << endl;
//	
//
//	Point2D p5(45, 58);
//	Point2D p6(52, 10);
//	Point2D p7(12, 15);
//	Point2D p8(23, 42);
//
//	Trait t1(p5,p6,1);
//	Trait t2(p7,p8,2);
//	Trait t3(t2); //construction par copie 
//	Trait t4 = t1;
//	
//	cout << "T1: " << t1 << endl;
//
//	cout << "test operation == et construction par copie: ";
//	if (t3 == t2) cout << "t3==t2 test ok" << endl;
//	else cout << "t1 != t2 test non ok" << endl;
//
//	if (t1 == t2) cout << "t1 == t2 test non ok" << endl;
//	else cout << "t1 != t2 test  ok" << endl;
//
//
//	cout << "test affectation d'un trait a un autre : ";
//	if (t4 == t1) cout << "t4==t1 test ok " << endl;
//	else cout << "t4!=t1 test non ok" << endl;
//
//	cout << "==============================================================================================" <<endl;
//	cout << endl;
//
//	cout << "TEST CLASSE POLYGONE " << endl;
//	vector<Point2D> listePoints;
//	listePoints.push_back(p1);
//	listePoints.push_back(p2);
//	listePoints.push_back(p5);
//	listePoints.push_back(p6);
//	Polygone po1(listePoints,1);
//	
//
//	vector<Point2D> listePoints2;
//	listePoints2.push_back(p2);
//	listePoints2.push_back(p3);
//	listePoints2.push_back(p5);
//	listePoints2.push_back(p6);
//
//	Polygone po2(listePoints2,2);
//	Polygone po3(po2); //construction par copie 
//	Polygone po4 = po1;
//
//	cout << "PO1: " << po1 << endl;
//
//	cout << "test operation == et construction par copie: ";
//	if (po3 == po2) cout << "po3==po2 test ok" << endl;
//	else cout << "po3 != po2 test non ok" << endl;
//
//	if (po1 == po2) cout << "po1 == po2 test non ok" << endl;
//	else cout << "po1 != po2 test  ok" << endl;
//
//
//	cout << "test affectation d'un polygone a un autre : ";
//	if (po4 == po1) cout << "po4 == po1 test ok " << endl;
//	else cout << "po4!=po1 test non ok" << endl;
//
//	cout << "==============================================================================================" << endl;
//	cout << endl;
//	cout << "TEST DE FONCTIONNALITE" << endl;
//	cout << " *test Translation" << endl;
//
//
//	cout << "   1) cercle : c1 par rapport a v1 " << endl;
//	cout << "    c1 :" << c1 << endl;
//	cout << "    v1 :" << v1 << endl;
//	c1.translation(v1);
//	cout << "    c1 apres translation : " << c1<< endl;
//	cout << endl;
//	
//	
//	cout << "   2) Trait : t1 par rapport a v1 " << endl;
//	cout << "    t1 :" << t1 << endl;
//	cout << "    v1 :" << v1 << endl;
//	t1.translation(v1);
//	cout << "    t1 apres translation : " << t1 << endl;
//	cout << endl;
//
//	cout << "   2) Polygone : po1 par rapport a v1 " << endl;
//	cout << "    po1 :" << po1 << endl;
//	cout << "    v1 :" << v1 << endl;
//	po1.translation(v1);
//	cout << "    po1 apres translation : " << po1 << endl;
//	cout << endl;
//
//
//	cout << "----------------------------------" << endl;
//	cout << " *test homothetie" << endl;
//
//	cout << "   1) cercle : c1  avec p1 et z=10" << endl;
//	cout << "    c1 : " << c1 << endl;
//	cout << "    p1 : " << p1 << endl;
//	c1.homothetie(p1,10);
//	cout << "    c1 apres homothetie : " << c1 << endl;
//	cout << endl;
//
//	cout << "   2)trait : t1  avec p1 et z=10" << endl;
//	cout << "    t1 :" << t1 << endl;
//	cout << "    p1 : " << p1 << endl;
//	t1.homothetie(p1, 10);
//	cout << "    t1 apres homothetie : " << t1 << endl;
//	cout << endl;
//
//	cout << "   3)polygone : po1  avec p1 et z=10" << endl;
//	cout << "    po1 :" << po1 << endl;
//	cout << "    p1 : " << p1 << endl;
//	po1.homothetie(p1, 10);
//	cout << "    po1 apres homothetie : " << po1 << endl;
//	cout << endl;
//
//
//	//TEST MATRICES
//	cout << "==============================================================================================" << endl;
//	cout << endl;
//
//	cout << "TEST CLASSE MATRICE2D " << endl;
//	Matrice2D m;
//	m.ajouterVecteur(v1);
//	cout << " m après l'ajout de v1 : " << m << endl;
//	m.ajouterVecteur(v2);
//	m.ajouterVecteur(v3);
//	cout << " m après l'ajout de v2 et v3 : " << m << endl;
//	m.retirerVecteur(v2);
//	cout << " m après la suppression de v2 : " << m << endl;
//	m.ajouterVecteur(v5);
//	cout << " m après l'ajout de v5 : " << m << endl;
//	m.retirerVecteur(1);
//	cout << " m après retirer le vecteur à l'indice 1 " << m << endl;
//	cout << " taille de m  : " << m.taille() << endl;
//	m.ajouterVecteur(v3);
//	cout << " m après ajout de v3" << m << endl;
//	Matrice2D m2;
//	m2.ajouterVecteur(v2);
//	m2.ajouterVecteur(v5);
//	cout << " m2 : " << m2 << endl;
//	cout << "m2*m : " << m2 * m << endl;
//	cout << "m*5 : " << m*5 << endl;
//
//	// test de communication 
//	cout << "TEST DE COMMUNICATION" << endl;
//
//	char trait[] = "1;2;410,450;480,525;0,255,255\n"; // dessin d un trait
//	char trait2[] = "1;2;560,650;555,795;0,0,0\n";
//	char polygone[] = "3;6;410,460;460,415;500,425;480,435;550,445;410,460;0,255,255\n"; //dessin polygone
//	char cercle[] = "2;1;50;410,460;0,255,255\n";
//	char adresse[] = "127.0.0.1";
//
//	
//
//	Point2D p56;
//	Point2D p57;
//	Point2D p58;
//	
//	p56.x = 410;
//	p56.y = 450;
//	
//	p57.x = 480;
//	p57.y = 525;
//	p58.x = 430;
//	p58.y = 442;
//
//	Trait t(p56,p57,2);
//	cout << "Avant rotation" << endl;
//	cout << "p1:" << t.getP1();
//	cout << "p2:" << t.getP2() << endl;
//	Trait tPrime(t);
//	tPrime.translation(v1);
//	tPrime.rotation(tPrime.getP1(), 1.57);
//
//	cout << "p1:"<< tPrime.getP1();
//	cout << "p2:" <<tPrime.getP2()<<endl;
//
///*	try
//	{
//		Communication* comm = comm->getInstance(adresse, 9111);
//		comm->Envoyer(trait);
//		Sleep(500);
//		comm->Envoyer(trait2);
//		//comm.Envoyer(cercle);
//	//comm.Envoyer(polygone);
//		comm->FermerConnexion();
//
//	}
//	catch (Erreur e)
//	{
//		cout << e.what();
//
//	}
//	*/

    Vecteur2D v1(150, 200);
	Vecteur2D v2(25, 10);

	Vecteur2D p56;
	Vecteur2D p57;
	Vecteur2D p58;
	
	

	Vecteur2D p1(45, 58);
	
	
	p56.x = 410;
	p56.y = 450;
	
	p57.x = 480;
	p57.y = 525;
	p58.x = 430;
	p58.y = 442;

	Couleur c = c.Red();
	Cercle c1(p1, 120, c);
	Cercle c2(p1, 110,Couleur::Green());

	Trait* t85 = new Trait(p56, p57,c);
	vector<Vecteur2D>Points;
	Vecteur2D p100(415, 550);
	Vecteur2D p101(400, 700);
	Vecteur2D p102(450, 650);
	Points.push_back(p100);
	Points.push_back(p101);
	Points.push_back(p102);
	Polygone* po85 = new Polygone(Points,c);
	Plan2D plan;
	plan.ajouterForme(t85);
	plan.ajouterForme(&c1);
	plan.ajouterForme(&c2);
	plan.ajouterForme(po85);
	Trait* t86 = new Trait(*t85);
	t86->translation(v1);
	t86->setCouleur(Couleur::Cyan());
	Polygone* po86 = new Polygone(*po85);
	Vecteur2D p103(390, 400);
	po86->rotation(p103, 1.57);
	po86->setCouleur(Couleur::Red());
	plan.ajouterForme(po86);
	plan.ajouterForme(t86);
	Dessin d;
	d.Dessiner(plan);
	Communication* com = com->getInstance();
	com->FermerConnexion();

//Vecteur2D p1(0, 3);
//Vecteur2D p2(2, 5);
//Vecteur2D p3(4, 3);
//Vecteur2D p4(4, 1);
//Vecteur2D p5(0, 1);
//
//vector<Vecteur2D> points;
//points.push_back(p1);
//points.push_back(p2);
//points.push_back(p3);
//points.push_back(p4);
//points.push_back(p5);
//
//Polygone carre(points,Couleur::Black());
//cout << carre << endl;
//cout << carre.Aire() << endl;

	
	





}

