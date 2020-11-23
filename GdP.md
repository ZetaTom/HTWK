```
  ____                      _ _                            _
 / ___|_ __ _   _ _ __   __| | | __ _  __ _  ___ _ __   __| | ___ _ __
| |  _| '__| | | | '_ \ / _` | |/ _` |/ _` |/ _ | '_ \ / _` |/ _ | '__|
| |_| | |  | |_| | | | | (_| | | (_| | (_| |  __| | | | (_| |  __| |
 \____|_|   \__,_|_| |_|\__,_|_|\__,_|\__, |\___|_| |_ \__,_|\___|_|
                                      |___/
 ____                                                _
|  _ \ _ __ ___   __ _ _ __ __ _ _ __ ___  _ __ ___ (_) ___ _ __ _   _ _ __   __ _
| |_) | '__/ _ \ / _` | '__/ _` | '_ ` _ \| '_ ` _ \| |/ _ | '__| | | | '_ \ / _` |
|  __/| | | (_) | (_| | | | (_| | | | | | | | | | | | |  __| |  | |_| | | | | (_| |
|_|   |_|  \___/ \__, |_|  \__,_|_| |_| |_|_| |_| |_|_|\___|_|   \__,_|_| |_|\__, |
                 |___/                                                       |___/
```

## C++ Grundlagen
### Compiler
GNU Compiler
* `g++ -Wall -std=c++14 programm.cpp` bzw. `g++ -Wall -std=c++14 programm.cpp -c`
  * Kompilieren bzw. *nur* kompilieren → Erzeugt Objektdatei programm.o
* `g++ -Wall -std=c++14 -o programm programm.o`
  * Erzeugt ausführbare Datei programm aus programm.o
* Zusammen: `g++ -Wall -std=c++14 -o programm programm.cpp`
  * `-Wall` aktiviert alle Fehlermeldungen und Warnungen
  * für clang++: `-Weverything`
  
### Hallo Welt und Programmstruktur
```c++
#include <iostream>

int main() {
  std::cout << "Hallo Welt!" << std::endl;
  return 0;
}
```

Strukturen
* `//Ich bin ein Kommentar`
* `/* Ich ebenfalls */`
* `#include < … >` bindet Bibliotheken ein
* `int main() {` ist der Einstiegspunkt für das Programm
* `{ … }` bildet den Funktionsrumpf bzw. Block
* `return 0;` Springt aus ihrem Programmteil heraus und beendet diesen; Rückgabe des Wertes `0`
  * optionale Rückmeldung an das System, dass die Ausführung erfolgreich war

### Symbole, Schlüsselwörter, Variablen und Bezeichner
Anhand der **Symbole** prüft der Rechner die formale Korrektheit eines Programms und setzt es in Maschinensprache um.
* Schlüsselwörter
* Bezeichner
* Literale
* Operatoren
* Kommentare
* Separatoren (“Whitespace” (Zwischenräume), Klammern)

**Schlüsselwörter** sind in einer Programmiersprache häufig reservierte Wörter , die eine fest vorgegebene Bedeutung haben. z.B. int, double, return, …

**Variablen, Bezeichner und Literale**
```c++
  int       a =         3;
//Datentyp  Bezeichner  Literal → Variable
//          L-Wert      R-Wert
```
*Variablen* sind Repräsentanten für Speicherbereiche.
*Literale* sind konstante Größen in einem Programm. Sie beschreiben die konkrete Werte für einen Datentyp.
Bezeichner| Definiert als
----------|--------------
\<Buchstabe\>|a-z, A-Z
\<Zeichen\>|\<Buchstabe\> \| _
\<Ziffer\>|0-9
\<Bezeichner\>|\<Zeichen\>
\<Bezeichner\>|\<Bezeichner\> \<Zeichen\>
\<Bezeichner\>|\<Bezeichner\> \<Ziffer\>

*Variablen beginnend mit _ und _ _ sind für die Standardbibliothek und das Betriebssystem vorgesehen*

**Deklaration und Initialisierung**
```c++
double d;           //deklariert aber nicht initialiert
double e = 1.0;     //reserviert Speicher und initialisiert ihn mit dem Wert 1
double f( 1.0 );
double g{ 1.0 };    //deklariert und initialisert, Prüfung auf Richtigkeit beim kompilieren
double i = double();//reserviert Speicher und initialisiert ihn mit dem Wert 0
double j{};         //reserviert Speicher und initialisiert ihn mit dem Wert 0
```

**Konstanten**
```c++
double d{ 1.0 };              //defiert d und setzt den Wert von d auf 1.0
                              //d kann im Programm verändert werden
contexpr double e{ 0.5/3.1};  //e ist ein konstanter Ausdruck und nach Definition nicht veränderbar
const double f{ 0.5/3.1 };    //f ist eine Konstante, die nach dem kompilieren konstant ist
constexpr double g{ f };      //in Ordnung, da ableitbar
```

### (Mathematische) Operatoren
c++|Beispiel|Bedeutung
---|--------|---------
+|2 + i| Plus
-|2 - i|Minus
++|++i|vorherige Inkrementierung um eins
++|i++|nachfolgende Inkrementierung um eins
--|--i|vorherige Dekrementierung um eins
--|i--|nachfolgende Dekrementierung um eins
\*|5 \* i|Multiplikation
/|i / 2|Division
%|i % 4|Modulo (Rest mit Vorzeichen von i)

Für alle anderen Rechenoperationen muss `cmath` eingebunden werden

c++|Beispiel|Bedeutung
---|--------|---------
=|i = 3|Zuweisung i ← 3
+=|i \*= 3|i = i \* 3
/=|i /= 3|i = i / 3
etc…

c++|Beispiel|Bedeutung
---|--------|---------
\<|i \< j|kleiner als
\>|i \> j|größer als
\<=|i \<= j|kleiner gleich
\>=|i \>= j|größer gleich
==|i == j|gleich =\> genau gleich
!=|i != j|ungleich =\> genau ungleich

c++|Beispiel|Bedeutung
---|--------|---------
!|!i|Negation
&&|i && true|Konjunktion
\|\||i \|\| false|Disjunktion
!=|i != j|Antivalenz
==|i == true|Äquivalenz

## Datentypen und Umwandlungen in C++
**bool**
* Akzeptiert zwei Zustände
* true (1) oder false (0)
**char**
* Zeichen, Ziffer, Steuerzeichen
* Intern als ASCII-Nummer gespeichert
  * Zuweisung als `i='x'` bzw. `i=64`
  * Ein-/Ausgabe immer als Zeichen
  * Rechnen und vergleichen möglich `'a' < 'b'`
  
**Zahlen**
Typ|Bits|Maximum|Genauigkeit
---|----|-------|-----------
char|8|127
unsigned char|8|255
int|32|-2147483648
unsigned int|32|4294967295
short int|16|32767
long int|64|2147483647
long long int|64|(2^63)-1
float|32|±1.2E − 38 … ± 3.4E + 38|7 Stellen
double|64|±2.2E − 308 … ± 1.8E + 308|15 Stellen
long double|80|±3.4E − 4932 … ± 1.2E + 4932|18 Stellen

* Suffixe
  * geben den Datentyp an
  * `42` int
  * `42u` unsigned int
  * `42l` long int
  * `42lu` long unsigned int
  * `42llu` long long unsigned int

* Präfixe
  * `int a{ 0x20 };` Hexadezimal
  * `int c{ 020 };` Oktal
  * `unsigned int e{ 0b01100101 };` Binär

* Infixe
  * `double d{ 4e2 };` 400 = 4 ∗ 10^2
  * `double d{ 4E2 };` 400 = 4 ∗ 10^2

**Enumerationen**
* Enumerationen (enum) sind selbstdefinierte Datentypen, die eine abzählbare Ausprägung von Werten besitzen
* Somit kann garantiert werden, dass eine Variable keinen falschen Wert annehmen kann
```c++
enum class Ampelfarbe { Rot, Gruen }; //Neuer Datentyp wird definiert
Ampelfarbe ampel1 = Ampelfarbe::Rot;  //Variablen können nur Rot und Gruen annehmen
if( anfrageVonFussgaenger ) {
  ampel1 = Ampelfarbe::Gruen;
}
```
* Interne Speicherung als Ganzzahl
```c++
enum class Ampelfarbe { Rot = 0, Gruen = 1};  //Explizite Zuweisung
```

**Typumwandlungen**
* Umwandlung von Typen kann zu Genauigkeitsverlusten bis hin zum Informationsverlust führen. Ursachen dafür sind:
  * Genauigkeitverlust
  * Überschreitung des Wertebereiches
  * Rundung
  * Vorzeichenverlust
* Jeder R-Wert des Typs char, signed char, unsigned char, short int und unsigned short int kann ohne Informationsverlust in einen int-Wert umgewandelt werden (engl. *integral promotion*)
* Integrale Typen sind untereinander konvertierbar. Die Fälle, die nicht zu den obigen gehören werden *integral conversion* genannt. Sonderfälle sind die Typen bool und enum
* Automatische Umwandlung wird unterstützt
```c++
float x {};
float comp = ( x == 0.0 );  //comp enthält den Wert 1.0
```
* Manuelle Umwandlung
```c++
//empfohlene Version in C++
double d {0.1};
int i = static_cast< int >( d );
double e = static_cast<double>( i );

//veraltet
double d {0.1};
int i = (int)d;
int i = int(d);
```

## RAII und Variablen
*In C++ wird der Zugriff auf Resourcen häufig über Variablen dargestellt. Das Halten der Resource ist somit automatisch vom Definitionsbereich einer Variablen abhängig. Verlässt diese Variable ihren Definitionsbereich, so kann sie Resourcen elegant und automatisiert freigeben. Gängige Beispiele sind der Zugriff auf*
* *Speicher(-bereiche) (z.B. double)*
* *Dateien, Netzwerkports, …(z.B. std::fstream)*

### Dateien lesen und Schreiben
* Der Dateityp `std::ofstream` *Output-Filesystem* erlaubt es, in Dateien zu schreiben
* Beim verlassen des Gültigkeitsbereichs wird die Datei automatisch geschlossen
```c++
int main() {
  std::ofstream fileOut("test.txt") //Anlegen einer Variable mit Dateinamen als Argument
                                    //→ öffnen der Datei
  if( fileOut ) {                   //falls die Datei schreibbar ist
    fileOut << "Hallo Welt"         //schreibt "Hallo Welt" in die Datei
  }
}                                   //Ende des Blockes, fileOut verliert Gültigkeit
                                    //Resource wird freigegeben; Datei geschlossen
```

### Namensräume
* `std` ist der Namensraum der Standardbibliothek
* Namensräume werden mit `::` von Variablen abgetrennt
  * `using namespace std;` setzt `std` als Standard *nicht empfohlen*
  * `using std::cout;` ermöglicht partielle Nutzung
  * `std::cout << a` → `cout << a`
* Eigene Namensräume erstellen
```c++
namespace htwk {            //Deklaration eines eigenen Namensraums
  const int dozenten{ 1 };  //Variable im Namensraum
  const int studenten{ 2 };
  namespace info {          //Verschachtelung möglich
    const int a{ 3 };
    const int b{ 4 };
  }
}

int main() {
  int dozenten = htwk::dozenten;
  int a = htwk::info::a;
}
```

### Globale Variablen (sind zu vermeiden)
```c++
int a = 5;    //Deklaration einer globalen Variable
int main() {
  //…
  int b = a;  //Die Variable ist überall gültig
  //…         //und kann nicht neu definiert werden
}
```

### if, else und der geschleifte Spaß
* Fallunterscheidung (wahr oder falsch)
```c++
if( … ) {   //wenn …
  //…       //dann …
} else {    //sonst …
  //…       //optional
}
```
* Fallunterscheidung
```c++
switch( … ) {       //Unterscheidung anhand von …
  case 1:           //Fall, dass Wert == 1
    //…             //dann
    break;          //beendet Ausführung des switch-Blocks
  case 'b':         //zulässig char
    //…
    break;
  case farbe::blau: //zulässig enum
  case farbe::gelb: //wenn einer übereinstimmt
  case farbe::cyan: //dann
    //…
    break;
  default:          //falls kein anderer Fall eintritt
    //…
}
```
* Schleifen
  * `break;` Sofortiger Abbruch der nächstäußeren switch/while/do-while/for-Anweisung
  * `continue;` Abbruch der aktuellen und sofortiger Start des nächsten Zykels einer while/do-while/for-Anweisung
```c++
while( … ) {    //Kopfgesteuerte Schleife
  //…           //Solange …
}               //tue …

do{             //Fußgesteuerte Schleife
  //…           //wird mindestens 1x ausgeführt
} while( … );

//Zählschleife
for (int i; i < 100; ++i) {
  //…
}
```

## Funktionen und Funktionsaufrufe
Wir kennen verschiedene *Unterprogramme* bereits:
* `std::sqrt`, definiert als `double sqrt( double aqrg )`
* `std::isnan`, definiert als `bool isnan( float num )` → Prüft ob Zahl `NaN` ist
* den Eintrittspunkt des Programms: `int main()`

Unterscheidung in
* Prozeduren (`void`)
  * Unterprogramme, die keine Werte zurückgeben
* Funktionen (`int`, `double`, etc.)
  * Unterprogramme, die Werte zurückgeben
  * dienen zur Strukturierung des Programms

### Aufbau einer Funktion
```c++
double            sqrt          ( double x  )
Rückgabedatentyp  Funktionsname   Parameter 
```

* Rückgabedatentyp: der Typ, den die Funktion an den Aufrufer zurückgibt
  * `void` → keine Rückgabe
* Funktionsname: Name der Funktion, case sensitive
* Argumentenliste: durch Komma getrennte Liste von Datentypen für die Argumente der Funktion
  * optional mit Bezeichner
  * kann auch leer sein

```c++
#include <iostream>

double Quadrat( double x);    //Deklaration einer Funktion, die einen double-Wert
                              //zurückgibt und einen als Eingabe nimmt (x)
double Quadrat( double x) {   //Implementierung bzw. Definition
  return x * x;
}

int main() {
  double x{ 3 };
  double y = Quadrat( x );    //Funktionsaufruf
  std::cout << x << "²" << "=" << y << std::endl;
}
```
Die Variable `x` kommt zwei Mal vor. Sie ist wegen RAII nur in der jeweiligen Funktion bzw. dem Programmanschnitt definiert. So wird eine Kollision vermieden.

**Funktionsdeklaration**
```c++
int f();            //Funktion f mit leerer Argumentenliste
int f(void);        //Selbiges
int f(int, char);   //Funktion f mit zwei Parametern
void f(int, char);  //Selbiges ohne Rückgabewert
```

**Funktionsdefinition**
```c++
int zweiundvierzig() {
  return 42;
}

double lineareFnkt( double x, double m, double n ) {
  return m * x + n;
}

void ausgabe( double zahl ) {
  std::cout << "Die Zahl lautet: " << zahl << std::endl;
}
```

### Parameterübergabe
**Call by Value**
* Variable wird für das Unterprogramm kopiert und separat gespeichert
* für kleine Datentypen geeignet → sonst hoher Speicher Aufwand
```c++
int CallByValue( int a ) {
  return a * 3;
}
```

**Call by const-Reference**
* bei großen Datenmengen
* Daten können *nur gelesen* werden, da `const`
* weist einen neuen Namen für die Bearbeitung in einer Unterfunktion zu (Verknüpfung)
* Speicheraufwand minimal
```c++
int CallByConstReference( const int& a ) {
  std::cout << a;
}

int b = 4;
CallByConstReference(b);
```

**Call by Reference**
* bei großen Datenmengen
* wenn Werte geändert werden müssen → `iostream`
* weist einen neuen Namen für die Bearbeitung in einer Unterfunktion zu (Verknüpfung)
* Speicheraufwand minimal
```c++
long long CallByReference( long long& a ) {
  a+= 3;
}

long long b = 4;
CallByReference(b);
```
