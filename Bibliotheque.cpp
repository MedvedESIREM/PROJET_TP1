#include "Bibliotheque.h"
#include "Lecteur.h"
#include "Livre.h"
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

// CONSTRUCTOR
Bibliotheque::Bibliotheque() = default;

// GETTERS ___________________________________________________________
const std::vector<Lecteur> &Bibliotheque::lecteur() const {
    return _lecteur; }

const std::vector<Emprunt> &Bibliotheque::emprunt() const {
    return _emprunt; }

    const std::vector<Livre> &Bibliotheque::livre() const {
    return _livre; }

const std::vector<Auteur> &Bibliotheque::auteur() const {
    return _auteur; }

// PRINT _______________________________________________________________
// Affichage des variables DES LECTEURS
void Bibliotheque::printLB() {
    std::cout << " " << std::endl;
    if (lecteur().empty()) {
        std::cout << "EMPTY" << std::endl;
    } else {
        int compt = 0;
        for (auto i = _lecteur.begin(); i != _lecteur.end(); ++i) {
            compt ++;
            std::cout << "_________________________READER ("<< compt <<")_________________________" << std::endl;
            (*i).printL();
            std::cout << "____________________________________________________________" << std::endl;
            std::cout << " " << std::endl;
        }
    }
}

// Affichage des variables DES LIVRES
void Bibliotheque::printLiB() {
    std::cout << " " << std::endl;
    if (livre().empty()) {
        std::cout << "EMPTY" << std::endl;
    } else {
        int compt = 0;
        for (auto i = _livre.begin(); i != _livre.end(); ++i) {
            compt ++;
            std::cout << "________________________________BOOK (" << compt << ")______________________________" << std::endl;
            (*i).printLi();
            std::cout << "________________________________________________________________________" << std::endl;
            std::cout << " " << std::endl;

        }
    }
}

// Affichage des variables DES AUTEURS
void Bibliotheque::printAB() {
    std::cout << " " << std::endl;
    if (auteur().empty()) {
        std::cout << "EMPTY" << std::endl;
    } else {
        int compt = 0;
        for (auto i = _auteur.begin(); i != _auteur.end(); ++i) {
            compt ++;
            std::cout << "_______________________________AUTHOR (" << compt << ")_____________________________" << std::endl;
            (*i).printA();
            std::cout << "______________________________________________________________________" << std::endl;
            std::cout << " " << std::endl;

        }
    }
}

// Affichage des variables DES EMPRUNTS
void Bibliotheque::printEB() {
    std::cout << " " << std::endl;
    if (emprunt().empty()) {
        std::cout << "EMPTY" << std::endl;
    } else {
        int compt = 0;
        for (auto i = _emprunt.begin(); i != _emprunt.end(); ++i) {
            compt ++;
            std::cout << "_____________________________BORROWING (" << compt << ")____________________________" << std::endl;
            (*i).printE();
            std::cout << "______________________________________________________________________" << std::endl;
            std::cout << " " << std::endl;
        }
    }
}

// METHOD ADD + DELETE _________________________________________________
// METHOD ADD AUTHOR
void Bibliotheque::addAuteur() {

    // CREATION D'AUTEUR(S)
    int i = 0; // Pour compter le nombre de création
    Auteur Auteur;
    int idn;
    char choice = '0';
    int b=0;
    int b1 = 0;
    // Forçage de la valeur b pour revenir au menu (et y pour continuer)
    while (b == 0) {
        std::cout << "Continue ?" << std::endl << "Yes (y) / No (n)" << std::endl;
        std::cin >> choice;
        // Choix entre : continuer à créer et retourner au menu
        switch(choice){
            case 'y' : case 'Y':
                b1=0;
                // PROGRAMME DE CREATION DE AUTEUR
                // Boucle While avec b1 pour refaire la création de l'auteur en cas de "non-confirmation"
                while (b1 == 0) {
                    std::cout << " " << std::endl << "________Creating new Author (" << i+1 <<")____" << std::endl;
                    // GESTION NUM ID
                    std::cout << "NUMERICAL ID (WARNING, ONLY NUMBERS!!) :";
                    // GESTION DE LA DUPLICATION D'AUTEUR AVEC MEME IN
                    // on saute la vérif' si la liste des auteurs est vide
                    if (_auteur.empty()){
                        std::cin >> idn;
                    }
                    // si la liste des auteurs n'est pas vide
                    else{
                        int test_idn =0;
                        // notre variable test s'incremente de 1 jusqu'a la taille de la liste 'auteurs'
                        while (test_idn != _auteur.size()){
                            std::cin >> idn;
                        test_idn = 0;
                        // la variable test va augmenter de 1 chaque fois que idn sera different de l'IN de l'auteur
                        for (auto j = _auteur.begin(); j != _auteur.end(); ++j) {
                            if (idn == (*j).identifiantnumerique()){
                                std::cout << std::endl << "(" << idn << ") ALREADY USED ! TAKE ANOTHER :" << std::endl << std::endl;
                            }
                            else
                                test_idn++;
                        }
                        }
                    }
                    Auteur.setIDN(idn);
                    // GESTION NAME
                    std::string nom;
                    std::cout << "NAME :";
                    std::cin >> nom;
                    Auteur.setNom(nom);
                    // GESTION FNAME
                    std::string prenom;
                    std::cout << "FIRST NAME :";
                    std::cin >> prenom;
                    Auteur.setPrenom(prenom);
                    // GESTION BIRTHDAY
                    std::cout << "-BIRTHDAY (WARNING, ONLY NUMBERS!!)-" << std::endl;
                    int day;
                    std::cout << "DAY :";
                    std::cin >> day;
                    int month;
                    std::cout << "MONTH :";
                    std::cin >> month;
                    int year;
                    std::cout << "YEAR :";
                    std::cin >> year;
                    Date Date(month, day, year);
                    Auteur.setDatenaissance(Date);
                    std::cout << "___________________________________" << std::endl;
                    b1 = 1;

                    // CONFIRMATION
                    int b2 = 0;
                    // Forçage de la valeur y et n pour b2
                    while (b2 == 0) {
                        char c;
                        // AFFICHAGE DES VARIABLES DE L'AUTEUR
                        std::cout << "__________________________________AUTHOR________________________________" << std::endl;
                        Auteur.printA();
                        std::cout << "______________________________________________________________________" << std::endl;
                        std::cout << " " << std::endl;
                        std::cout << "Confirm ?" << std::endl << "Yes (y) / No (n)" << std::endl;
                        std::cin >> c;
                        switch (c) {
                            case 'y' :
                            case 'Y':
                                // INTEGRATION DE L'AUTEUR DANS LA LISTE DES AUTEURS
                                i = i+1;
                                std::cout << " " << std::endl << "New AUTHOR (" << idn << ") added !" << std::endl;
                                _auteur.push_back(Auteur);
                                b2 = 1;
                                break;
                            case 'n' :
                            case 'N' :
                                // CHANGEMENT DES VARIABLES DE L'AUTEUR | b1 = 0 -> refaire la création
                                b1 = 0;
                                b2 = 1;
                                break;
                            default:
                                std::cout << "You have to : 'Y' or 'N', please !" << std::endl;
                        }


                    }
                }
                break;
            case 'n' : case 'N':
                b=1;
                break;
            default:
                std::cout << "You have to : 'Y' or 'N', please !" << std::endl;
        }
    }



    std::cout << "Creation of the author(s) : finished" << std::endl << "Back to the menu" << std::endl << " " << std::endl;

}

// METHOD ADD BOOK
void Bibliotheque::addBook() {
    if (auteur().empty()) {
        std::cout << "ADD ONE AUTHOR BEFORE TO DO THAT!" << std::endl;
    } else {
        // CREATION DE  LIVRE(S)
        int i = 0; // Pour compter le nombre de création
        Livre Livre;
        char choice = '0';
        int b = 0;
        int b1 = 0;
        // Forçage de la valeur b pour revenir au menu (et y pour continuer)
        while (b == 0) {
            std::cout << "Continue ?" << std::endl << "Yes (y) / No (n)" << std::endl;
            std::cin >> choice;
            // Choix entre : continuer à créer et retourner au menu
            switch (choice) {
                case 'y' :
                case 'Y':
                    b1 = 0;
                    // PROGRAMME DE CREATION DE LIVRE
                    // Boucle While avec b1 pour refaire la création de LIVRE en cas de "non-confirmation"
                    while (b1 == 0) {
                        std::cout << " " << std::endl << "________Creating new BOOK (" << i + 1 << ")____" << std::endl;
                        // GESTION TITLE
                        std::string title;
                        std::cout << "TITLE";
                        std::getline (std::cin,title);
                        std::string name;
                        std::cout << " : ";
                        std::getline (std::cin,name);
                        Livre.setTitre(name);

                        // GESTION AUTHOR
                        printAB();
                        int NID = 0;
                        bool A = true;
                        while (A) {
                            std::cout << "AUTHOR (NUM ID, ONLY NUMBERS!!) :";
                            std::cin >> NID;
                            for (auto i = _auteur.begin(); i != _auteur.end(); ++i) {
                                if (NID == (*i).identifiantnumerique()) {
                                    Livre.setAuteur((*i));
                                    (*i).affichauteur();
                                    A = false;
                                    break;
                                }
                            }
                            if (A)
                                std::cout << "NO AUTHOR WAS FOUND ! CHECK YOUR NUM ID !" << std::endl << " "
                                          << std::endl;
                        }
                        // GESTION LANGUAGE
                        std::string lang;
                        std::cout << "LANGUAGE :";
                        std::cin >> lang;
                        Livre.setDialecte(lang);
                        // GESTION KIND
                        std::string genre;
                        std::cout << "KIND :";
                        std::cin >> genre;
                        Livre.setGenre(genre);
                        // GESTION PUBLICATION DATE
                        std::cout << "-PUBLICATION DATE (WARNING, ONLY NUMBERS!!)-" << std::endl;
                        int day;
                        std::cout << "DAY :";
                        std::cin >> day;
                        int month;
                        std::cout << "MONTH :";
                        std::cin >> month;
                        int year;
                        std::cout << "YEAR :";
                        std::cin >> year;
                        Date Date(month, day, year);
                        Livre.setDatepublication(Date);
                        // GESTION ISBN
                        std::string isbn;
                        std::cout << "ISBN :";
                        // GESTION DE LA DUPLICATION DE LIVRE AVEC MEME ISBN
                        // on saute la vérif' si la liste des livres est vide
                        if (_livre.empty()){
                            std::cin >> isbn;
                        }
                            // si la liste des livres n'est pas vide
                        else{
                            int test_isbn =0;
                            // notre variable test s'incremente de 1 jusqu'a la taille de la liste 'livres'
                            while (test_isbn != _livre.size()){
                                std::cin >> isbn;
                                test_isbn = 0;
                                // la variable test va augmenter de 1 chaque fois que isbn sera different de l'ISBN du livre
                                for (auto j = _livre.begin(); j != _livre.end(); ++j) {
                                    if (isbn == (*j).ISBN()){
                                        std::cout << std::endl << "(" << isbn << ") ALREADY USED ! TAKE ANOTHER :" << std::endl << std::endl;
                                    }
                                    else
                                        test_isbn++;
                                }
                            }
                        }
                        Livre.setIsbn(isbn);
                        std::cout << "___________________________________" << std::endl;
                        b1 = 1;

                        // CONFIRMATION
                        int b2 = 0;
                        // Forçage de la valeur y et n pour b2
                        while (b2 == 0) {
                            char c;
                            // AFFICHAGE DES VARIABLES DU LIVRE
                            std::cout << "___________________________________BOOK_________________________________" << std::endl;
                            Livre.printLi();
                            std::cout << "________________________________________________________________________" << std::endl;
                            std::cout << " " << std::endl;
                            std::cout << "Confirm ?" << std::endl << "Yes (y) / No (n)" << std::endl;
                            std::cin >> c;
                            switch (c) {
                                case 'y' :
                                case 'Y':
                                    // INTEGRATION DU LIVRE DANS LA LISTE DES LIVRES
                                    i = i + 1;
                                    std::cout << " " << std::endl << "New BOOK (" << isbn << ") added !" << std::endl;
                                    _livre.push_back(Livre);
                                    b2 = 1;
                                    break;
                                case 'n' :
                                case 'N' :
                                    // CHANGEMENT DES VARIABLES DU LIVRE | b1 = 0 -> refaire la création
                                    b1 = 0;
                                    b2 = 1;
                                    break;
                                default:
                                    std::cout << "You have to : 'Y' or 'N', please !" << std::endl;
                            }


                        }
                    }
                    break;
                case 'n' :
                case 'N':
                    b = 1;
                    break;
                default:
                    std::cout << "You have to : 'Y' or 'N', please !" << std::endl;
            }
        }


        std::cout << "Creation of the book(s) : finished" << std::endl << "Back to the menu" << std::endl << " "
                  << std::endl;

    }
}

// METHOD ADD READER
void Bibliotheque::addLecteur() {

    // CREATION DE  LECTEUR(S)
    int i = 0; // Pour compter le nombre de création
    Lecteur lecteur;
    std::string id;
    char choice = '0';
    int b=0;
    int b1 = 0;
    // Forçage de la valeur b pour revenir au menu (et y pour continuer)
    while (b == 0) {
        std::cout << "Continue ?" << std::endl << "Yes (y) / No (n)" << std::endl;
        std::cin >> choice;
        // Choix entre : continuer à créer et retourner au menu
        switch(choice){
            case 'y' : case 'Y':
                b1=0;
                // PROGRAMME DE CREATION DE LECTEUR
                // Boucle While avec b1 pour refaire la création de LECTEUR en cas de "non-confirmation"
                while (b1 == 0) {
                    std::cout << " " << std::endl << "________Creating new Reader (" << i+1 <<")____" << std::endl;
                    // GESTION ID
                    std::cout << "ID :";

                    // GESTION DE LA DUPLICATION DE LECTEUR AVEC MEME ID
                    // on saute la vérif' si la liste des lecteurs est vide
                    if (_lecteur.empty()){
                        std::cin >> id;
                    }
                        // si la liste des lecteurs n'est pas vide
                    else{
                        int test_id =0;
                        // notre variable test s'incremente de 1 jusqu'a la taille de la liste 'lecteur'
                        while (test_id != _lecteur.size()){
                            std::cin >> id;
                            test_id = 0;
                            // la variable test va augmenter de 1 chaque fois que id sera different de l'ID du lecteur
                            for (auto j = _lecteur.begin(); j != _lecteur.end(); ++j) {
                                if (id == (*j).id()){
                                    std::cout << std::endl << "(" << id << ") ALREADY USED ! TAKE ANOTHER :" << std::endl << std::endl;
                                }
                                else
                                    test_id++;
                            }
                        }
                    }
                    lecteur.setId(id);
                    // GESTION NAME
                    std::string name;
                    std::cout << "NAME :";
                    std::cin >> name;
                    lecteur.setName(name);
                    // GESTION FNAME
                    std::string fname;
                    std::cout << "FIRST NAME :";
                    std::cin >> fname;
                    lecteur.setFname(fname);
                    std::cout << "___________________________________" << std::endl;
                    b1 = 1;

                    // CONFIRMATION
                    int b2 = 0;
                    // Forçage de la valeur y et n pour b2
                    while (b2 == 0) {
                        char c;
                        // AFFICHAGE DES VARIABLES DU LECTEUR
                        std::cout << "____________________________READER____________________________" << std::endl;
                        lecteur.printL();
                        std::cout << "____________________________________________________________" << std::endl;
                        std::cout << " " << std::endl;
                        std::cout << "Confirm ?" << std::endl << "Yes (y) / No (n)" << std::endl;
                        std::cin >> c;
                        switch (c) {
                            case 'y' :
                            case 'Y':
                                // INTEGRATION DU LECTEUR DANS LA LISTE DES LECTEURS
                                i = i+1;
                                std::cout << " " << std::endl << "New READER (" << id << ") added !" << std::endl;
                                _lecteur.push_back(lecteur);
                                b2 = 1;
                                break;
                            case 'n' :
                            case 'N' :
                                // CHANGEMENT DES VARIABLES DU LECTEUR | b1 = 0 -> refaire la création
                                b1 = 0;
                                b2 = 1;
                                break;
                            default:
                                std::cout << "You have to : 'Y' or 'N', please !" << std::endl;
                        }


                    }
                }
                break;
            case 'n' : case 'N':
                b=1;
                break;
            default:
                std::cout << "You have to : 'Y' or 'N', please !" << std::endl;
        }
    }



    std::cout << "Creation of the reader(s) : finished" << std::endl << "Back to the menu" << std::endl << " " << std::endl;

}

// METHOD ADD BORROWING
void Bibliotheque::addBorrow() {
    // CREATION D'EMPRUNT
    bool test_livre = false; // true = il y a des livres dispo
    // TEST POUR SAVOIR S'IL Y A DES LIVRES DISPONIBLES (NON EMPRUNTE)
    for (auto j = _livre.begin(); j != _livre.end(); ++j) {
        if (!(*j).emprunte())
            test_livre = true;
    }
    // S'IL Y A DES LIVRES DISPO
    if (test_livre){
        // AFFICHAGE DE TOUS LES LECTEURS
    printLB();
    // DEMANDE D'ID POUR IDENTIFIER LE LECTEUR
    std::cout << "What is your Reader ID ?" << std::endl;
    std::string ID;
    std::cin >> ID;
    bool test = true; // false = l'ID correspond a un lecteur qui existe
    int compt_livre_dispo = 0;
// TEST POUR SAVOIR SI L'ID EXISTE
    for (auto i = _lecteur.begin(); i != _lecteur.end(); ++i) {
        // SI L'ID EXISTE
        if (ID == (*i).id()) {
            test = false;
            std::cout << "Welcome " << (*i).fname() << " " << (*i).name() << " !" << std::endl;
            // AFFICHAGE DE TOUS LES LIVRES DISPO
            for (auto j = _livre.begin(); j != _livre.end(); ++j) {
                if ((*j).emprunte()) {}
                    else {
                    (*j).printLiS();
                    compt_livre_dispo++;
                    }
            }
            std::cout << "There are "<< compt_livre_dispo << "/" << _livre.size() << " available books." << std::endl;
            std::cout << "Which book do you want to borrow ?" << std::endl;
            std::cout << "(Enter a title or the ISBN)" << std::endl;
            // DEMANDE DE RENTRER UN TITRE OU ISBN POUR TROUVER LE LIVRE (BOUCLE SI ELM N'EST PAS VALIDE)
            std::string ELM;
            bool A = true; // false = l'emprunt est terminé
            while (A) {
                // GETLINE POUR PRENDRE DES STRING AVEC DES ESPACES
                std::getline (std::cin,ELM);
                // TEST POUR SAVOIR SI LE LIVRE EXISTE ET S'IL EST DISPO
                for (auto j = _livre.begin(); j != _livre.end(); ++j) {
                    if ( ELM == (*j).titre() || ELM == (*j).ISBN()){
                        // SI LE LIVRE N'EST PAS DISPO
                        if ((*j).emprunte())
                            std::cout << "This book is already borrowed, choose another books (not borrowed)!" << std::endl;
                        else{
                            // DEBUT DE LA CREATION D'UN EMPRUNT SI LE LIVRE EXISTE ET EST DISPO
                            (*j).setEmprunte(true);
                            addisbn((*j).ISBN(), (*i).id());
                            addid((*i).id(), ELM);
                            std::cout << "-DATE (WARNING, ONLY NUMBERS!!)-" << std::endl;
                            int day;
                            std::cout << "DAY :";
                            std::cin >> day;
                            int month;
                            std::cout << "MONTH :";
                            std::cin >> month;
                            int year;
                            std::cout << "YEAR :";
                            std::cin >> year;
                            Date Date(month, day, year);
                            // Création d'un nouvel emprunt
                            Emprunt EMP1 ((*j).ISBN(), (*i).id(), Date);
                            std::cout << "________________________________BORROWING_______________________________" << std::endl;
                            EMP1.printE();
                            std::cout << "______________________________________________________________________" << std::endl;
                            std::cout << " " << std::endl;
                            pbE(EMP1);
                            std::cout << " " << std::endl << "BORROWING FINISHED, ENJOY YOUR BOOK (" << (*j).titre() << ") !" << std::endl;
                            A = false;
                        }
                    }
                }
            }

        }
    }
    // SI L'ID N'EXISTE PAS
    if (test)
    std::cout << "There is no reader with this ID -> Back to the MENU" << std::endl;
    }
    // S'IL N'Y A PAS DE LIVRES DISPO
    else
        std::cout << "There is no book available, come later!" << std::endl;
}

// METHOD DELETE BORROWING
void Bibliotheque::delBorrow() {
    // SUPPRESSION D'EMPRUNT
    bool test = true; //true = il existe un lecteur avec l'id rentre
    bool test_livre = false; // true = le lecteur a des livres
    //TEST POUR SAVOIR S'IL Y A DES EMPRUNTS DEJA CREES
    if (emprunt().empty())
        std::cout << "There is no Borrowing here, so you can not to that !" << std::endl;
    // S'IL Y A DES EMPRUNTS DEJA CREES
    else {
        // AFFICHAGE DE TOUS LES LECTEURS
        printLB();
        std::cout << "What is your Reader ID ?" << std::endl;
        // DEMANDE D'ID POUR IDENTIFICATION DE LECTEUR
        std::string ID;
        std::cin >> ID;
        // AFFICHAGE DES INFOS DU LECTEUR
        for (auto i = _lecteur.begin(); i != _lecteur.end(); ++i) {
            // SI LE LECTEUR EXISTE
            if (ID == (*i).id()) {
                test = false;
                std::cout << "Welcome " << (*i).fname() << " " << (*i).name() << " !" << std::endl;
                // AFFICHAGE DE TOUS LES LIVRES DU LECTEUR
                for (auto k = (*i).isbn().begin(); k!= (*i).isbn().end(); ++k){
                    for (auto j = _livre.begin(); j != _livre.end(); ++j) {
                        if ((*k) == (*j).ISBN())
                            (*j).printLiS();
                        test_livre = true;
                    }
                }
                // SI LE LECTEUR A DES LIVRES EMPRUNTES
                if (test_livre){
                    std::cout << " " << std::endl;
                    std::cout << "Which book do you want to return ?" << std::endl;
                    std::cout << "(Enter the ISBN, and ONLY the ISBN)" << std::endl;
                    std::string ISBN;
                    // DEMANDE ISBN POUR TROUVER LE LIVRE A RENDRE
                    std::cin >> ISBN;
                    bool test_avlb = false; // true = le livre ne peut pas être remis
                    bool test_isbn = false; // true = le livre existe
                    // RECHERCHE ET AFFICHAGE DU LIVRE AVEC L'ISBN RENTRE
                    for (auto j = _livre.begin(); j != _livre.end(); ++j) {
                        if (ISBN == (*j).ISBN()){
                            std::cout << "___________________________________BOOK_________________________________" << std::endl;
                            (*j).printLi();
                            std::cout << "________________________________________________________________________" << std::endl;
                            std::cout << " " << std::endl;
                            test_isbn = true;
                        }
                    }
                    // TEST POUR SAVOIR SI LA REMISE DU LIVRE EST DISPONIBLE
                    for (auto k = _emprunt.begin(); k != _emprunt.end(); ++k) {
                        // SI LA REMISE EST POSSIBLE
                    if ((*k).isbn() == ISBN && (*k).id() == (*i).id()){
                        std::cout << "RETURN AVAILABLE" << std::endl;
                        // ON EFFACE L'EMPRUNT DE LA LISTE D'EMPRUNTS
                       _emprunt.erase(k);
                       // ON ENLEVE L'ISBN DE LA LISTE DU LECTEUR
                        (*i).deleteisbn(ISBN);
                        // ON REMET LE LIVRE EN DISPONIBLE
                        for (auto j = _livre.begin(); j != _livre.end(); ++j) {
                            if (ISBN == (*j).ISBN())
                                (*j).setEmprunte(false);
                        }
                        std::cout << "The book ("<< ISBN <<") is now returned to the library !" << std::endl;
                        test_avlb = true;
                        --k;
                    }
                    }
                    // SI LE LECTEUR ESSAYE DE RENDRE UN LIVRE QUI N'EST PAS A LUI
                    if (!test_avlb)
                        std::cout << "RETURN NOT AVAILABLE, THAT IS NOT YOUR BOOK !" << std::endl;
                    // SI LE LIVRE N'EXISTE PAS
                    if (!test_isbn)
                        std::cout << "Wait, this book does not exist, back to the menu !" << std::endl;
                }
                // SI LE LECTEUR N'A PAS DE LIVRE EMPRUNTE
                else
                    std::cout << "You do not have any book(s) to return !" << std::endl;
            }
        }
    }
    // SI L'ID NE CORRESPOND A AUCUN LECTEUR
    if (test && !emprunt().empty())
        std::cout << "There is no reader with this ID -> Back to the MENU" << std::endl;
}

// PUSH BACK ____________________________________________________________
//PUSH BACK LECTEUR
void Bibliotheque::pbLe(const Lecteur& Le){
    _lecteur.push_back(Le); }

//PUSH BACK EMPRUNT
void Bibliotheque::pbE(const Emprunt& E){
    _emprunt.push_back(E); }

//PUSH BACK AUTEUR
void Bibliotheque::pbA(const Auteur& A){
    _auteur.push_back(A); }

//PUSH BACK LIVRE
void Bibliotheque::pbLi(const Livre& Li){
    _livre.push_back(Li); }

// FUNCTION ADD ________________________________________________________
// FUNCTION ADD ISBN
void Bibliotheque::addisbn(const std::string& nisbn, const std::string& ID) {
    bool A = true;
    // TEST POUR SAVOIR SI LE LECTEUR EXISTE
    for (auto i = _lecteur.begin(); i != _lecteur.end(); ++i) {
       // SI LE LECTEUR EXISTE
        if (ID == (*i).id()) {
            // PUSH BACK DE L'ISBN DANS LE LECTEUR ID
            (*i).addisbnl(nisbn);
            A = false;
            break; }
    }
    // SI LE LECTEUR N'EXISTE PAS
    if (A)
        std::cout << "There is no reader " << ID << " ! Try again :)" << std::endl;
    }

// FUNCTION ADD ID
void Bibliotheque::addid(const std::string& nid, const std::string& ELM) {
    bool A = true;
    // TEST POUR SAVOIR SI LE LIVRE EXISTE
    for (auto i = _livre.begin(); i != _livre.end(); ++i) {
        // SI LE LIVRE EXISTE
        if (ELM == (*i).titre() || ELM == (*i).ISBN()) {
            // PUSH BACK DE L'ID DANS LE LIVRE ELM
            (*i).addidl(nid);
            A = false;
            break; }
    }
    // SI LE LIVRE N'EXISTE PAS
    if (A)
        std::cout << "There is no book " << ELM << " ! Try again :)" << std::endl;
}


// QUESTION 8 - TP1 ____________________________________________________
// a) search all books of an author
void Bibliotheque::a() {
std::cout << " " << std::endl;
// TEST POUR SAVOIR S'IL Y A DES AUTEURS DANS LA BIBLIOTHEQUE
if (!_auteur.empty()){
    // AFFICHAGE DES AUTEURS
    std::cout << "--------------------------AUTHORS------------------------------" << std::endl;
    for (auto j = _auteur.begin(); j != _auteur.end(); ++j)
        (*j).affichauteur();
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << " " << std::endl;
std::cout << "Hello, I am going to search all books of an author for you !" << std::endl;
std::cout << "I have print every author, enter the IN of an author (WARNING, ONLY NUMBERS)" << std::endl;
int IN=0;
std::string fname_auth;
std::string name_auth;
bool test_IN = false;
std::cin >> IN;
// AFFICHAGE DE L'AUTEUR CHOISI
    for (auto j = _auteur.begin(); j != _auteur.end(); ++j) {
        if ((*j).identifiantnumerique() == IN){
            name_auth = (*j).nom();
            fname_auth = (*j).prenom();
            std::cout << "__________________________________AUTHOR________________________________" << std::endl;
            (*j).printA();
            std::cout << "______________________________________________________________________" << std::endl;
            std::cout << " " << std::endl;
        }
    }
    // AFFICHAGE DES LIVRES DE L'AUTEUR CHOISI
            for (auto i = _livre.begin(); i != _livre.end(); ++i) {
                if(IN == (*i).auteur().identifiantnumerique()) {
                    std::cout << "___________________________________BOOK_________________________________" << std::endl;
                    (*i).printLi();
                    std::cout << "________________________________________________________________________" << std::endl;
                    std::cout << " " << std::endl;
                    test_IN = true;
                }
            }
            if (test_IN)
                std::cout << "Here the list of all books from " << fname_auth << " " << name_auth << " !" << std::endl;
// SI LE NID NE FAIT REFERENCE A AUCUN AUTEUR
            else
                std::cout << "There is no author with this NID (" << IN << ") !" << std::endl;
    // TEXT DE FIN SYMPATHIQUE
    std::cout << "Enter a character (or enter THANKS) to back to the menu." << std::endl;
    std::string enter;
    std::cin >> enter;
    if (enter == "THANKS" || enter == "thanks" || enter == "THX" || enter == "thx")
        std::cout << "You are welcome :)" << std::endl << " " << std::endl;
    else
        std::cout << "Ok i will remember that..."  << std::endl << " " << std::endl;
}
// S'IL N'Y A PAS D'AUTEURS DANS LA BIBLIOTHEQUE
else {
    std::cout << " " << std::endl;
    std::cout << "There are no authors in this library, it's disappointing..." << std::endl;
    std::cout << " " << std::endl;
}
}
// b) show the books borrowed & calculate the % of books borrowed
void Bibliotheque::b() {
    std::cout << " " << std::endl;
    int it_bor = 0;
    // AFFICHAGE DE TOUS LES LIVRES EMPRUNTES
    for (auto j = _livre.begin(); j != _livre.end(); ++j) {
        if ((*j).emprunte()) {
            std::cout << "___________________________________BOOK_________________________________" << std::endl;
            (*j).printLi();
            std::cout << "________________________________________________________________________" << std::endl;
            std::cout << " " << std::endl;
            it_bor ++;
        }
    }
    // TEST POUR SAVOIR S'IL Y A DES LIVRES EMPRUNTES
    if (!_emprunt.empty()){
    std::cout << "Hello, I have print all borrowed books for you !" << std::endl;
    // CALCUL DU POURCENTAGE
    double perc = 0.0;
    double it_bor_d = it_bor;
    double size = _livre.size();
    perc = (it_bor_d/size)*100;
    int iperc;
    iperc = perc;
    // AFFICHAGE DU RESULTAT
    std::cout << it_bor << "/" << _livre.size() << " are borrowed. PERCENTAGE : " << iperc << " %" << std::endl;
    }
    // S'IL N'Y A PAS DE LIVRES EMPRUNTES
    else {
        std::cout << "Hello, I am sorry but.. there are no borrowed books.. how sad !" << std::endl;
        std::cout << "Percentage of book borrowed : 0 %, did you know that?" << std::endl;
    }
    // TEXT DE FIN SYMPATHIQUE
    std::cout << " " << std::endl;
    std::cout << "Enter a character (or enter THANKS) to back to the menu." << std::endl;
    std::string enter;
    std::cin >> enter;
    if (enter == "THANKS" || enter == "thanks" || enter == "THX" || enter == "thx")
        std::cout << "You are welcome :)" << std::endl << " " << std::endl;
    else
        std::cout << "Ok i will remember that..."  << std::endl << " " << std::endl;
}
// c) find all the books that a reader has borrowed
void Bibliotheque::c() {
    std::cout << " " << std::endl;
    // TEST POUR SAVOIR SI IL Y A DES LECTEURS DANS LA BIBLIOTHEQUE
    if (!_lecteur.empty()){
        // AFFICHAGE DES LECTEURS
    std::cout << "--------------------------READERS------------------------------" << std::endl;
    for (auto j = _lecteur.begin(); j != _lecteur.end(); ++j){
        (*j).printLS();
        std::cout << "_____________________________________________________________" << std::endl;
    }
    bool test_lect = false;
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Hello, I am going to search all borrowed books by a reader !" << std::endl;
    std::cout << "I have print every readers, enter the ID of a reader :" << std::endl;
    std::string ID;
    std::cin >> ID;
    // AFFICHAGE DU LECTEUR SELECTIONNE
    for (auto j = _lecteur.begin(); j != _lecteur.end(); ++j) {
        if (ID == (*j).id()){
            std::cout << "____________________________READER__________________________" << std::endl;
            (*j).printL();
            std::cout << "____________________________________________________________" << std::endl;
            std::cout << " " << std::endl;
            // TEST POUR SAVOIR SI LA LISTE DES LIVRES EMPRUNTES EST VIDE
            if (!(*j).isbn().empty()){
                // AFFICHAGE DES LIVRES QUI ONT LE MEME ISBN QUE CELUI DANS LA LISTE DU LECTEUR
            for (auto i = (*j).isbn().begin(); i != (*j).isbn().end(); i++) {
                for (auto k = _livre.begin(); k != _livre.end(); k++)
                    if ((*i) == (*k).ISBN())
                        (*k).printLiS();
            }
            std::cout << " " << std::endl;
            std::cout << "This is the list of all the books that " << (*j).id() << " has currently borrowed." << std::endl;
        }
            // SI LA LISTE DES LIVRES EMPRUNTES EST VIDE
            else {
                std::cout << "Currently, this reader (" << (*j).id() << ") does not have any borrowed books !" << std::endl;
                std::cout << "Try to borrow some books with " << (*j).id() << " !" << std::endl;
            }
            test_lect = true;
        }
    }
    // SI L'ID NE CORRESPOND A AUCUN LECTEUR
    if (!test_lect)
        std::cout << "The reader '" << ID << "' does not exist ! More concentration please..." << std::endl;
    // TEXT DE FIN SYMPATHIQUE
    std::cout << " " << std::endl;
    std::cout << "Enter a character (or enter THANKS) to back to the menu." << std::endl;
    std::string enter;
    std::cin >> enter;
    if (enter == "THANKS" || enter == "thanks" || enter == "THX" || enter == "thx")
        std::cout << "You are welcome :)" << std::endl << " " << std::endl;
    else
        std::cout << "Ok i will remember that..."  << std::endl << " " << std::endl;
    }
    // S'IL N'Y A PAS DE LECTEURS DANS LA BIBLIOTHEQUE
    else{
        std::cout << " " << std::endl;
        std::cout << "There are no Readers in this Library, I am alone... scary!" << std::endl;
        std::cout << " " << std::endl;
    }

}
// d) rank all readers according to the number of books borrowed
void Bibliotheque::d() {
    std::cout << " " << std::endl;
    std::cout << "Hello, I am going to rank every readers according to the number of books borrowed !" << std::endl;
    std::cout << " " << std::endl;
    // VECTEUR QUI CONTIENT TOUTES LES TAILLES DES LISTE "ISBN" DES LECTEURS
    std::vector<int> nb;
    int cmp = 0; // pour compter les places dans le classement
    // TOUTES LES TAILLES DES LISTES SONT RENTREES DANS LE VECTEUR
    for (auto j = _lecteur.begin(); j != _lecteur.end(); ++j){
                    nb.push_back((*j).isbn().size());
        }
    // ON TRIE LES TAILLES DANS LE VECTEUR
    std::sort(nb.begin(), nb.end());
    // ON AFFICHE LES LECTEURS AVEC LES LISTES DU PLUS GRAND AU PLUS PETIT
    for (auto j = nb.end()-1; j != nb.begin()-1; --j){
        // pour ne pas avoir de doublon
        if ((*j) != (*(j+1))) {
        cmp ++;
        std::cout << "___________RANK (" << cmp << ")_______(" << (*j) << " Borrowed Books)____________________" << std::endl;
        for (auto i = _lecteur.begin(); i != _lecteur.end(); ++i)  {
            if ((*i).isbn().size() == (*j)){
                (*i).printLS();
            }
        }
        std::cout << "________________________________________________________________" << std::endl;
        }
    }
    // TEST POUR SAVOIR S'IL Y A DES LECTEURS
    if (_lecteur.size() == 0)
        std::cout << "Oh wait, there are no readers..." << std::endl;
    else {
    // TEXT DE FIN SYMPATHIQUE
    std::cout << " " << std::endl;
    std::cout << "Enter a character (or enter THANKS) to back to the menu." << std::endl;
    std::string enter;
    std::cin >> enter;
    if (enter == "THANKS" || enter == "thanks" || enter == "THX" || enter == "thx")
        std::cout << "You are welcome :)" << std::endl << " " << std::endl;
    else
        std::cout << "Ok i will remember that..."  << std::endl << " " << std::endl;
    }
}