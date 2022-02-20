#pragma once
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

class Couleur
{
private:
	int R;
	int G;
	int B;
public:
	Couleur(int r, int g, int b) {
		R = r;
		G = g;
		B = b;
	}
	Couleur()
	{
		R = 0;
		G = 0;
		B = 0;
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

	static Couleur Cyan() {
		return Couleur(0,255,255);
	}
	static Couleur Black() {
		return Couleur(0, 0, 0);
	}
	static Couleur Blue() {
		return Couleur(0, 0, 255);
	}
	static Couleur Red() {
		return Couleur(255,0,0);
	}
	static Couleur Green() {
		return Couleur(0,255,0);
	}
	static Couleur Yellow() {
		return Couleur(255, 255, 0);
	}
	string toString() const {
		string s;
		s = to_string(R) + "," + to_string(G)+","+ to_string(B);
		return s;
	}


};

inline ostream& operator<<(ostream& s, const Couleur& c) {
	return s << c << endl;
}