#ifndef DATE_H
#define DATE_H

class Date {
public:
    // CONSTRUCTOR
    Date(int month=1, int day=1, int year=1);

    // GETTER
    int year() const;
    int month() const;
    int day() const;

    // METHOD POUR AFFICHER LA DATE
    void affichdate();

private:
    int _year;
    int _month;
    int _day;
};
#endif // DATE_H