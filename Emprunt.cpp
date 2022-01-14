#include "Emprunt.h"
#include "iostream"

// CONSTRUCTOR CODE
Emprunt::Emprunt(const std::string &isbn, const std::string &id, Date due_date) : _isbn(isbn), _id(id), _due_date(due_date) {}

// GETTERS
    const std::string &Emprunt::isbn() const {
    return _isbn; }

    const std::string &Emprunt::id() const {
    return _id; }

    Date Emprunt::dueDate() const {
    return _due_date; }

//METHOD PRINT
void Emprunt::printE() {
    std::cout << "ISBN : " << isbn() << std::endl;
    std::cout << "ID : " << id() << std::endl;
    std::cout << "Date d'emprunt : ";
    dueDate().affichdate();
    std::cout << "" << std::endl;
}