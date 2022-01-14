#include "date.h"
#include "iostream"

// CODE CONSTRUCTOR
Date::Date(int month, int day, int year) : _month(month), _day(day), _year(year) {
}

// GETTER
int Date::month()  const {
    return _month; }

int Date::day() const {
    return _day; }

int Date::year() const {
    return _year; }

//METHOD PRINT
void Date::affichdate() {
    std::cout << day() << " / " << month() << " / " << year(); }