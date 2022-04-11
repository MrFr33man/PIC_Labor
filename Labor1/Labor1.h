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

/// 8: struct Person mit angeforderten Attributen
struct Alter {
    int stunden;
    int tag;
    int jahr;
};

struct Person {
    std::string vorname;
    std::string nachname;
    std::chrono::year_month_day geburtstag;
    Alter alterInJTS;
};

double calcPow(double in, double power);

int localChange(int valIn);

Alter AlterBerechnen(Alter alter);



#endif //PIC_LABOR_LABOR1_H
