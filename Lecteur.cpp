#include <iostream>
#include <vector>
#include "Lecteur.h"
#include <string>

// CONSTRUCTEUR CODES
Lecteur::Lecteur() {}
Lecteur::Lecteur(const std::string &id, const std::string &name, const std::string &fname,
                 const std::vector<std::string> &isbn) : _id(id), _name(name), _fname(fname), _isbn(isbn) {}

// GETTERS
    const std::string &Lecteur::id() const {
    return _id; }

    const std::string &Lecteur::name() const {
    return _name; }

    const std::string &Lecteur::fname() const {
    return _fname; }

    const std::vector<std::string> &Lecteur::isbn() const {
    return _isbn; }

// SETTERS
    void Lecteur::setId(const std::string &id) {
    _id = id; }

    void Lecteur::setName(const std::string &name) {
    _name = name; }

    void Lecteur::setFname(const std::string &fname) {
    _fname = fname; }

// FUNCTION ADD
void Lecteur::addisbnl(const std::string& nisbn) {
    std::cout << "New ISBN (" << nisbn <<") in the list of " << id() << " !" << std::endl;
    _isbn.push_back(nisbn); }

// FUNCTION DELETE
void Lecteur::deleteisbn(const std::string& nisbn) {
    for (auto i = _isbn.begin(); i != _isbn.end(); ++i) {
        if (*i == nisbn) {
            _isbn.erase(i);
            std::cout << "Deleting ISBN (" << nisbn << ") in the list of " << id() << " !" << std::endl;
            i--;
        }
    }
}

// METHOD PRINT
void Lecteur::printL() const {
    std::cout << "ID : " << id() << std::endl;
    std::cout << "NAME : " << name() << std::endl;
    std::cout << "FIRST NAME : " << fname() << std::endl;
    std::cout << "ISBN LIST : ";
    if (isbn().empty()){
        std::cout << "EMPTY";
    }
    else{
    for (auto i = isbn().begin(); i != isbn().end(); ++i)
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

// METHOD PRINT SIMPLE
void Lecteur::printLS() const {
    std::cout << "- ID : " << id() << " / NAME : " << name() << " / FIRST NAME : " << fname() << std::endl;
    std::cout << "  ISBN LIST : ";
    if (isbn().empty()){
        std::cout << "EMPTY";
    }
    else{
        for (auto i = isbn().begin(); i != isbn().end(); ++i)
            std::cout << *i << " ";
    }
    std::cout << std::endl;
}