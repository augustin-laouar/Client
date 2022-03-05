#pragma once
#include <string>
#include "Forme2D.h"
#include <iostream>
#include <fstream> 
#pragma warning(disable : 4996)
using namespace std;
class ChargeurForme
{
public :
	
	virtual Forme2D * charger(const string fichier, const string id = "0")const = 0; // par defaut id = 0 car lorsque l'on enregistre une forme
	// seule son id sera 0 par defaut
};

