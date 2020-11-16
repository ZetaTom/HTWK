# Grundlagen der Programmierung 2020
## C++ Grundlagen
### Compiler
GNU Compiler
* `g++ -Wall -std=c++14 programm.cpp`
  * Kompilieren -> Erzeugt Objektdatei programm.o
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
//Datentyp  Bezeichner  Literal => Variable
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

Für alle anderen Rechenoperationen muss `cmath` eingebunden werden.

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
* Enumerationen (enum) sind selbstdefinierte Datentypen, die eine abzählbare Ausprägung von Werten besitzen.
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
* Integrale Typen sind untereinander konvertierbar. Die Fälle, die nicht zu den obigen gehören werden *integral conversion* genannt. Sonderfälle sind die Typen bool und enum.
* Automatische Umwandlung wird unterstützt
```c++
float x {};
float comp = ( x == 0.0 );  //comp enthält den Wert 1.0
```
* Manuelle Umwandlung
```c++
//empfohlene Version in C++
double d {0.1}; int i = static_cast< int >( d );
double e = static_cast<double>( i );

//veraltet
double d {0.1};
int i = (int)d;
int i = int(d);
```

## RAII und Variablen
