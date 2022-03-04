#pragma once
#include "ChargeurCercle.h"
#include "ChargeurTrait.h"
#include "ChargeurGroupe.h"
#include "ChargeurPolygone.h"
#include "Plan2D.h"
class Chargeur
{
public :
	string trouverRequete(FILE*fd,string id) {
		char buffer[BUFSIZ];
		string comparateur;
		while (fgets(buffer, BUFSIZ, fd)) {
			for (int i = 0; buffer[i] != ':'; i++) {
				comparateur += buffer[i]; //recupere l'id char par char
			}
			if (id == comparateur) {
				int iterateur =0;
				string requete;
				while (buffer[iterateur] != '\n' && buffer[iterateur] != '\0') {
					if (buffer[iterateur] == '[') {
						int nbCrochet = 1;
						while (nbCrochet != 0) {
							fgets(buffer, BUFSIZ, fd);
							requete += buffer[iterateur];
							if (buffer[iterateur] == '[')
								nbCrochet++;
							if (buffer[iterateur] == ']')
								nbCrochet--;
							iterateur++;
						}
						requete += ']';
						return requete;
					}
					requete+= buffer[iterateur];
					iterateur++;
				}
				return requete;
			}
			comparateur.clear();
		}
		throw Erreur("Id non trouvé");
	}
	Forme2D* traiteRequete(string requete) {
		ChargeurGroupe* cg = new ChargeurGroupe();
		ChargeurCercle* cc = new ChargeurCercle(cg);
		ChargeurTrait* ct = new ChargeurTrait(cc);
		ChargeurPolygone* cp = new ChargeurPolygone(ct);
		return cp->charger(requete);
	}
	Trait* chargerTrait(string id,FILE * fd) {
		string rq = trouverRequete(fd, id);
		Trait * t = dynamic_cast<Trait*>(traiteRequete(rq));
		if (t == NULL) {
			throw Erreur("ID non trouvé ou type de forme invalide");
		}
		return t;
	}
	Cercle* chargerCercle(string id, FILE* fd) {
		string rq = trouverRequete(fd, id);
		Cercle* c = dynamic_cast<Cercle*>(traiteRequete(rq));
		if (c == NULL) {
			throw Erreur("ID non trouvé ou type de forme invalide");
		}
		return c;
	}
	Polygone* chargerPolygone(string id, FILE* fd) {
		string rq = trouverRequete(fd, id);
		Polygone* p = dynamic_cast<Polygone*>(traiteRequete(rq));
		if (p == NULL) {
			throw Erreur("ID non trouvé ou type de forme invalide");
		}
		return p;
	}
	GroupeForme* chargerGroupe(string id, FILE * fd) {
		string rq = trouverRequete(fd, id);
		GroupeForme * g = dynamic_cast<GroupeForme*>(traiteRequete(rq));
		if (g == NULL) {
			throw Erreur("ID non trouvé ou type de forme invalide");
		}
		return g;
	}
	Plan2D* chargerPlan(string id, FILE* fd) {
		char buffer[BUFSIZ];
		string comparateur;
		string requete;
		while (fgets(buffer, BUFSIZ, fd)) {
			for (int i = 0; buffer[i] != ':'; i++) {
				comparateur += buffer[i]; //recupere l'id char par char
			}
			if (id == comparateur) {
				int iterateur = comparateur.size() + 2;
				while (buffer[iterateur] != '}' && buffer[iterateur] != '\0') {
					requete+= buffer[iterateur];
					iterateur++;
				}
			}
			comparateur.clear();
		}
		if (requete.size() == 0) {
			throw Erreur("Id non trouvé");
		}
		int i = 0;
		string requeteATraite;
		Plan2D* p = new Plan2D;
		while (i < requete.size()) {
			requeteATraite += requete[i];
			if (requete[i] == '\n') {
				p->ajouterForme(traiteRequete(requeteATraite));
				requeteATraite.clear();
			}
			if (requete[i] == '[') {
				int nbCrochet = 1;
				while (nbCrochet != 0) {
					requeteATraite += requete[i];
					if (requete[i] == '[')
						nbCrochet++;
					if (requete[i] == ']')
						nbCrochet--;
					i++;
				}
				requeteATraite += ']';
				p->ajouterForme(traiteRequete(requeteATraite));
				requeteATraite.clear();
			}
			i++;
		}
		return p;
	}
};

