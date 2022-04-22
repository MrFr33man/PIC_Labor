#include "Labor1/Labor1.h"

using namespace std;

int main(int argc, char *argv[]) {

    /// 1: Speichern der Programmargumente in in einem Vektor
    /// und Ausgabe durch eine for-Schleife -----------------
    vector<string> proArgs (argv, argv+argc);

    returnArgs(proArgs);
    /// -----------------------------------------------------

    cout << "---------------------------------------------------------" << endl;

    /// 2: Zuweisung eines Programmarguments an eine Fließkomma-
    /// variable. String ---> Double
    double const floatarg {stod(proArgs.back())};
    cout << "String vor Umwandlung: " << proArgs.back() << endl;
    cout << "Fliesskommazahl nach Umwandlung: " << floatarg << endl;
    ///---------------------------------------------------------

    cout << "---------------------------------------------------------" << endl;

    /// 4: Anwendung einer transzendenten mathematischen Funktion
    /// aus cmath. Hier Potenzrechnung.
    double powerin {3};
    double const valPow {calcPow(floatarg, powerin)};
    cout << floatarg << " hoch " << powerin << ": " << valPow << endl;
    ///`---------------------------------------------------------

    cout << "---------------------------------------------------------" << endl;

    /// 5: Cast und Zuweisung zu Ganzszahlvariable --------------
    int const castedInt {static_cast<int>(valPow)};
    cout << valPow << " als Integer gecastet: " << castedInt << endl;
    /// ---------------------------------------------------------

    cout << "---------------------------------------------------------" << endl;

    /// 6: Lokale Veränderung der Ganzzahlvariable --------------
    cout << "Variable vor Funktion: " << castedInt << endl;
    localChange(castedInt); // Call by Reference nicht möglich, da castedInt const ist und in der Methode verändert würde
    cout << "Variable nach verlassen der Funktion: " << castedInt << endl;
    /// ---------------------------------------------------------

    cout << "---------------------------------------------------------" << endl;

    /// 7: Ausgabe Ganzzahlwert in Hexadezimaldarstellung -------
    cout << castedInt << " in Hexdarstellung: " << hex << castedInt << dec << endl;
    /// ---------------------------------------------------------

    cout << "---------------------------------------------------------" << endl;

    /// 9: Vektor von Personen ----------------------------------------
    Person p1 {"K.", "Evin", "01.08.1990"};

    Person p2 {"Luke", "Bleiwalker", "21.02.1990"};

    Person p3 {"Santa", "Claus", "24.12.1903"};

    Person p4 = createPerson("Henrick", "Henrickson", "12.12.2000");

    vector<Person> personenVektor{p1, p2, p3, p4};

    returnPersonen(personenVektor);

    /// -------------------------------------------------------------

    cout << "---------------------------------------------------------" << endl;

    /// 10, 11 & 12: Einlesen von Personendaten aus Textdatei, als Programmargument übergeben
    /// mit Abfangen von Exeptions

    string filename {argv[1]};

    vector<Person> personenVektorFromFile {readPersonen(filename)};

    returnPersonen(personenVektorFromFile);

    /// ----------------------------------------------------------

    cout << "---------------------------------------------------------" << endl;

    /// 13: Berechnugn des Alters in Jahren, Tagen und Stunden

    Person muster {"Max/ine", "Musterdiverslol"};

    cout << "Bitte geben Sie ein Geburtsdatum (TT-MM-JJJJ) ein: " << endl;

    cin >> muster.geburtstag;

    muster.alterInJTS = calcAge(muster.geburtstag);

    returnPerson(muster);

    cout << "---------------------------------------------------------" << endl;

    /// 14: Ausgabe einer Zahl als Klartext:

    cout << "Max Mustermann ist " << numToStr(muster.alterInJTS.jahr) << " Jahre alt!" << endl;


    return 0;
}
