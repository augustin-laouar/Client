#pragma once
#include "Vecteur2D.h"
#include "Cercle.h"
#include <cmath>
class Plan2D
{
	//AXE J
	// ^
	// |
	// |
	//-|------> AXE I
	// O      
private:
	vector<Forme2D*>FormesDuPlan;
public:
	Plan2D(){}
	Plan2D(const Plan2D& p) {
		for (size_t i = 0; i < p.FormesDuPlan.size(); i++) {
			FormesDuPlan.push_back(p.getForme(i));
		}
	}
	int nbFormes()const {
		return FormesDuPlan.size();
	}
	void ajouterForme(const Forme2D* f) {
		FormesDuPlan.push_back(f->clone());
	}
	Forme2D* getForme(int i)const {
		return FormesDuPlan[i]->clone();
	}
	double xMAX()const {
		double max = DBL_MIN;
		for (size_t i = 0; i < FormesDuPlan.size(); i++) {
			if (max < FormesDuPlan[i]->xMAX()) {
				max = FormesDuPlan[i]->xMAX();
			}
		}
		return max;
	}
	double yMAX()const {
		double max = DBL_MIN;
		for (size_t i = 0; i < FormesDuPlan.size(); i++) {
			if (max < FormesDuPlan[i]->yMAX()) {
				max = FormesDuPlan[i]->yMAX();
			}
		}
		return max;
	}
	double xMIN()const {
		double min = DBL_MAX;
		for (size_t i = 0; i < FormesDuPlan.size(); i++) {
			if (min > FormesDuPlan[i]->xMIN()) {
				min = FormesDuPlan[i]->xMIN();
			}
		}
		return min;
	}
	double yMIN()const {
		double min = DBL_MAX;
		for (size_t i = 0; i < FormesDuPlan.size(); i++) {
			if (min > FormesDuPlan[i]->yMIN()) {
				min = FormesDuPlan[i]->yMIN();
			}
		}
		return min;
	}
	Plan2D* clone()const {
		return new Plan2D(*this);
	}
};

