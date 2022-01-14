#include "Lecteur.h"
#include "Emprunt.h"
#include "Auteur.h"
#include "Bibliotheque.h"
#include <iostream>
#include <string>

int main() {
// Ajout de la Bibliotheque
    Bibliotheque Bibli;
// Variable d'enclenchement de la création rapide
    bool FC = false;
    std::cout << " " << std::endl;

// Ligne de textes sympatique
std::cout << "Initialization of the \"Library\" program ..."
             "Creating a new Library ...\n"
             "\n"
             "Welcome!\n"
             "\n" << std::endl;

// Création d'un MENU
char choice;
choice = '0';
// SI 6, ALORS FERMER LE PROGRAMME
while (choice!='6') {
    std::cout << " " << std::endl;
    std::cout << "                               Hello, What do you want to do?" << std::endl;
    std::cout << "                                                                                            _________________" << std::endl;
    std::cout << "              (GESTION : FUNCTIONS/METHODS REQUIRED ON QUESTION 8 FROM TP 1)                |   _- EXIT -_  | " << std::endl;
    std::cout << "      (TEST MODE : FAST CREATION of 3 READERS / 10 BOOKS / 5 AUTHORS / 3 BORROWING)         |               | " << std::endl;
    std::cout << "                                                                                            |      (6)      | " << std::endl;
    std::cout << "|-----------------------------------------------------------------------------------------------------------|" << std::endl;
    std::cout << "|       _- ADD -_      |      _- SHOW -_      |    _- BORROWING -_   |   _- TEST MODE -_    | _- GESTION -_ |" << std::endl;
    std::cout << "| Author, Book, Reader | Author, Book, Reader | Create, Return, Show | Create elements fast | TP_QUESTION 8 |" << std::endl;
    std::cout << "|          (1)         |          (2)         |          (3)         |          (4)         |      (5)      |" << std::endl;
    std::cout << "|-----------------------------------------------------------------------------------------------------------|" << std::endl;
    std::cout << "[TIP] MENU 'ADD (1)' prevents from duplicates (elements) ID/ISBN/NID but not 'TEST MODE (4)" << std::endl;
    std::cout << std::endl;
    std::cin >> choice;
    // Forçage de la valeur à 1, 2, 3, 4, 5, et (6)
    while ((choice != '1') && (choice != '2') && (choice != '3') && (choice != '4') && (choice != '5') && (choice != '6')) {
        std::cout << " " << std::endl;
        std::cout << "                               Try to enter a real command :)" << std::endl;
        std::cout << "                                                                                            _________________" << std::endl;
        std::cout << "              (GESTION : FUNCTIONS/METHODS REQUIRED ON QUESTION 8 FROM TP 1)                |   _- EXIT -_  | " << std::endl;
        std::cout << "      (TEST MODE : FAST CREATION of 3 READERS / 10 BOOKS / 5 AUTHORS / 3 BORROWING)         |               | " << std::endl;
        std::cout << "                                                                                            |      (6)      | " << std::endl;
        std::cout << "|-----------------------------------------------------------------------------------------------------------|" << std::endl;
        std::cout << "|       _- ADD -_      |      _- SHOW -_      |    _- BORROWING -_   |   _- TEST MODE -_    | _- GESTION -_ |" << std::endl;
        std::cout << "| Author, Book, Reader | Author, Book, Reader | Create, Return, Show | Create elements fast | TP_QUESTION 8 |" << std::endl;
        std::cout << "|          (1)         |          (2)         |          (3)         |          (4)         |      (5)      |" << std::endl;
        std::cout << "|-----------------------------------------------------------------------------------------------------------|" << std::endl;
        std::cin >> choice;
        }
    switch (choice){
    case '1' :
        // ADD__________________________________________________________________________________________________________
        // SI 4, ALORS FERMER LA FENETRE
        while (choice!='4') {
            std::cout << "             |" << std::endl;
            std::cout << "|-------------------------------|" << std::endl;
            std::cout << "|           _- ADD -_           |" << std::endl;
            std::cout << "| AUTHOR | BOOK | READER | QUIT |" << std::endl;
            std::cout << "|  -(1)  | -(2) |  -(3)  | -(4) |" << std::endl;
            std::cout << "|-------------------------------|" << " " << std::endl;
            std::cin >> choice;
            // Forçage de la valeur à 1, 2, 3 (et 4)
            while ((choice != '1') && (choice != '2') && (choice != '3') && (choice != '4')) {
                std::cout << " WRONG COMMAND" << std::endl;
                std::cout << "|-------------------------------|" << std::endl;
                std::cout << "|           _- ADD -_           |" << std::endl;
                std::cout << "| AUTHOR | BOOK | READER | QUIT |" << std::endl;
                std::cout << "|  -(1)  | -(2) |  -(3)  | -(4) |" << std::endl;
                std::cout << "|-------------------------------|" << " " << std::endl;
                std::cin >> choice;
            }
            switch (choice) {
                case '1' :
                    // Création AUTEUR(S)
                    Bibli.addAuteur();
                    break;
                case '2' :
                    // Création LIVRE(S)
                    Bibli.addBook();
                    break;
                case '3' :
                    // Création LECTEUR(S)
                    Bibli.addLecteur();
                    break;
                default:
                    std::cout << " " << std::endl;
            }
        }
    break;
    case '2' :
        // SHOW_________________________________________________________________________________________________________
        // SI 4, ALORS FERMER LA FENETRE
        while (choice!='4') {
            std::cout << "                                   |" << std::endl;
            std::cout << "|-------------------------------|  |" << std::endl;
            std::cout << "|           _- SHOW -_          |  |" << std::endl;
            std::cout << "| AUTHOR | BOOK | READER | QUIT |--|" << std::endl;
            std::cout << "|  -(1)  | -(2) |  -(3)  | -(4) |" << std::endl;
            std::cout << "|-------------------------------|" << " " << std::endl;
            std::cin >> choice;
            // Forçage de la valeur à 1, 2, 3 (et 4)
            while ((choice != '1') && (choice != '2') && (choice != '3') && (choice != '4')) {
                std::cout << " WRONG COMMAND" << std::endl;
                std::cout << "|-------------------------------|" << std::endl;
                std::cout << "|           _- SHOW -_          |" << std::endl;
                std::cout << "| AUTHOR | BOOK | READER | QUIT |" << std::endl;
                std::cout << "|  -(1)  | -(2) |  -(3)  | -(4) |" << std::endl;
                std::cout << "|-------------------------------|" << " " << std::endl;
                std::cin >> choice;
            }
            switch (choice) {
                case '1' :
                    // Affichage de TOUS LES AUTEURS
                    Bibli.printAB();
                    break;
                    case '2' :
                        // Affichage de TOUS LES LIVRES
                        Bibli.printLiB();
                        break;
                    case '3' :
                        // Affichage de TOUS LES LECTEURS
                        Bibli.printLB();
                        break;
                    default:
                        std::cout << " " << std::endl;
                }
            }
    break;
    case '3' :
        // Emprunt______________________________________________________________________________________________________
        // SI 4, ALORS FERMER LA FENETRE
        while (choice!='4') {
            std::cout << "                                                          |" << std::endl;
            std::cout << "|-------------------------------|                         |" << std::endl;
            std::cout << "|        _- BORROWING -_        |                         |" << std::endl;
            std::cout << "| CREATE | RETURN | SHOW | QUIT |-------------------------|" << std::endl;
            std::cout << "|  -(1)  |  -(2)  | -(3) | -(4) |" << std::endl;
            std::cout << "|-------------------------------|" << " " << std::endl;
            std::cin >> choice;
            // Forçage de la valeur à 1, 2, 3 (et 4)
            while ((choice != '1') && (choice != '2') && (choice != '3') && (choice != '4')) {
                std::cout << " WRONG COMMAND" << std::endl;
                std::cout << "|-------------------------------|" << std::endl;
                std::cout << "|        _- BORROWING -_        |" << std::endl;
                std::cout << "| CREATE | RETURN | SHOW | QUIT |" << std::endl;
                std::cout << "|  -(1)  |  -(2)  | -(3) | -(4) |" << std::endl;
                std::cout << "|-------------------------------|" << " " << std::endl;
                std::cin >> choice;
            }
            switch (choice) {
                case '1' :
                    // Création DE 1 EMPRUNT
                    Bibli.addBorrow();
                    break;
                    case '2' :
                        // Suppression DE 1 EMPRUNT
                        Bibli.delBorrow();
                        break;
                    case '3' :
                        // Afficher les emprunts en cours
                        Bibli.printEB();
                        break;
                    default:
                        std::cout << " " << std::endl;
                }
            }
    break;
    case '4' :
        // TEST MODE____________________________________________________________________________________________________
        // Création rapide de 3 lecteurs, 10 livres, 5 auteurs et 3 emprunts
        if (FC)
            std::cout << "TEST MODE ALREADY USED !" << std::endl;
        else {
            // Création rapide de plusieurs auteurs, livres, lecteurs et emprunts
            std::vector<std::string> liste;
            std::cout << "FAST CREATION / 3 READERS / 10 BOOKS / 5 AUTHORS / 3 BORROWINGS" << std::endl;
            // CREATION DE 2 LECTEURS
            Lecteur L1 ("BIBI42", "SACQUET", "Bilbon", liste);
            Lecteur L2 ("LEGO23", "VERTEFEUILLE", "Legolas", liste);
            Lecteur L3 ("SARU", "LE GRAND", "Saruman", liste);
            Bibli.pbLe(L1);
            Bibli.pbLe(L2);
            Bibli.pbLe(L3);
            // CREATION DE 5 AUTEURS
            Auteur JP (1, "PISTOU", "Jonathan", Date(12, 13, 2021));
            Auteur LG (2, "GARNIER", "Lionel", Date(1, 7, 1722));
            Auteur RN (3, "NADAL", "Rafael", Date(3, 6, 1986));
            Auteur KM (4, "MBAPPE", "Kylian", Date(12, 20, 1998));
            Auteur SM (5, "MIYAMOTO", "Shigeru", Date(11, 16, 1952));
            Bibli.pbA(JP);
            Bibli.pbA(LG);
            Bibli.pbA(RN);
            Bibli.pbA(KM);
            Bibli.pbA(SM);
            // CREATION DE 10 LIVRES
            Livre Li1("Le pont", LG, "Francais", "Comedie", Date(12, 13, 2021), "5435343422", liste);
            Livre Li2("La porte", LG , "Francais", "Erotique", Date(12, 12, 2021), "69696969", liste);
            Livre Li3("Comment avoir la cote?", JP, "Francais", "Guide", Date(2, 19, 2015), "1233108", liste);
            Livre Li4("Las colinas", RN , "ESPAGNOL", "Policier", Date(9, 1, 2012), "1247843", liste);
            Livre Li5("El descubrimiento", RN, "ESPAGNOL", "Comedie", Date(4, 2, 2018), "0146523", liste);
            Livre Li6("Programacion", RN , "ESPAGNOL", "Guide", Date(5, 23, 1999), "01374652", liste);
            Livre Li7("Marquer, la vie", KM, "Francais", "Philosophique", Date(2, 20, 2017), "29476234", liste);
            Livre Li8("Retour sur mon penaltie", KM , "Francais", "Philosophique", Date(9, 5, 2021), "59274652", liste);
            Livre Li9("Sekai seifuku", SM, "Japonais", "Guide", Date(1, 4, 1974), "917652", liste);
            Livre Li10("Usagi o sagasu", SM , "Japonais", "Guide", Date(3, 29, 1987), "1672544", liste);
            Bibli.pbLi(Li1);
            Li2.setEmprunte(true);
            Bibli.pbLi(Li2);
            Bibli.pbLi(Li3);
            Bibli.pbLi(Li4);
            Li5.setEmprunte(true);
            Bibli.pbLi(Li5);
            Bibli.pbLi(Li6);
            Bibli.pbLi(Li7);
            Bibli.pbLi(Li8);
            Bibli.pbLi(Li9);
            Li10.setEmprunte(true);
            Bibli.pbLi(Li10);
            // CREATION DE 3 EMPRUNTS
            Emprunt EMP1 (Li2.ISBN(), L1.id(), Date(12, 31, 2021));
            Bibli.addid(L1.id(), Li2.ISBN());
            Bibli.addisbn(Li2.ISBN(), L1.id());
            Bibli.pbE (EMP1);
            Emprunt EMP2 (Li10.ISBN(), L1.id(), Date(12, 29, 2021));
            Bibli.addid(L1.id(), Li10.ISBN());
            Bibli.addisbn(Li10.ISBN(), L1.id());
            Bibli.pbE (EMP2);
            Emprunt EMP3 (Li5.ISBN(), L2.id(), Date(12, 25, 2021));
            Bibli.addid(L2.id(), Li5.ISBN());
            Bibli.addisbn(Li5.ISBN(), L2.id());
            Bibli.pbE (EMP3);
            Bibli.printEB();
            std::cout << " " << std::endl;
            FC = true;
                    }
    break;
    case '5' :
        // GESTION______________________________________________________________________________________________________
        // SI 5, ALORS FERMER LA FENETRE
        while (choice!='4') {
            std::cout << "                                                                                                    |" << std::endl;
            std::cout << "|----------------------------------| 1) search all books by an author                               |" << std::endl;
            std::cout << "|           _- GESTION -_          | 2) show the books borrowed & calculate the % of books borrowed |" << std::endl;
            std::cout << "|  a)  |  b)  |  c)  | QUIT |  d)  |----------------------------------------------------------------|" << std::endl;
            std::cout << "| -(1) | -(2) | -(3) | -(4) | -(5) | 3) find all the books that a reader has borrowed " << std::endl;
            std::cout << "|----------------------------------| 5) rank all readers according to the number of books borrowed" << " " << std::endl;
            std::cin >> choice;
            // Forçage de la valeur à 1, 2, 3, 4 (et 5)
            while ((choice != '1') && (choice != '2') && (choice != '3') && (choice != '4') && (choice != '5')) {
                std::cout << " WRONG COMMAND" << std::endl;
                std::cout << "|----------------------------------| 1) search all books of an author" << std::endl;
                std::cout << "|           _- GESTION -_          | 2) show the books borrowed & calculate the % of books borrowed" << std::endl;
                std::cout << "|  a)  |  b)  |  c)  | QUIT |  d)  |----------------------------------------------------------------|" << std::endl;
                std::cout << "| -(1) | -(2) | -(3) | -(4) | -(5) | 3) find all the books that a reader has borrowed " << std::endl;
                std::cout << "|----------------------------------| 5) rank all readers according to the number of books borrowed" << " " << std::endl;
                std::cin >> choice;
            }
            switch (choice) {
                case '1' :
                    // QUESTION 8.a)
                    Bibli.a();
                    break;
                    case '2' :
                        // QUESTION 8.b)
                        Bibli.b();
                        break;
                    case '3' :
                       // QUESTION 8.c)
                        Bibli.c();
                        break;
                case '5' :
                    // QUESTION 8.d)
                    Bibli.d();
                    break;
                    default:
                        std::cout << " " << std::endl;
                }
            }
    default:
        std::cout << " " << std::endl;

    }
    }

return 0;
}