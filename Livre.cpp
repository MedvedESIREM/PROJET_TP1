#include "Livre.h"
#include <string>
#include <iostream>
using namespace std;

// CONSTRUCTEUR CODES
Livre::Livre() {}
Livre::Livre(string titre, Auteur auteur, string dialecte, string genre,Date datepublication, string ISBN, vector<string> lempr, bool emprunte) : _titre(titre), _auteur(auteur), _dialecte(dialecte), _genre(genre), _datepublication(datepublication),  _ISBN(ISBN), _lempr(lempr), _emprunte(emprunte) {}

// GETTERS
    string Livre::titre()  const {
    return _titre; }

    Auteur Livre::auteur() {
    return _auteur; }

    string Livre::dialecte()  const {
    return _dialecte; }

    string Livre::genre()  const {
    return _genre; }

    string Livre::ISBN()  const {
    return _ISBN; }

    Date Livre::datepublication() {
    return _datepublication; }

    const std::vector<std::string> &Livre::lempr() const {
    return _lempr; }

    bool Livre::emprunte()  const {
    return _emprunte; }

// SETTERS
    void Livre::setTitre(const string &titre) {
    _titre = titre; }

    void Livre::setAuteur(const Auteur &auteur) {
    _auteur = auteur; }

    void Livre::setDialecte(const string &dialecte) {
    _dialecte = dialecte; }

    void Livre::setGenre(const string &genre) {
    _genre = genre; }

    void Livre::setDatepublication(const Date &datepublication) {
    _datepublication = datepublication; }

    void Livre::setIsbn(const string &isbn) {
    _ISBN = isbn; }

    void Livre::setEmprunte(const bool &emprunte) {
    _emprunte = emprunte; }

// METHOD PRINT
    void Livre::printLi() {
std::cout << "TITLE : " << titre() << std::endl;
std::cout << "AUTHOR : ";
auteur().affichauteur();
std::cout << "LANGUAGE : " << dialecte() << std::endl;
std::cout << "KIND : " << genre() << std::endl;
std::cout << "PUBLICATION DATE : ";
datepublication().affichdate();
std::cout << std::endl << "ISBN : " << ISBN() << std::endl;
std::cout << "LIST OF FORMER BORROWERS : ";
if (lempr().empty()) {
std::cout << "EMPTY";
} else {
for (auto j = lempr().begin(); j != lempr().end(); ++j)
std::cout << *j << " ";
}
std::cout << std::endl;
if (emprunte())
std:: cout << "BORROWED : YES " << std::endl;
else
    std:: cout << "BORROWED : NO " << std::endl;
    }

// METHOD PRINT SIMPLE (Infos en ligne des livres non empruntés)
    void Livre::printLiS() {
    std::cout << " " << std::endl;
    std::cout << "________________________________________BOOKS____________________________________" << std::endl;
    std::cout << "TITLE : " << titre() << "  /  AUTHOR : " ;
    auteur().printAVS();
    std::cout << "LANGUAGE : " << dialecte() << "  /  KIND : " << genre() << "  /  PUBLICATION DATE : ";
    datepublication().affichdate();
    std::cout << std::endl << "ISBN : " << ISBN() << std::endl;
    std::cout << "_________________________________________________________________________________" << std::endl;
}

// FUNCTION ADD
    void Livre::addidl(const string& id) {
    cout << "Nouvel ID (" << id <<") dans la liste de : " << titre() << " !" << endl;
    _lempr.push_back(id); }