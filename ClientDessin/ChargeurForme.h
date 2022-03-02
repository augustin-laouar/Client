#pragma once
#include <string>
#include "Forme2D.h"
using namespace std;
class ChargeurForme
{
public :
	virtual Forme2D * charger(string id)const = 0;
};

