#include "Labor1/Labor1.h"

using namespace std;

int main(int argc, char *argv[]) {

    /// 1: Speichern der Programmargumente in in einem Vektor
    /// und Ausgabe durch eine for-Schleife -----------------
    vector<string> proArgs (argv, argv+argc);

    for (string arg : proArgs){
        cout << "Programmargument: " << arg << endl;
    }
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
    localChange(castedInt);
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

    /// 10: Einlesen von Personendaten aus Textdatei ----------------

    string filename {"lab1.txt"};

    vector<Person> personenVektorFromFile {readPersonen(filename)};

    returnPersonen(personenVektorFromFile);

    /// ----------------------------------------------------------

    cout << "---------------------------------------------------------" << endl;

    ///

    /*

    /// ---------------------------------------------------------

    /// Array
    array<string, 4> ZahlenWorte {"Null", "Eins", "Zwei", "Drei"};

    for(auto const &el: ZahlenWorte){
        cout << el << endl;
    }


    /// -------------------------------------------------



    cout << "Geburtstag: " << static_cast<unsigned>(p1.geburtstag.day()) <<
     "." << static_cast<unsigned>(p1.geburtstag.month()) <<
     "." << static_cast<int>(p1.geburtstag.year()) << endl;

     */
    return 0;
}
