//
// Created by fabia on 04.04.2022.
//

#ifndef PIC_LABOR_LABOR1_H
#define PIC_LABOR_LABOR1_H
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <array>
#include <cmath>
#include <fstream>

/// 8: struct Person mit angeforderten Attributen
struct Alter {
    int stunden;
    int tag;
    int jahr;
};

struct Person {
    std::string vorname;
    std::string nachname;
    std::string geburtstag;
    Alter alterInJTS;
};

double calcPow(double const in, double const power);

void localChange(int valIn);

void returnPersonen(std::vector<Person> const personen);

std::vector<Person> readPersonen(std::string const filename);

Person createPerson(std::string const vorname, std::string const nachname, std::string const geburtstag);

Alter AlterBerechnen(Alter alter);



#endif //PIC_LABOR_LABOR1_H
