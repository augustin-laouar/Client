#pragma once
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

class Couleur
{

	/**
	* @class  classe representant les couleurs en fonction de leurs niveau de ROUGE VERT ET BLEU 
	*/
private:
	int R;
	int G;
	int B;
public:
	/**
	* @brief constructeur 
	*/
	Couleur(int r, int g, int b) {
		R = r;
		G = g;
		B = b;
	}
	/** 
	* @brief constructeur par defaut : par defaut la couleur du dessin est ke noir 
	*/
	Couleur()
	{
		R = 0;
		G = 0;
		B = 0;
	}
	/**
	* @return Niveau de Rouge
	*/
	int getR()const {
		return R;
	}
	/**
	* @return Niveau de Vert
	*/
	int getG()const {
		return G;
	}
	/**
	* @return Niveau de Bleu
	*/

	int getB()const {
		return B;
	}
	/**
	* @brief setter du Rouge
	*/

	void setR(int r) {
		R = r;
	}
	/**
	* @brief setter de Vert
	*/
	void setG(int g) {
		G = g;
	}
	/**
	* @brief setter de Bleu
	*/
	void setB(int b)
	{
		B = b;
	}
	/**
	* @brief construction de la couleur Cyan 
	*/

	static Couleur Cyan() {
		return Couleur(0,255,255);
	}
	/**
	* @brief construction de la couleur Noir 
	*/
	static Couleur Black() {
		return Couleur(0, 0, 0);
	}
	/**
	* @brief construction de la couleur Bleu
	*/
	static Couleur Blue() {
		return Couleur(0, 0, 255);
	}
	/**
	* @brief construction de la couleur Rouge
	*/
	
	static Couleur Red() {
		return Couleur(255,0,0);
	}
	/**
	* @brief construction de la couleur Vert 
	*/
	static Couleur Green() {
		return Couleur(0,255,0);
	}
	/**
	* @brief construction de la couleur Jaune 
	*/
	static Couleur Yellow() {
		return Couleur(255, 255, 0);
	}
	/**
	* @return une chaine de couleur  sous format R,G,B (format utilise pour l envoi d une requete)
	*/
	string toString() const {
		string s;
		s = to_string(R) + "," + to_string(G)+","+ to_string(B);
		return s;
	}
	/**
	* @brief operator string 
	*/
	operator string() const
	{
		return this->toString();
	}

};
/**
* @brief redefinition de l'operator <<
*/
inline ostream& operator<<(ostream& s, const Couleur& c) {
	return s << c << endl;
}