#ifndef C___TP1_AUTEUR_H
#define C___TP1_AUTEUR_H

#include "date.h"
#include <iostream>
#include <string>

using namespace std;

class Auteur {
public:
    // CONSTRUCTORS
    Auteur();
    Auteur(int identifiantnumerique, string nom, string prenom, Date datenaissance);

    // GETTERS
    int identifiantnumerique() const;
    string nom() const;
    string prenom() const;
    Date datenaissance();

    // SETTERS
    void setIDN(int identifiantnumerique);
    void setNom(const string &nom);
    void setPrenom(const string &prenom);
    void setDatenaissance(const Date &datenaissance);

    // METHOD PRINT
    void printAVS();
    void affichauteur();
    void printA();

private:
    int _identifiantnumerique;
    string _nom;
    string _prenom;
    Date _datenaissance;
};
#endif //C___TP1_AUTEUR_H