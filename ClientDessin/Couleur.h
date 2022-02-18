#pragma once
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

class Couleur
{
	int R;
	int G;
	int B;
	Couleur(int r, int g, int b) {
		R = r;
		G = g;
		B = b;
	}
	
	int getR()const {
		return R;
	}
	int getG()const {
		return G;
	}
	int getB()const {
		return B;
	}

	void setR(int r) {
		R = r;
	}
	void setG(int g) {
		G = g;
	}
	void setB(int b)
	{
		B = b;
	}

	Couleur Cyan() {
		return Couleur(0,255,255);
	}
	Couleur Black() {
		return Couleur(0, 0, 0);
	}
	Couleur Blue() {
		return Couleur(0, 0, 255);
	}
	Couleur Red() {
		return Couleur(255,0,0);
	}
	Couleur Green() {
		return Couleur(0,255,0);
	}
	Couleur Yellow() {
		return Couleur(255, 255, 0);
	}
	string toString() const {
		string s;
		s = to_string(R) + "," + to_string(G)+","+ to_string(B);
	}


};

inline ostream& operator<<(ostream& s, const Couleur& c) {
	return s << c << endl;
}