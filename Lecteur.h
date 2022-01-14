#include <string>
#include <vector>
#ifndef PROJET_TP1_LECTEUR_H
#define PROJET_TP1_LECTEUR_H

class Lecteur {

public:
    // CONSTRUCTORS
    Lecteur();
    Lecteur(const std::string &id, const std::string &name, const std::string &fname,
            const std::vector<std::string> &isbn);

    // GETTERS
    const std::string &id() const;
    const std::string &name() const;
    const std::string &fname() const;
    const std::vector<std::string> &isbn() const;

    // SETTERS
    void setId(const std::string &id);
    void setName(const std::string &name);
    void setFname(const std::string &fname);

    // FUNCTION ADD
    void addisbnl(const std::string& id);

    // FUNCTION DELETE
    void deleteisbn(const std::string& nisbn);

    // METHOD PRINT
    void printL() const;
    void printLS() const;

private:
    std::string _id;
    std::string _name;
    std::string _fname;
    std::vector <std::string> _isbn;

};
#endif //PROJET_TP1_LECTEUR_H