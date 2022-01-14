#ifndef PROJET_TP1_BIBLIOTHEQUE_H
#define PROJET_TP1_BIBLIOTHEQUE_H
#include "Livre.h"
#include <ostream>
#include "Lecteur.h"
#include "Emprunt.h"
#include <vector>

class Bibliotheque {

public:
    // CONSTRUCTOR
    Bibliotheque();

    // GETTERS
    const std::vector<Lecteur> &lecteur() const;
    const std::vector<Emprunt> &emprunt() const;
    const std::vector<Livre> &livre() const;
    const std::vector<Auteur> &auteur() const;

    // METHOD ADD
    void addLecteur();
    void addAuteur();
    void addBook();
    void addBorrow();

    // METHOD DEL
    void delBorrow();

    // FUNCTION ADD
    void addisbn(const std::string& nisbn, const std::string& ID);
    void addid(const std::string& nid, const std::string& ID);

    // METHOD PRINT
    void printLB();
    void printLiB();
    void printAB();
    void printEB();

    // PUSH BACK
    void pbLe(const Lecteur& Le);
    void pbE(const Emprunt& E);
    void pbA(const Auteur& A);
    void pbLi(const Livre& Li);

    // QUESTION 8 - TP1
    void a();
    void b();
    void c();
    void d();

private:
    std::vector <Lecteur> _lecteur;
    std::vector <Emprunt> _emprunt;
    std::vector <Livre> _livre;
    std::vector <Auteur> _auteur;

};
#endif //PROJET_TP1_BIBLIOTHEQUE_H