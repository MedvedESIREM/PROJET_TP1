#include <string>
#include "date.h"
#ifndef PROJET_TP1_EMPRUNT_H
#define PROJET_TP1_EMPRUNT_H

class Emprunt {
public:
    // CONSTRUCTOR
    Emprunt(const std::string &isbn, const std::string &id, Date due_date);

    // GETTERS
    const std::string &isbn() const;
    const std::string &id() const;
    Date dueDate() const;

    // METHOD PRINT
    void printE();

private:
    std::string _isbn;
    std::string _id;
    Date _due_date;
};

#endif //PROJET_TP1_EMPRUNT_H