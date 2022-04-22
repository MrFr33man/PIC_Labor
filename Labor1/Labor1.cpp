//
// Created by fabia on 04.04.2022.
//
#include "Labor1.h"

void returnArgs(std::vector<std::string> const &proArgs){
    for (std::string arg : proArgs){
        std::cout << "Programmargument: " << arg << std::endl;
    }
}

double calcPow(double const &in, double const &power){
    return pow(in, power);
}

void localChange(int valIn) {
    valIn += valIn;
    std::cout << "Variable nach Operation in Funktion: " << valIn << std::endl;
}

void returnPersonen(std::vector<Person> const &personen){
    for (auto p : personen){
        std::cout << "Vorname: " << p.vorname << std::endl;
        std::cout << "Nachname: "  << p.nachname << std::endl;
        std::cout << "Geburtstag: "  << p.geburtstag << std::endl;
        std::cout << "---" << std::endl;
    }
}

void returnPerson(Person const p){
    std::cout << "Vorname: " << p.vorname << std::endl;
    std::cout << "Nachname: "  << p.nachname << std::endl;
    std::cout << "Geburtstag: "  << p.geburtstag << std::endl;
    std::cout << "Alter in Jahren: " << p.alterInJTS.jahr << std::endl;
    std::cout << "Alter in Tagen: " << p.alterInJTS.tag << std::endl;
    std::cout << "Alter in Stunden (0 Uhr): " << p.alterInJTS.stunden << std::endl;
}


std::vector<Person> readPersonen(std::string const &filename){
    std::vector<Person> pv;
    std::ifstream infile(filename);
    Person p;

    try{

        infile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        if (!infile){
            std::cout << "Fehler beim lesen der Datei" << std::endl;
            exit(1);
        }

        while(!infile.eof()){
            //infile.exceptions(std::ifstream::eofbit);
            infile >> p.vorname;
            infile >> p.nachname;
            infile >> p.geburtstag;

            pv.push_back(p);
        }
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    return pv;
}

Person createPerson(std::string const &vorname, std::string const &nachname, std::string const &geburtstag) {
    return Person{vorname, nachname, geburtstag};
}

std::string return_current_time_and_date(){
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d");
    return ss.str();
}

Alter calcAge(std::string const &gebdat){
    Alter a;
    std::string test {return_current_time_and_date()};
    std::cout << "Heute: " << test << std::endl;

    std::string jahr = test.substr(0,4);

    std::string monat = test.substr(5,2);

    std::string tag = test.substr(8,2);


    time_t t;
    struct  tm d1{0}, d2{0};
    d1.tm_year = stoi(jahr) - 1900;
    d1.tm_mon = stoi(monat)-1;
    d1.tm_mday = stoi(tag);

    d2.tm_year = stoi(gebdat.substr(6,4))-1900;
    d2.tm_mon = stoi(gebdat.substr(3,2))-1;
    d2.tm_mday = stoi(gebdat.substr(0,2));

    t = difftime(mktime(&d1), mktime(&d2));

    a.jahr = t / 60 / 60 / 24 / 365;
    a.tag = t / 60 / 60 / 24;
    a.stunden = t / 60 / 60;

    return a;
}

std::string numToStr(const int &val){

    std::array<std::string, 20> special {};
    std::array<std::string, 9> tens {};

    special[0] = "null";
    special[1] = "ein";
    special[2] = "zwei";
    special[3] = "drei";
    special[4] = "vier";
    special[5] = "fuenf";
    special[6] = "sechs";
    special[7] = "sieben";
    special[8] = "acht";
    special[9] = "neun";
    special[10] = "zehn";
    special[11] = "elf";
    special[12] = "zwoelf";
    special[13] = "dreizehn";
    special[14] = "vierzehn";
    special[15] = "fuenfzehn";
    special[16] = "sechszehn";
    special[17] = "siebzehn";
    special[18] = "achtzehn";
    special[19] = "neunzehn";

    tens[0] = "zwanzig";
    tens[1] = "dreisssig";
    tens[2] = "vierzig";
    tens[3] = "fuenfzig";
    tens[4] = "sechszig";
    tens[5] = "siebzig";
    tens[6] = "achtzig";
    tens[7] = "neunzig";
    tens[8] = "hundert";


    if (val > 122) return "zu alt";
    if(val < 20){
        return special[val];
    }
    if (val < 100) {
        if (val % 10 == 0) return tens[val / 10 - 2];
        if (val % 10 == 1) return "einund" + numToStr(val / 10 * 10);
        return numToStr(val % 10) + "und" + numToStr(val / 10 * 10);
    }
    if (val > 100) {
        if (val == 100) return "hundert";
        if (val % 100 == 0) return numToStr(val / 100) + "hundert";
        if (val / 100 == 1) return "einhundert" + numToStr(val % 100);
        return numToStr(val / 100) + "hundert" + numToStr(val % 100);
    }
}