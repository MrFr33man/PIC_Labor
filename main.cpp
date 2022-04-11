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

    /// 2: Zuweisung eines Programmarguments an eine Fließkomma-
    /// variable. String ---> Double
    double const floatarg {stod(proArgs.back())};
    cout << "String vor Umwandlung: " << proArgs.back() << endl;
    cout << "Fliesskommazahl nach Umwandlung: " << floatarg << endl;
    ///---------------------------------------------------------

    /// 4: Anwendung einer transzendenten mathematischen Funktion
    /// aus cmath. Hier Potenzrechnung.
    double powerin {3};
    double const valPow {calcPow(floatarg, powerin)};
    cout << floatarg << " hoch " << powerin << ": " << valPow << endl;
    ///`---------------------------------------------------------

    /// 5: Cast und Zuweisung zu Ganzszahlvariable --------------
    int const castedInt {static_cast<int>(valPow)};
    cout << valPow << " als Integer gecastet: " << castedInt << endl;
    /// ---------------------------------------------------------

    /// 6: Lokale Veränderung der Ganzzahlvariable --------------
    cout << "Variable vor Funktion: " << castedInt << endl;
    localChange(castedInt);
    cout << "Variable nach verlassen der Funktion: " << castedInt << endl;
    /// ---------------------------------------------------------

    /// 7: Ausgabe Ganzzahlwert in Hexadezimaldarstellung -------
    cout << castedInt << " in Hexdarstellung: " << hex << castedInt << dec << endl;
    /// ---------------------------------------------------------

    /// 8: Vektor von Personen ----------------------------------
    Person p1;

    p1.vorname ="Evin";
    p1.nachname = "K.";
    p1.geburtstag = std::chrono::August/1/1990;

    Person p2;

    p1.vorname = "Luke";
    p2.nachname = "Bleiwalker";
    p2.geburtstag = std::chrono::December/21/1969;

    Person p3;

    p3.vorname = "Santa";
    p3.nachname = "Claus";
    p3.geburtstag = std::chrono::December/24/1903;

    vector<Person> PersonenVektor{p1, p2, p3};

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

    return 0;
}
