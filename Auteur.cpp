#include "Auteur.h"
#include <string>
#include <iostream>
using namespace std;

// CONSTRUCTEUR CODES
Auteur::Auteur() {}
Auteur::Auteur(int identifiantnumerique, string nom, string prenom, Date datenaissance) : _identifiantnumerique(identifiantnumerique), _nom(nom), _prenom(prenom), _datenaissance(datenaissance) {}

// GETTERS
    int Auteur::identifiantnumerique() const {
    return _identifiantnumerique; }

    string Auteur::nom()  const {
    return _nom; }

    string Auteur::prenom()  const {
    return _prenom; }

    Date Auteur::datenaissance() {
    return _datenaissance; }

// SETTERS
    void Auteur::setIDN(int identifiantnumerique) {
    _identifiantnumerique = identifiantnumerique; }

    void Auteur::setNom(const string &nom) {
    _nom = nom; }

    void Auteur::setPrenom(const string &prenom) {
    _prenom = prenom; }

    void Auteur::setDatenaissance(const Date &datenaissance) {
    _datenaissance = datenaissance; }

//METHOD PRINT VEEEERY SIMPLE
void Auteur::printAVS() {
    cout << _nom << " (NAME) | " << _prenom << " (FNAME)" << std::endl;
}

//METHOD PRINT SIMPLE
void Auteur::affichauteur() {
    cout << _identifiantnumerique << " (NID) | " << _nom << " (NAME) | " << _prenom << " (FNAME) | " ;
    datenaissance().affichdate();
    cout << " " << endl;
}

// METHOD PRINT ADVANCED
void Auteur::printA() {
std::cout << "NUM ID : " << identifiantnumerique() << std::endl;
std::cout << "NAME : " << nom() << std::endl;;
std::cout << "FIST NAME : " << prenom() << std::endl;
std::cout << "BIRTHDAY  : ";
datenaissance().affichdate();
std::cout << std::endl;
}