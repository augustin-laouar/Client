#pragma once
#include <string>
#include "Forme2D.h"
#include <iostream>
#include <fstream> 
using namespace std;
class ChargeurForme
{
public :
	virtual Forme2D * charger(const string requete)const = 0;
};

