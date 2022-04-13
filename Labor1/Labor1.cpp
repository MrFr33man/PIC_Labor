//
// Created by fabia on 04.04.2022.
//
#include "Labor1.h"

double calcPow(double const in, double const power){
    return pow(in, power);
}

void localChange(int valIn) {
    valIn += valIn;
    std::cout << "Variable nach Operation in Funktion: " << valIn << std::endl;
}

void returnPersonen(std::vector<Person> const personen){
    for (auto p : personen){
        std::cout << "Vorname: " << p.vorname << std::endl;
        std::cout << "Nachname: "  << p.nachname << std::endl;
        std::cout << "Geburtstag: "  << p.geburtstag << std::endl;
        std::cout << "---" << std::endl;
    }
}

std::vector<Person> readPersonen(std::string const filename){
    std::vector<Person> pv;
    std::ifstream infile(filename);
    Person p;

    if (!infile){
        std::cout << "Fehler beim lesen der Datei" << std::endl;
        exit(1);
    }

    while(!infile.eof()){
        infile >> p.vorname;
        infile >> p.nachname;
        infile >> p.geburtstag;

        pv.push_back(p);
    }
    return pv;
}

Person createPerson(std::string const vorname, std::string const nachname, std::string const geburtstag) {
    return Person{vorname, nachname, geburtstag};
}

Alter AlterBerechnen(std::chrono::year_month_day geburtstag){
    Alter a;
    return a;
}
