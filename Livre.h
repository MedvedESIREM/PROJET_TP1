#ifndef C___TP1_LIVRE_H
#define C___TP1_LIVRE_H

#include "date.h"
#include "vector"
#include "Auteur.h"
#include <string>

class Livre {
public:

    // CONSTRUCTORS
    Livre(std::string titre, Auteur auteur, std::string dialecte, std::string genre,Date datepublication, std::string ISBN, std::vector<std::string> lempr, bool emprunte=false);
    Livre();

    // GETTERS
    std::string titre() const;
    Auteur auteur();
    std::string dialecte() const;
    std::string genre() const;
    Date datepublication();
    std::string ISBN() const;
    const std::vector<std::string> &lempr() const;
    bool emprunte() const;

    //SETTERS
    void setTitre(const std::string &titre);
    void setAuteur(const Auteur &auteur);
    void setDialecte(const std::string &dialecte);
    void setGenre(const std::string &genre);
    void setDatepublication(const Date &datepublication);
    void setIsbn(const std::string &isbn);
    void setEmprunte(const bool &emprunte);

    // METHOD PRINT
    void printLi();
    void printLiS();

    // FUNCTION ADD
    void addidl(const std::string& id);

private:
    std::string _titre;
    Auteur _auteur;
    std::string _dialecte;
    std::string _genre;
    Date _datepublication;
    std::string _ISBN;
    std::vector<std::string> _lempr;
    bool _emprunte;
};
#endif //C___TP1_LIVRE_H