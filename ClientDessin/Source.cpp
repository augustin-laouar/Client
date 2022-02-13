#include <iostream>
#include "Trait.h"
#include "Cercle.h"
#include "Polygone.h"
#include "Vecteur2D.h"
#include "Communication.h"

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

	Point2D p1 (45, 58);
	Point2D p2(48, 58);
	Point2D p3(p2); //construction par copie 
	Point2D p4 = p1;
	cout << "TEST CLASSE POINT2D " << endl;
	cout << "p1: " << p1 << endl;
	
	cout << "test operation == et construction par copie: ";
	if (p3 == p2) cout << "p3==p2 test ok" << endl;
	else cout << "p1 != p2 test non ok" << endl;
	
	if (p1 == p2) cout << "p1 == p2 test non ok" << endl;
	else cout << "p1 != p2 test  ok" << endl;
	

	cout << "test affectation d'un point a un autre : ";
	if (p4 == p1) cout << "p4==p1 test ok " << endl;
	else cout << "p4!=p1 test non ok" << endl;


	
	cout << "==============================================================================================" <<endl;
	cout << endl;

	//TEST CLASSE Vecteur2D

	Vecteur2D v1(15, 20);
	Vecteur2D v2(25, 10);
	
	cout << "TEST CLASSE VECTEUR2D " << endl;
	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;

	cout << "test addition de deux vecteurs :";
	Vecteur2D v3 = v1 + v2;
	cout << "test v3 =v1+ v2 : v3 => " << v3 << endl;

	cout << "test multiplication : ";
	Vecteur2D v4 = v1 * 2;
	cout << "test v4=v1*2 : v4 =>" << v4 << endl;

	cout << "test operator - : ";
	Vecteur2D v5 = -v1;
	cout << "test  v5 = -v1 : v5 => " << v5 << endl;


	cout << "==============================================================================================" << endl;
	cout << endl;

	
	//TEST CLASSE CERCLE  
	Cercle c1(p1,120,2);
	Cercle c2(p1, 110, 2);
	Cercle c3(c2);
	Cercle c4 = c1;
	cout << "TEST CLASSE CERCLE" << endl;
	cout << "c1 :" << c1 <<endl ;
	
	cout << "test operation == et construction par copie : ";
	if (c3 == c2) cout << "c3==c2 test  ok" << endl;
	else cout << "c3 != c2 test non ok" << endl;
	if (c1 == c2) cout << "c1==c2  test non ok" << endl;
	else cout << "c1!=c2 test ok" << endl;

	
	cout << "test affectation d'un cercle a un autre : ";
	if (c4 == c1) cout << "c4==c1 test ok " << endl;
	else cout <<"c4!=c1 test non ok" << endl;
	
	cout << "=============================================================================================="<< endl;
	cout << endl;
	
	
	cout << "TEST CLASSE TRAIT" << endl;
	

	Point2D p5(45, 58);
	Point2D p6(52, 10);
	Point2D p7(12, 15);
	Point2D p8(23, 42);

	Trait t1(p5,p6,1);
	Trait t2(p7,p8,2);
	Trait t3(t2); //construction par copie 
	Trait t4 = t1;
	
	cout << "T1: " << t1 << endl;

	cout << "test operation == et construction par copie: ";
	if (t3 == t2) cout << "t3==t2 test ok" << endl;
	else cout << "t1 != t2 test non ok" << endl;

	if (t1 == t2) cout << "t1 == t2 test non ok" << endl;
	else cout << "t1 != t2 test  ok" << endl;


	cout << "test affectation d'un trait a un autre : ";
	if (t4 == t1) cout << "t4==t1 test ok " << endl;
	else cout << "t4!=t1 test non ok" << endl;

	cout << "==============================================================================================" <<endl;
	cout << endl;

	cout << "TEST CLASSE POLYGONE " << endl;
	vector<Point2D> listePoints;
	listePoints.push_back(p1);
	listePoints.push_back(p2);
	listePoints.push_back(p5);
	listePoints.push_back(p6);
	Polygone po1(listePoints,1);
	

	vector<Point2D> listePoints2;
	listePoints2.push_back(p2);
	listePoints2.push_back(p3);
	listePoints2.push_back(p5);
	listePoints2.push_back(p6);

	Polygone po2(listePoints2,2);
	Polygone po3(po2); //construction par copie 
	Polygone po4 = po1;

	cout << "PO1: " << po1 << endl;

	cout << "test operation == et construction par copie: ";
	if (po3 == po2) cout << "po3==po2 test ok" << endl;
	else cout << "po3 != po2 test non ok" << endl;

	if (po1 == po2) cout << "po1 == po2 test non ok" << endl;
	else cout << "po1 != po2 test  ok" << endl;


	cout << "test affectation d'un polygone a un autre : ";
	if (po4 == po1) cout << "po4 == po1 test ok " << endl;
	else cout << "po4!=po1 test non ok" << endl;

	cout << "==============================================================================================" << endl;
	cout << endl;
	cout << "TEST DE FONCTIONNALITE" << endl;
	cout << " *test Translation" << endl;


	cout << "   1) cercle : c1 par rapport a v1 " << endl;
	cout << "    c1 :" << c1 << endl;
	cout << "    v1 :" << v1 << endl;
	c1.translation(v1);
	cout << "    c1 apres translation : " << c1<< endl;
	cout << endl;
	
	
	cout << "   2) Trait : t1 par rapport a v1 " << endl;
	cout << "    t1 :" << t1 << endl;
	cout << "    v1 :" << v1 << endl;
	t1.translation(v1);
	cout << "    t1 apres translation : " << t1 << endl;
	cout << endl;

	cout << "   2) Polygone : po1 par rapport a v1 " << endl;
	cout << "    po1 :" << po1 << endl;
	cout << "    v1 :" << v1 << endl;
	po1.translation(v1);
	cout << "    po1 apres translation : " << po1 << endl;
	cout << endl;


	cout << "----------------------------------" << endl;
	cout << " *test homothetie" << endl;

	cout << "   1) cercle : c1  avec p1 et z=10" << endl;
	cout << "    c1 : " << c1 << endl;
	cout << "    p1 : " << p1 << endl;
	c1.homothetie(p1,10);
	cout << "    c1 apres homothetie : " << c1 << endl;
	cout << endl;

	cout << "   2)trait : t1  avec p1 et z=10" << endl;
	cout << "    t1 :" << t1 << endl;
	cout << "    p1 : " << p1 << endl;
	t1.homothetie(p1, 10);
	cout << "    t1 apres homothetie : " << t1 << endl;
	cout << endl;

	cout << "   3)polygone : po1  avec p1 et z=10" << endl;
	cout << "    po1 :" << po1 << endl;
	cout << "    p1 : " << p1 << endl;
	po1.homothetie(p1, 10);
	cout << "    po1 apres homothetie : " << po1 << endl;
	cout << endl;

	// test de communication 
	cout << "TEST DE COMMUNICATION" << endl;
	char trait []= "1;2;410,450;480,525"; // dessin d un trait 
	char polygone[] = "3;6;410,460;460,415;500,425;480,435;550,445;410,460"; //dessin polygone

	char adresse[] = "127.0.0.1";
	Communication comm(adresse,9111);
	comm.Envoyer(trait);
	comm.FermerConnexion();


}

