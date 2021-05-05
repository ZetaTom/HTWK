```
  ____                      _ _                              _
 / ___|_ __ _   _ _ __   __| | | __ _  __ _  ___ _ __     __| | ___ _ __
| |  _| '__| | | | '_ \ / _` | |/ _` |/ _` |/ _ | '_ \   / _` |/ _ | '__|
| |_| | |  | |_| | | | | (_| | | (_| | (_| |  __| | | | | (_| |  __| |
 \____|_|   \__,_|_| |_|\__,_|_|\__,_|\__, |\___|_| |_|  \__,_|\___|_|
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
* `// Ich bin ein Kommentar`
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
    int         a   =       3;
//  Datentyp    Bezeichner  Literal → Variable
//              L-Wert      R-Wert
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
double d;               // deklariert aber nicht initialisiert
double e = 1.0;         // reserviert Speicher und initialisiert ihn mit dem Wert 1
double f( 1.0 );
double g{ 1.0 };        // deklariert und initialisiert, Prüfung auf Richtigkeit beim kompilieren
double i = double();    // reserviert Speicher und initialisiert ihn mit dem Wert 0
double j{};             // reserviert Speicher und initialisiert ihn mit dem Wert 0
```

**Konstanten**
```c++
double d{ 1.0 };                // definiert d und setzt den Wert von d auf 1.0
                                // d kann im Programm verändert werden
contexpr double e{ 0.5/3.1};    // e ist ein konstanter Ausdruck und nach Definition nicht veränderbar
const double f{ 0.5/3.1 };      // f ist eine Konstante, die nach dem kompilieren konstant ist
constexpr double g{ f };        // in Ordnung, da ableitbar
```

**Statische Variablen**
```c++
void f(int a, int b) {
    static int n = 0;   // beim ersten Funktionsdurchlauf: definiert und setzt n auf 0
    // ...              // bei folgenden Aufrufen: wird n vom vorhergehenden Aufruf verwendet
}                       // für Rekursion nützlich (siehe Hanoi)
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
/|i / 2|Division (von Ganzzahlen)
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
float|32|±1.2E - 38 … ± 3.4E + 38|7 Stellen
double|64|±2.2E - 308 … ± 1.8E + 308|15 Stellen
long double|80|±3.4E - 4932 … ± 1.2E + 4932|18 Stellen

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
  * `double d{ 4e2 };` 400 = 4 * 10^2
  * `double d{ 4E2 };` 400 = 4 * 10^2

**Enumerationen**
* Enumerationen (enum) sind selbstdefinierte Datentypen, die eine abzählbare Ausprägung von Werten besitzen
* Somit kann garantiert werden, dass eine Variable keinen falschen Wert annehmen kann
```c++
enum class Ampelfarbe { Rot, Gruen };   // Neuer Datentyp wird definiert
Ampelfarbe ampel1 = Ampelfarbe::Rot;    // Variablen können nur Rot und Gruen annehmen
if( anfrageVonFussgaenger ) {
    ampel1 = Ampelfarbe::Gruen;
}
```
* Interne Speicherung als Ganzzahl
```c++
enum class Ampelfarbe { Rot = 0, Gruen = 1};    // Explizite Zuweisung
```

### Typumwandlungen
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
float comp = ( x == 0.0 );  // comp enthält den Wert 1.0
```

**Manuelle Umwandlung**
```c++
// empfohlene Version in C++
double d {0.1};
int i = static_cast< int >( d );
double e = static_cast<double>( i );

// veraltet
double d {0.1};
int i = (int)d;
int i = int(d);
```

## RAII und Variablen
*In C++ wird der Zugriff auf Resourcen häufig über Variablen dargestellt. Das Halten der Resource ist somit automatisch vom Definitionsbereich einer Variablen abhängig. Verlässt diese Variable ihren Definitionsbereich, so kann sie Resourcen elegant und automatisiert freigeben. Gängige Beispiele sind der Zugriff auf*
* *Speicher(-bereiche) (z.B. double)*
* *Dateien, Netzwerkports, …(z.B. std::fstream)*

### Ein- und Ausgabe
* Ausgabe aka. `printf`
  * Enthalten in `iostream`
  * `std::cout << var` bzw. `std::cout << "Hallo"`
  * Verkettung möglich `std::cout << "Wert von n: " << n "MeV"`
  * neue Zeilen
      * `std::endl` fügt programmabhängig das Zeilenende ein und wartet, bis Ausgabe beendet
      * `"\n"` Zeilenende unter *NIX, inkompatibel mit z.B. WIN
      * `std::flush` Wartet bis die Ausgabe beendet ist; Erzwingt die Ausgabe
* Formatierung von Zahlen
  * Führende Zeichen bzw. Leerzeichen Einfügen
      * Bestandteil von `iomanip`
      * `std::cout << std : : setw ( 4 ) << 1 ;` gibt `    1` aus
      * `std::cout << std::setfill ('x') << std::setw (10) << 42` gibt `xxxxxxxx42` aus
  * Pluszeichen ausgeben: `std::cout << std::showpos`
  * Wissenschaftliche Schreibweise: `std::cout << std::scientific`
  * Ausgabegenauigkeit festlegen
      * `std::cout << std::setprecision(5) << 3.14159` gibt `3.1416` aus
      * `std::cout << std::setprecision(9) << 3.14159` gibt auch `3.1416` aus
      * `std::cout << std::fixed << std::setprecision(9) << 3.14159` gibt `3.141590000` aus
* Eingabe lesen
  * Enthalten in `iostream`
  * Eingabe von *Worten* möglich. D.h. Bis zu `\n` oder `␣`
  * `std::cin >> var`
  * Einlesen einer Zeile möglich mit: `std::getline(std::cin, var)`
      * also bis LF lesen


### Dateien lesen und Schreiben
* Der Dateityp `std::ofstream` *Output-Filesystem* erlaubt es, in Dateien zu schreiben
* Beim verlassen des Gültigkeitsbereichs wird die Datei automatisch geschlossen
```c++
int main() {
    std::ofstream fileOut("test.txt")   // Anlegen einer Variable mit Dateinamen als Argument
                                        // → öffnen der Datei
    if( fileOut ) {                     // falls die Datei schreibbar ist
    fileOut << "Hallo Welt"             // schreibt "Hallo Welt" in die Datei
    }
}                                       // Ende des Blockes, fileOut verliert Gültigkeit
                                        // Resource wird freigegeben; Datei geschlossen
```

**Einlesen einer gesamten Datei**
```c++
std::string leseGanzeDatei2(const std::string& dateiname) {
    std::ifstream ifs(dateiname);
    std::string text;
    while(ifs) {
        std::string temp;
        std::getline(ifs, temp);
        text.append(temp);
    }
    return text;
}

// oder

#include <streambuf>
#include <fstream>
std::string leseGanzeDatei(const std::string& dateiname) {
    std::ifstream ifs( dateiname );
    return std::string( (std::istreambuf_iterator<char>(ifs)),
                        (std::istreambuf_iterator<char>()));
}
```

### Namensräume
* `std` ist der Namensraum der Standardbibliothek
* Namensräume werden mit `::` von Variablen abgetrennt
  * `using namespace std;` setzt `std` als Standard *nicht empfohlen*
  * `using std::cout;` ermöglicht partielle Nutzung
  * `std::cout << a` → `cout << a`

**Eigene Namensräume erstellen**
```c++
namespace htwk {                // Deklaration eines eigenen Namensraums
    const int dozenten{ 1 };    // Variable im Namensraum
    const int studenten{ 2 };
    namespace info {            // Verschachtelung möglich
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
int a = 5;      // Deklaration einer globalen Variable
int main() {
    // ...
    int b = a;  // Die Variable ist überall gültig
    // ...      // und kann nicht neu definiert werden
}
```

### if, else und der geschleifte Spaß
**Fallunterscheidung (wahr oder falsch)**
```c++
if( … ) { // wenn …
    // ...  // dann …
} else {    // sonst …
    // ...  // optional
}
```

**Fallunterscheidung**
```c++
switch( … ) {         // Unterscheidung anhand von …
    case 1:             // Fall, dass Wert == 1
    // ...              // dann
    break;              // beendet Ausführung des switch-Blocks
    case 'b':           // zulässig char
    // ...
    break;
    case farbe::blau:   // zulässig enum
    case farbe::gelb:   // wenn einer übereinstimmt
    case farbe::cyan:   // dann
    // ...
    break;
    default:            // falls kein anderer Fall eintritt
    // ...
}
```

**Schleifen**
  * `break;` Sofortiger Abbruch der nächstäußeren switch/while/do-while/for-Anweisung
  * `continue;` Abbruch der aktuellen und sofortiger Start des nächsten Zykels einer while/do-while/for-Anweisung
```c++
while( … ) {  // Kopfgesteuerte Schleife
    // ...      // Solange …
}               // tue …

do{             // Fußgesteuerte Schleife
    // ...      // wird mindestens 1x ausgeführt
} while( … );

// Zählschleife
for (int i; i < 100; ++i) {
    // ...
}
```

## Funktionen und Funktionsaufrufe
Wir kennen verschiedene *Unterprogramme* bereits:
* `std::sqrt`, definiert als `double sqrt( double arg )`
* `std::isnan`, definiert als `bool isnan( float num )` → Prüft ob Zahl `NaN` ist
* den Eintrittspunkt des Programms: `int main()`

Unterscheidung in
* Prozeduren (`void`)
  * Unterprogramme, die keine Werte zurückgeben
* Funktionen (`int`, `double`, etc.)
  * Unterprogramme, die Werte zurückgeben
  * dienen zur Strukturierung des Programms

* C++ unterscheidet, welche Funktion aufgerufen wird *nicht nur am Funktionsnamen* (wie C), *sondern auch am Datentyp*

### Aufbau einer Funktion
**Prototyp der Funktion**
```c++
double              sqrt            ( double x  )
Rückgabedatentyp   Funktionsname    Parameter
```

* Rückgabedatentyp: der Typ, den die Funktion an den Aufrufer zurückgibt
  * `void` → keine Rückgabe
* Funktionsname: Name der Funktion, case sensitive
* Argumentenliste: durch Komma getrennte Liste von Datentypen für die Argumente der Funktion
  * optional mit Bezeichner
  * kann auch leer sein

```c++
#include <iostream>

double Quadrat( double x);      // Deklaration einer Funktion, die einen double-Wert
                                // zurückgibt und einen als Eingabe nimmt (x)
                                // Prototyp der Funktion
double Quadrat( double x) {     // Implementierung bzw. Definition
    return x * x;
}

int main() {
    double x{ 3 };
    double y = Quadrat( x );    // Funktionsaufruf
    std::cout << x << "²" << "=" << y << std::endl;
}
```
Die Variable `x` kommt zwei Mal vor. Sie ist wegen RAII nur in der jeweiligen Funktion bzw. dem Programmanschnitt definiert. So wird eine Kollision vermieden.

**Funktionsdeklaration**
```c++
int f();            // Funktion f mit leerer Argumentenliste
int f(void);        // Selbiges
int f(int, char);   // Funktion f mit zwei Parametern
void f(int, char);  // Selbiges ohne Rückgabewert
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

C++ unterscheidet Funktionen nach **Funktionsname und Parameter**. Beim Aufrufen wird anhand des Argumentes entschieden, welche Funktion ausgewählt wird. Diese Vorgehensweise nennt man *Überladen der Funktion.*
```c++
int sqrt( int );
float sqrt( float );
double sqrt( double );
long double sqrt( long double );

auto a = sqrt( 2 );     // verwendet sqrt( int )
auto b = sqrt( 2.0f );  // verwendet sqrt( float )
auto c = sqrt( 2.0 );   // verwendet sqrt( double )
auto d = sqrt( 2.0l );  // verwendet sqrt( long double )
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
  * benötigt (theoretisch) keinen zusätzlichen Speicher
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
  * benötigt (theoretisch) keinen zusätzlichen Speicher
* Speicheraufwand minimal
* *Referenzen sind immer neue Namen, für vorhandene Objekte*
```c++
long long CallByReference( long long& a ) {
    a+= 3;
}

long long b = 4;
CallByReference(b);
```


**Optionale Parameter**
* n mögliche Parameter, von denen nur einige übergeben werden müssen
* Festlegung der optionalen Parameter auf einen Standardwert
```c++
int add(int a, int b = 0, int c = 0, int d = 0) {
    return a + b + c + d;
}
int r1 = add(3);        // a = 3, b = 0, c = 0, d = 0
int r2 = add(3, 4);     // a = 3, b = 4, c = 0, d = 0
int r3 = add(3, 4, 5);  // a = 3, b = 4, c = 5, d = 0
```

* Wenn beliebig viele Parameter übergeben werden sollten: **varargs**
```c++
printf( "Hallo %d %d %d %d", 1, 2, 3, 4 );
```

### Dokumentation von Funktionen
```c++
/**
 * @brief Berechnet die Quadratwurzel aus der positiven Zahl c
 *
 * Berechnet die Quadratwurzel über das iterative Newtonverfahren
 * zum Berechnen der Nullstellen von \f[ f(x) = c - xˆ2 \f].
 * Das Verfahren wird nach n Iterationen abgebrochen.
 *
 * @param c nicht negative, reellwertige Zahl
 * @param n gibt die Anzahl der Newton-Iterationen im numerischen Verfahren an
 * @return die Quadratwurzel zur Zahl n
 * @pre c >= 0
 */
double wurzel( double c, unsigned int n = 20 ) {
    // ...
}
```

## Iteration und Rekursion
### Speicherbereiche eines Programms
```
+-----------------+
|  Heap / Haufen  |
+-----------------+
| Stack /  Stapel |
+-----------------+
| Static,  Global |
+-----------------+
|   Code (Text)   |
+-----------------+
```

**Text Segment**
* Der ausführbare Code eines Programms
  * meist nur lesbar
  * selbstmodifizierender Code aber möglich

**Global Segment**
* Globale Variablen (*außerhalb* `main`) und feste Zeichenketten (*im Programm*)

**Aufrufstapel (Call Stack)**
* Speicherbereich, der zur Laufzeit den aktuellen Zustand speichert
* Bei jedem Funktionsaufruf wird ein Segment auf den Stapel abgelegt
* Jeder Eintag beinhaltet mindestens
  * Aufrufparameter
  * lokale Variablen
  * Rückgabewerte
  * Rücksprungadresse

```
         Oberes Stapelende
+-----> +-----------------+ +----------+
Stapel- |Lokale  Variablen|
zeiger  +-----------------+  Aktueller
        |Rücksprungadresse|  Aufruf-
+-----> +-----------------+  rahmen
Rahmen- |    Parameter    |
zeiger  +-----------------+ +----------+
        +-----------------+ +----------+
        |Lokale  Variablen| Aufruf-
        +-----------------+ Rahmen der
        |Rücksprungadresse| letzten AE
        +-----------------+ +----------+
        +-----------------+ +----------+
        |Rücksprungadresse| Aufruf-
        +-----------------+ rahmen der
        |                 | vorletzten
        |    Parameter    | Aufrufebene
        |                 |
        +-----------------+
        |        .        |
        |        .        |
```
Stapelinhalt nach Rücksprung
```
         Oberes Stapelende
+-----> +-----------------+  +----------+
Stapel- |  Rückgabewerte  |
zeiger  +-----------------+   Aktueller
        +-----------------+   Aufruf-
        |Lokale  Variablen|   rahmen
        +-----------------+
        |Rücksprungadresse|
+-----> +-----------------+  +----------+
Rahmen- +-----------------+  +----------+
zeiger  |Rücksprungadresse|  Aufruf-
        +-----------------+  rahmen der
        |                 |  letzten
        |    Parameter    |  Aufrufebene
        |                 |
        +-----------------+  +----------+
        |        .        |  +----------+
        |        .        |
```
Jeder Aufruf einer Funktion hat ihren eignen Speicher und eigene Variablen auf dem Stapel.

### Rekursion
Eine Funktion ruft *sich selbst* auf
```c++
int funktion( … ) {
    if( Abbruchfall erreicht ) {            // Rekursionsanfang mit Abbruchbedingung
    // Löse den einfachsten Fall           // (mehrere möglich)
    // Ergebnis zurückgeben
    } else {                                // Rekursionsschritt
    // Teile das Problem in Teilprobleme
    // rufe funktion( … ) auf
    // Kombiniertes Ergebnis zurückgeben
    }
```

**Der größte gemeinsame Teiler**
* ggT(a, b) = {ggT(b, a - b) falls a > b; ggT(a, b - a) falls b > a}
* ggT(a, b) = ggT(b, a)
* ggT(a, a) = a
```
a, b ∈ ℕ
|––|––|––|––|––|  a
|––|––|––|  |  |  b
|  |  |  |  |  |
|––|––|––|––|––|  a
|––|––|––|__|__|  b, c
|  |  |  |  |  |
|  |  |  |  |––| Teiler
→ Eine Zahl, die a und b teielt muss auch c teilen.
```
```c++
unsigned int ggT( unsigned int a, unsigned int b ) {
    if( a == b ) {
    return a;
    }
    else if( a > b ) {
    return ggT( b, a - b );
    } else  // ( a < b )
    {
    return ggT( a, b - a );
    }
}
```

**Die Türme von Hanoi**
```
        ++              ++              ++
        ||              ||              ||
      +----+            ||              ||
      +----+            ||              ||
    +--------+          ||              ||
    +--------+          ||              ||
  +------------+        ||              ||
  +------------+        ||              ||
+------------------------------------------------+
|       1.              2.              3.       |
+------------------------------------------------+
```
Ziel ist es, alle Scheiben vom 1. auf den 3. Stapel zu bewegen. Dabei darf jedoch nur eine Scheibe gleichzeitig bewegt werden und es darf keine größere Scheibe auf einer kleineren liegen.

Idee zur rekursiven Lösung:
* Alle Scheiben bis auf eine werden auf 2. (dem Hilfsstapel) gelegt
* Die letzte Scheibe wird auf 3. (dem Zielstapel) abgelegt
* Die restlichen Schreiben müssen von 2. auf 3. geschoben werden

**Umsetzung in C++**
```c++
#include <iostream>

// Ausgabe der Züge
void ziehe( int von, int nach ) {
    static int zuege = 0;
    zuege++;
    std::cout << "Zug " << zuege << " von " << von << " nach " << nach << "\n";
}

/**
 * Löst das Türme von Hanoi Problem mit n Scheiben
 *
 * Die Funktion gibt die Züge für die Lösung mit n
 * Scheiben auf dem Bildschirm aus, nutzt dafür die Funktion ziehe zur formatierten Ausgabe.
 * Die Funktion arbeitet Rekursiv.
 *
 * @param n Anzahl der Schieben die zu ziehen sind
 * @param von Der Stapel von dem gezogen wird
 * @param nach Der Stapel auf den gezogen werden soll
 * @param hilf Der Stapel, der als Hilfsstapel verwendet werden soll.
 */
void loeseHanoi(int n, int von, int nach, int hilf ) {
    if( n == 1 ) {
    // Löse den Trivialfall → Eine Scheibe
    ziehe( von, nach );
    } else {
    // Lege alle Scheiben bis auf eine auf den Hilfsstapel
    loeseHanoi( n - 1, von, hilf, nach );
    // Lege diese Scheibe auf den Zielstapel
    // loeseHanoi( 1, von, nach, hilf ); bzw.
    ziehe( von, nach );
    // Lege alle anderen Schreiben vom Hilfsstapel auf den Zielstapel
    loeseHanoi( n - 1, hilf, nach, von );

    }
}

int main() {
    int N;
    std::cin >> N;
    loeseHanoi( N, 1, 3, 2 );
}
```

### Rekursion ←→ Iteration
```c++
unsigned int multipliziere( unsigned int a, unsigned int b ) {
    unsigned int ergebnis = 0;
    for( unsigned int i = 1; i <= b; ++i ) {
    ergebnis = ergebnis + a;
    }
    return ergebnis;
}

unsigned int multipliziere( unsigned int a, unsigned int b ) {
    unsigned int ergebnis = 0;
    while( b > 0 ) {
    ergebnis = ergebnis + a; --b;
    }
    return ergebnis;
}

unsigned int multipliziere( unsigned int a, unsigned int b ) {
    if( b == 0 ) {return 0; }
    else { return multipliziere( a, b - 1 ) + a; }
}
```

### Rekursion zur Compilezeit
* Der Compiler kann Rekursion (aber keine Schleifen) auswerten.
* Festlegen der Werte als `constexpr` → Steht zur Compilezeit fest
  * **ALLE** Parameter müssen zur Compilezeit feststehen
```c++
constexpr int a = 10;           // a = 10 ist konstant
constexpr int c = 3 * a;        // c = 30 ist konstant

constexpr int function(int c);  // deklariert Funktion, die zur Compilezeit ausgewertet werden kann.
```

### Definitionen und Begriffe
**Wann ist Rekursion zu verwenden?** (siehe *Rekursion*.)
* Wenn das Problem rekursiv gestellt ist
  * Fibonacci, Fakultät, Türme von Hanoi, Suchen von Wegen, Pfadplanung…)
* Wenn keine Schleifen möglich/erlaubt
* Wenn die maximale Rekursiontiefe nicht überschritten wird
  * ≙ Anzahl der gleichzeitigen Aufrufe einer rekursiven Funktion

**Lineare Rekursion**
* Funktion, die pro Ausführung nur einen rekursiven Aufruf vornimmt
* Linearer Speicherbedarf

**Endrekursive Funktion**
* Eine Funktion ist endrekursiv (tail recursive), wenn die Rekursion (außer `return`) der letzte Befehl in der Funktion ist.
* Können besser optimiert bzw. umgeschrieben werden

**Baumrekursive Funktion/nicht-linear**
* Funktion, die pro Durch- lauf mehrere Aufrufe von sich selbst beinhaltet

**Indirekte rekursive Funktionen**
* Zusammenspiel mehrerer Funktionen, die sich untereinander aufrufen

**Gegenseitige Rekursion**
* Zwei Funktionen, die sich gegenseitig aufrufen

## Felder (ohne Raps)
* Zusammenfassen vom mehreren Objekten (gleichen Typs) zu einem Feld bzw. *Array*, *Vektor*, *Liste*, etc…
* Einträge sind in der Regel indizierbar
* Entsprechende Bibliotheken benötigt: `vector`, `array`, `string`

**Felder fester Länge**
* Der Datentyp und die Größe stehen zur Compilezeit fest
* Deklaration mit Template
  * Möglichkeit, Datenstrukturen für viele Typen auf einmal zu definieren
  * Namen und Templateparamter als Argumente
  * *Diese müssen zur Compilezeit feststehen*

### Einführung in die Welt der Felder
```c++
std::array  < int, 10 >         feld;
Datentyp    Templateparameter   Variablenname
            Inhaltstyp, Größe
                            //definiert ein statisches Feld der Länge 3
std::array< int, 10 > feld = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
                            // deklariert das Feld feld, vom Typ int mit 10 Elementen
int feld[10] = {…}            // veraltet

int n = 3;
std::cout << feld.at(n);    // Ausgabe von dem Element an Stelle 3
                            // Prüft, ob der Index gültig ist
std::cout << feld[n];       // Selbiges, ohne Test → schneller

int i = 7;
feld.at(i) = 41;            // Das Element an Stelle 3 überschreiben
feld[i] = 42;
std::cout << feld.size();   // Größe des Feldes asugeben
```

**Felder dynamischer Länge**
* Größe bleibt während der Laufzeit veränderlich
  * Größe muss nicht vorher festgelegt werden
  * Zeilen in Matrizen müssen nicht gleich lang sein
  * Prüfung auf Größe in Laufzeit kostet Zeit
  * Zusätzlicher Speicher für Länge → für keine Felder ineffizient

```c++
std::vector< int > leer;        // deklariert leeres Feld vom Typ int
std::vector< int > ehn(N);      // deklariert Vektor der Länge N vom Typ int
std::vector< int > zuv(N, 42);  // deklariert Vektor der Länge N und setzt alle Werte auf 42
std::vector< int > prim( {6, 3, 8, 7, 11} );
                                // deklariert Feld prim und weist Werte zu

prim.at(0) = 2;         // setzt das 0. Element auf 2
prim[2] = 5;
prim.pop.back();        // !entfernt das letzte Element
prim.push.back(3);      // !fügt 3 an das Ende es Vektors an
                        // Führt zu unnötigen Kopieroperationen wenn Kapazität überschritten
                        // Speicher nach Feld belegt → neuen Speicher anfordern
                        // Wenn möglich immer mehr reservieren bzw. statischs Feld nutzen

std::cout << prim.at(n);    // liefert das n-te Element
prim.front();               // liefert das erste Element
prim.back();                // liefert das letzte Elemement

prim.empty();               // test, ob prim Werte enthält
prim.clear();               // !leert das Feld *erntet es :P*

prim.resize();              // !Ändern der Größe des Feldes
prim.size();                // liefert Größe des Feldes
prim.capacity();            // liefert maximale Größe, ohne neuen Speicher anzufragen
prim.reserve( size_t N);    // !Allokation von Speicher, ohne die Größe zu ändern
                            // ! → schreibt → nur für dynamische Felder
```

**Textfelder bzw. Zeichenketten**
```c++
std::string text;           // Feld aus Bruchstaben
text = "Hallo Welt!";
std::cout << text[0];       // liefert "H"
text.length();              // liefert Länge des Feldes
```

* Manipulation von Zeichenketten
```c++
text = "Te" + "xt";         // Verketten von Zeichenketten mittels +
text += ".";                // text = "Text."
```

* Suchen in Strings
```c++
string.find("match", 50);       // Suche Position von "match" ab Position 50
string.rfind("match");          // Suche Position von "match" rückwärts

// Suchen von einzelnen, wiederholenden Buchstaben
std::string str ("Ersetze alle e und a durch Asterisks.");
std::size_t found = str.find_first_of("ea");                // erster Durchlauf
while (found!=std::string::npos) {                          // Durchlaufen, bis zum Ende erreicht
    str[found]='*';                                         // falls gefunden → ersetzen
    found=str.find_first_of("ea",found+1);                  // weiter suchen
}
```

* Konvertierungen
```c++
text = std::to_string(5);   // Konvertierung zu String

int i = std::stoi("10.5 Hallo Welt");
int i = std::stoi(string, size_t*, base);
// Konvertierung von Str zu Int
// size_t* enthält Postition ab ersten nicht gültigen Zeichen

string → int  stoi
string → double   stod
string → long stol
```

* In c++ können *strings* wie *streams* behandelt werden
```c++
#include <sstream>
int main() {
    std::stringstream stream("42 leckere Brezeln beim Bäcker.");

    int zahl;
    std::string text;
    stream >> zahl;         // liest 42 in Variable zahl
    stream >> text;         // liest "leckere" in Text
    getline(stream, text);  // liest "Brezeln beim Bäcker."
}
```

**Durchlaufen von Feldern**
* Eigener Datentyp für Größen: `size_t`
```c++
for( size_t = 0; i < text.length(); ++i ) {
    std::cout << "Der Buchstabe an Stelle " << i << " lautet " << text[i] << "\n";
}
```

**Objekte und ihre Eigenschaften**
* Objekte haben Funktionen, mit denen der Zustand dieser angefragt werden kann
* in C++ ist der Operator `.`
  * `feld.size()` ruft die Funktion `size()` auf, des Objektes `feld` auf


### Anwendung von Feldern
**Speicherung von 1D-Feldern**
* Felder werden im Speicher als Elemente hintereinander gespeichert
* `std::array< int, 5 > x` wird als `x0|x1|x2|x3|x4` gespeichert

**Speicherung von 2D-Feldern**
* Matrizen oder Bilder
* Speicherung von Feldern, in Feldern
  * Direkte Indizierung möglich → Mathe
  * Durchlaufen aller Einträge → verschachtelte Schleifen
  * Vektoren: jede Zeile muss in der Länge gesetzt werden
* Alternativ auch linearisiert
  * Einfaches Durchlaufen aller Werte
  * Indizes müssen *manuell* berechnet werden
  * Nachbarn nicht eindeutig
  * separate Größenangaben

```c++
// Felder von Feldern
array<array<double, N>, M> A;   // Deklaration eines 2D-Feldes
A[3][1] = 5;                    // Zuweisung
A.at(3).at(1) = 5;

array<array<double, 3>, 4> A = {
    { 8.0, 20.3, 14.2 },
    { 7.6, 18.3, 12.2 },
    { 5.3, 20.1, 12.2 },
    { 1.2, 1.0,  1.1 }
};

// 2D als 1D-Feld → Linearisierung
array<double, M*N> A;
A[ 3*M + 1 ] = 5.0;
A.at( 3*M + 1 ) = 5.0;

// Vektor → Jede Zeile muss separat in der Größe gesetzt werden
std::vector< std::vector< double > > feld2d( 3, std::vector< double >( 4 ) );
// ist äquivalent zu:
std::vector< std::vector< double > > feld2d( 3 );
for( size_t zeile = 0; zeile < 3; ++zeile ) {
    feld2d.at( zeile ) = std::vector< double >( 4 );
    }
// ist äquivalent zu:
std::vector< std::vector< double > > feld2d( 3 );
for( size_t zeile = 0; zeile < 3; ++zeile ) {
    feld2d.at( zeile ).resize( 4 );
}


// Jede Zeile kann unterschiedliche Größe haben
// Dreiecksmatrix ermöglicht
    00
A=  01  11
    20  21  20
std::vector< std::vector< double > > A( 3 );
for( size_t zeile = 0; zeile < 3; ++zeile ) {
    A.at( zeile ).resize( zeile + 1 );
}
```

*PPM-Dateiformat*
```
P1
# comment
5 5
0 1 0 0 0 →  █
0 1 0 1 0 →  █ █
0 1 0 0 0 →  █
0 1 1 1 1 →  ████
0 0 0 0 0 →
```

## Objekte und Klassen
* Objekte werden aus Funktionen und Daten gebildet
* Bsp.: `std::vector< double>` ist ein Objekt
  * Funktionen verfügbar: `.size` und `.at(i)`
* Klassen in c++
  * Repräsentant eines Objektes ist eine Klasse
      * z.B. Klasse PKW, die Autos repräsentiert
  * ein Objekt ist eine Instanz einer Klasse
      * z.B. Objekt diesesAuto des Typs PKW
  * Attribute einer Klasse sind Variablen, die zur Klasse gehören
      * z.B. Attribut fahrtüchtig in der Klasse PKW
  * Methoden sind Funktionen die zur Klasse gehören
      * z.B. fahrzeughalter() in der Klasse PKW

### Eigene Datentypen
```c++
using zahlen = std::vector< int >;  // Definition von Datentyp "zahlen"
typedef std::vector< int > zahlen;  // selbiges
zahlen Primzahlen;                  // → std::vector< int > Primzahlen
Primzahlen.push_back(2);
```

### Strukturen – struct
* Aus C übernommen und Standard ist `public`
* Sammlung von Daten, ohne direkte Verknüpfung zu Funktionen
```c++
struct Student {                // Struktur Student
    std::string name;           // Vermeidung von unübersichtlicher Speicherung in Listen
    int matrikelnummer;         // Definition von allen Eigenschaften als Variablen
    int semester;               // "Bündelung" von Variablen zu neuen Datentypen
    std::string  studiengruppe;
};

Student student1;               // erstelle neuen (leeren) Student
student1.name = "Otto";         // Setze Eigenschaft Name auf "Otto"(String)
student1.matrikelnummer = 42;   // Setze Eigenschaft MN auf 42(int)

std::vector<Student> studenten; // erstelle Liste bzw. Feld von Studenten
studenten.push_back(student1);  // Füge eine Kopie von Otto zur Liste hinzu
```

### Klassen
* Beschreibt den Aufbau von Objekten gleichen Typs
* Definieren Funktionen, die mit den Objekten verbunden sind
* Attribut → Eigenschaft von Objekt bzw. Objektvariable
  * Variablen, die die Klasse beschreiben
  * Stehen zum Objekt in einer *hat-*, *hat ein-* oder *besteht aus-Beziehung*
* Klasse:   Student
* Instanz:  RainerFunden, MaxMustermann
* Methode:  Student::erhoeheStudiensemester(int)
  * Funktionen, die zu der Klasse direkt gehören

**Erstellen von Klassen**
* Zur Verwendung ist Speicherung und Implementierung egal
* Nur der Zugriff auf die Klasse ist interessant
  * Funktion zum Zugriff in `public` → *Interface*
* Funktionen und Klassen werden bei der Definition *nicht ausgeführt*
* Instanzen können auch als konstant deklariert werden, um das Schreiben zu unterbinden

**Konstruktoren**
* Erzeugung eines Typs einer Klasse durch aufrufen des **Konstruktors**
  * Definition in `public`
  * gleicher Name wie die Klasse
  * kann beliebig viele Argumente haben
  * kann überladen werden → Konstruktoren mit unterschiedlichen Argumentenlisten
  * *kein* Rückgabetyp
* Zerstörung eines Typs einer Klasse durch aufrufen des **Destruktors**
  * Aufruf, wenn das Objekt den Definitionsbereich verlässt
  * *explizites* Aufrufen durch `delete Objektname;`
  * Name: `~Klassenname`
  * darf *keine* Argumente haben (wird automatisch aufgerufen)
  * ebenfalls *kein* Rückgabetyp
  * explizite Freigabe von Speicher (wenn nötig)
  * explizites Abmelden von einem Objekt aus dem System

**Sichtbarkeit und Aufbau**
* Klassen sind standardmäßig `private`
```c++
class Klassenanme {
public:
    // Öffentlich → für jeden sichtbar
    // IdR. Methoden zum Lesen und Schreiben (aus/in private)
protected:
    // Geschützt → nur für abgeleitete Klassen sichtbar
private:
    // Privat → nur für Klasse selbst sichtbar
    // IdR. Attribute

    friend class andereKlasse;
    // andereKlasse darf auf private zugreifen
};
```

* Studenten Beispiel
```c++
class Student {
public:
    void setName(std::string neuerName) {   // Überprüfung, dass nur sinnvolle Daten vorkommen
        if(neuerName != "")
            name = neuerName;
    }

    void setSemester(int i) {
        if(i > 0)
            semester = i;
    }

    int getSemester() {                     // Ausgabe von Werten über Methode möglich
        return semester;
    }

private:
    std::string name;
    int martrikelnummer;
    int semester;
    std::string studiengruppe;
};

Student sudente;
studente.name = "Otto";         // Nicht möglich, da "name" in private
studente.setName("Otto");       // Führt Methode setName aus

const Student RainerFunden;     // Konstanter Student
RainerFunden.setSemester(3);    // Fehler, da RainerFunden konstant ist
```

**Statische Funktionen**
* Funktionen können statisch seien, wenn sie vom Objekt unabhängig sind

```c++
class Student {
public:
    static constexpr int ECTSinH = 30;
    stdatic int ects2h(int ects) {
        return ects * ECTSinH;
    }
};

Student nummerEins;
std::cout << nummerEins.ects2h(1) << '\n';  // Aufruf mit Objekt
std::cout << Student::ects2h(1) << '\n';    // Selbiges, ohne Objekt
```

**Zählen von Objekten**
```c++
class CountedClass {
    static int counter; // Definition des Zählers
public:
    CountedClass() {    // Aufruf beim Erstellen → Konstruktor
        counter++;
    }
    ~CountedClass() {   // Aufruf beim Zerstören → Destruktor
        counter--;
    }
};

int CountedClass::counter = 0;  // Zähler wird initialisiert

int main() {
    // CountedClass::counter = 0
    CountedClass a;             // CountedClass::counter = 1
    {
        CountedClass b;         // CountedClass::counter = 2
        CountedClass c;         // CountedClass::counter = 3
    }
    // CountedClass::counter = 1, da Objekte ihre Gültigkeit verloren haben
}
```

**Komplexe Zahlen Beispiel → Konstruktorfunktion**
```c++
class Komplex {
public:
    Komplex() {                     // Standardkonstruktor → Aufruf ohne Parameter
        real = 0.0;
        imag = 0.0;
    }
    Komplex(double r, double i) {   // Konstruktor → Aufruf mit Parameter
        real = r;
        imag = i;
    }

    void set(double r, double i) {
        real = r;
        real = i;
    }
    double getReal() const {        // Ruft Realteil ab → liest nur (const)
        return real;
    }
    double getImag() const {        // Ruft Imaginärteil ab → liest nur (const)
        return imag;
    }


    Komplex add(Komplex rhs) {      // Memberfunktion zum addieren a.add(b) = c
        Komplex result;
        result.set(real + rhs.getReal(), imag + rhs.getImag()); // RightHandSide
        return result;
    }

    Komplex add2(Komplex lhs, Komplex rhs) {
        Komplex result;
        result.set(lhs.getReal() + rhs.getReal(), lhs.getReal + rhs.getImag());
        return result;
    }

    static Komplex add3(Komplex lhs, Komplex rhs) {
        Komplex result;
        result.set(lhs.getReal() + rhs.getReal(), lhs.getReal + rhs.getImag());
        return result;
    }

private:
    double real;
    double imag;
};

// Überladen von Operatoren (Beste Option für Mathe; mit allen Operatoren möglich → siehe String)
Komplex operator+(Komplex lhs, Komplex rhs) {
    Komplex result;
    result.set(lhs.getReal() + rhs.getReal(), lhs.getReal + rhs.getImag());
    return result;
}

// Definition als globale Funktion (zu vermeiden aber vertretbar)
Komplex add2(Komplex lhs, Komplex rhs) {
    Komplex result;
    result.set(lhs.getReal() + rhs.getReal(), lhs.getReal + rhs.getImag());
    return result;
}


Komplex sum1    = add(a, b);            // globale Funktion
Komplex sum2    = a + b;                // Operatorüberladung
Komplex sum3    = a.add(b);             // Memberfunktion
Komplex sum4    = a.add2(a,b);          // Memberfunktion in schrecklich
Komplex sum5    = z.add2(a,b);
Komplex sum6    = Komplex::add3(a,b);   // Memberfunktion (static) in nicht ganz so schrecklich
                                        // sollte dennoch vermieden werden…
```

**Vererbung bzw. abgeleitete Klassen**
* *ist ein-Beziehung*
* Objekte stehen oft untereinander in Beziehung
  * Jeder PKW ist ein Fahrzeug, d.h. er hat die Eigenschaften eines Fahrzeuges
  * Jeder LKW ist auch ein Fahrzeug, d.h. er hat die Eigenschaften eines Fahrzeuges
  * PKW und LKW haben aber zueinander unterschiedliche Eigenschaften
  * Ein LKW hat z.B. einen Laderaum und ein dazugehöriges Ladevolumen ein Fahrrad nicht, obwohl es ein Fahrzeug ist
  * `PKW` *erbt* von `Fahrzeug`
      * `PKW` besitzt gleiche Attribute und Methoden wie `Fahrzeug`
      * `PKW` ist die *abgeleitete Klasse*
      * `Fahrzeug` ist die *Basisklasse* bzw. *Base Class*
      * `PKW` ist ein *Untertyp* von `Fahrzeug` wenn `PKW` überall dort eingesetzt werden kann, wo `Fahrzeug` erwartet wird
* abstrakte Methoden sind Funktionen, die von abgeleiteten Klassen überschrieben werden und in der Basisklasse nicht implementiert werden
* abstrakte Klassen sind Klassen, die abstrakte Methoden enthalten
  * können nicht erzeugt werden
* Vererbung kann verhindert werden, in dem man die Klasse als `final` markiert

```c++
class Fahrzeug {            // allgemeine Fahrzeugklasse (Basisklasse)
public:                     // Eigenschaften, die jedes Fahrzeug hat
    void setV(double v);
    void setA(double a);
    double getV();
    virtual bool getSchneeAufDach();        // Funktion darf in abgeleiteten Klassen überschrieben werden
    virtual bool getSchneeAufDach() = 0;    // Selbiges; Funktion ist in der Basisklasse nicht implementiert
    virtual bool motorFunktioniert();       // → abstrakte Methoden

// Attribute
    std::vector<Reifen> reifen;
};


class LKW : public Fahrzeug // LKW ist eine Erweiterung (Vererbung) von Fahrzeug
{                           // LKW erbt alle Funktionen und Eigenschaften von Fahrzeug
    double ladeVolumen;     // z.B. setV(), getV(), reifen…
};

class PKW : public Fahrzeug // PKW ist ein Fahrzeug und erweitert diese Klasse nicht
{                           // (abgeleitete Klasse)
};

class Fahrrad final : public Fahrzeug               // Unterbindet Erstellung von abgeleiteten Klassen
    double bool getSchneeAufDach() override const { // Wir überschreiben bewusst die Methode (kein Fehler)
        return false;
    }
    double bool getSchneeAufDach() final {          // Wir überschreiben bewusst die Methode und abgeleitete Klassen
        return false;                               // dürfen diese nicht überschreiben
    }
};


void fnkt1(LKW lkw) {
    // berechne Ladung aus Ladevolumen, etc.
}
void fnkt2(Fahrzeug fahrzeug) {
    std::cout << fahrzeug.getV();   // Darf sich nur auf Fahrzeug, nicht auf PKW/LKW beziehen
}

LKW brummi;
fnkt1(brummi);  // Rufe Funktion, die Typ LKW erwartet auf
fnkt2(brummi);  // Rufe Funktion, die Typ Fahrzeug erwartet auf

PKW smarti;
fnkt1(smarti);  // Fehler, da fnkt1 Typ LKW erwartet
fnkt2(smarti);  // Ok, da Klasse PKW von Fahrzeug erbt und smit die Eigenschaften
                // eines Fahrzeuges beseitzt
```

* Konstruktoren können auch *"vererbt"* werden
* Destruktoren ebenso
  * Überladen sinnvoll, da eventuell Destruktor der übergeordneten Klasse aufgerufen wird
  * dann in abgeleiteter Klasse definieren mit `virtual ~KlassenName() {`

siehe Komplex
```c++
class neuKomplex : Komplex {
    neuKomplex(double r, double i, double skalar)   // Konstruktor von neuKomplex
    : Komplex(r, i) {                               // Rufe Konstruktor von Kompex mit Parametern auf
        // ...                                      // Konstruktor von neuKomplex
    }
```

### Aufteilung in Dateien
**Header Student.hpp**
* Beschreibung von Objekten und wie diese gespeichert sind
* Definition von Klassen und allgemeine Definitionen
```c++
#pragma once                // Sicherstellen, dass diese Datei 1x
                            // pro Kompiierungseinheit gelesen wird
#include <something>

class Student {
public:
    std::string getName();
private:
    std::string vorname;
    std::string nachname;
};
```

**Source Student.cpp**
* Implementierung der Klasse / der Funktionen
```c++
#include "Student.hpp"  // Definition von Studentklasse

Student::Student() {    // Konstruktor
    / …
}

Student::~Student() {   // Destruktor
    / …
}

std::string Student::getName() {
    return nachname + ", " + vorname;
}

extern int a;               // Jedes einbindende Programm hat Zugriff auf a (global)
                            // Deklatarion, ohne Definition
```

**Source main.cpp**
* Hauptprogramm
* Es werden nur `.hpp` (header) eingebunden *keine* `.cpp`
```c++
#include "Student.hpp"

int main() {
    Student RainerFunden;
    std::cout << RainerFunden.getName();

    int a;                              // a wird definiert (siehe oben)
}
```

**Kompilierung**
* *In einem Rutsch*
  * `clang++ main.cpp Student.cpp`
  * `g++ -o programm main.cpp Studend.cpp`
* Einzeln (bei größeren Programmen)
  * Erneute Kompilierung von Programmteilen möglich
  * `g++ -c Student.cpp` Erzeugt `student.o`
  * `g++ -c main.cpp` Erzeugt `main.o`
  * `g++ -o programm student.o main.o` Binden zu `programm`

## Pointer (Zeiger)
* Pointer sind Zeiger, die auf bestimmte Speicherstellen zeigen
* Sie zeigen auf die erste Speicherstelle eines Objekts
* Kennzeichnung durch `*` nach dem Datentyp
  * `int* ptr` bedeutet, dass `ptr` ein Zeiger ist, der auf die Speicherstelle einer Ganzzahl zeigt
  * `*ptr` verweist auf den Wert an der Speicherstelle, auf die `ptr` zeigt
  * `ptr` bzw. `&a` verweist auf die Speicherstelle von dem Zeiger `ptr` bzw. der Variable `a`
  * `nullptr` ist der *Null Pointer* → bewusst nicht gültiger Wert `0L`
* Die Adresse, auf die der Zeiger zeigt, muss nicht sinnvoll sein und wird nicht überprüft
* Referenzen sind Zeigern zu bevorzugen
  * Referenzen sind neue Namen für vorhandene Objekte und belegen keinen Speicher
  * Zeiger benötigen so viel Speicher, dass der gesamte Speicher adressiert werden kann

```c++
Datentyp *variablenname;    // erstellen eines Zeigers, der auf ein Objekt vom Typ Datentyp verweist
new Datentyp(parameter);    // erzeugt Objekt vom Datentyp Datentyp auf dem Heap
                            // gibt eine Speicheradresse zurück → Speicherung möglich
variablenname;              // gibt Speicherstelle des Objektes zurück
*variablenname;             // Dereferenzierung → Objekt an Speicherstelle
(*variablenname).length();  // Funktionsaufruf mit Wert (wenn aus Klasse)
vaiblenname->length();      // Selbiges in übersichtlich

int a;
&a;                         // gibt Speicheradresse von a zurück
int* b= &a;                 // Zeiger b verweist auf Speicherstelle von a
(*b) = 1;                   // Zugriff auf Objekt a

int *z;
z = new int;                // lege Objekt vom Typ int auf dem Heap an
int *b = a;                 // b zeigt auf Speicherstelle von dem Objekt von a
a = new int;                // b verweist noch auf das alte a
a = b;                      // a verweist wieder auf altes a (bzw. b)
```

### Variablen auf dem Heap
* Schlüsselwort `new` bedeutet, dass ein neues Objekt auf dem *Heap* erzeugt wird
  * Objekt ist *anonym* bzw. es muss keiner Variablen zugewiesen sein
  * Objekt bleibt im Speicher, selbst es „den Gültigkeitsbereich verlässt“
  * bisherige Objekte liegen auf dem Stack (wessen Größe vom Compiler beschränkt ist)
      * ebenso fester Gültigkeitsbereich, feste Größe
* Löschen durch `delete` → gibt angefragten Speicher wieder frei
  * Unbedingt notwendig (bei Klassen im Destruktor)

```
       +-----------+            int c;
int  c |   Wert1   |            int* a = &d;
       +-----------+            int* b = new int;
int* a |Adresse  * |-----+
       +-----------+     |      "Umbiegen" des Zeigers
int* b |Adresse  * |---+ |      b = a;
       +-----------+   | |      → b zeigt jetzt auf a
       |    etc    |   | |      → b zeigt auf d
       +-----------+   | |
       |   Wert2   | <-+ |      Pointer belegen Speicher!
       +-----------+     |
int  d |   Wert3   | <---+
       +-----------+
```

**Felder mit Zeigern**
* `double *data = new double[i];` wie `std::vector`
  * fragt Speicher für i Objekte des Typs `double` an
* `data++` rückt den Zeiger um ein double-Wert weiter
  * dabei wird um `sizeof(double)` weiter gerückt
* `delte[] data` löscht alle Werte

* `double data[i];` ist *nicht* nach C++-Standard
* `double data[8];` ist ok, da ein statisches Feld erzeugt und automatisch geräumt wird

### Verwendung von Zeigern
#### Design-Pattern Factory Beispiel
* Negativbeispiel (Warum Pointer?)
```c++
class Fahrzeug {...};
class Fahrrad : public Fahrzeug {...};
class PKW : public Fahrzeug {...};

class Fabrik {                          // allgemeine Fabrik
public:
    virtual Fahrzeug Fahrzeug() = 0;    // Rückgabe von allgemeinen Fahrzeug (Typ Fahrzeug)
};                                      // Funktion wird Überschrieben (ist abstrakt)

class FahrradFabrik : public Fabrik     // Fahrradfabrik, als spezielle Fabrik, die erbt
{
public:
    Fahrzeug neuesFahrzeug() {          // gibt Fahrzeug, vom Typ Fahrrad zurück
        return Fahrrad();
    }                                   // Fahrrad verlässt Gültigkeitsbereich → wird gelöscht
};

class AutoFabrik : public Fabrik        // Autofabrik, als spezielle Fabrik, die erbt
{
public:
    Fahrzeug neuesFahrzeug() {          // gibt Fahrzeug, vom Typ PKW zurück
        return PKW();
    }
};


Fabrik f;                               // allgemeine Fabrik
Fahrzeug fahrzeug = f.neuesFahrzeug();  // erstelle ein neues Fahrzeug, vom Typ Fahrzeug
Fahrrad fahrzeug = f.neuesFahrzeug();   // erstelle ein neues Fahrrad, vom Typ Fahrrad
Fahrzeug& fahrzeug = f.neuesFahrzeug(); // Erstelle Referenz auf fahrzeug
```

* Problem: Wenn ein Fahrrad erzeugt werden soll, also wenn die Fabrik eine Fahrradfabrik ist, wird dennoch ein allgemeines Fahrzeug zurückgeliefert
  * Fahrrad müsste gleiche Speicherstruktur, wie Fahrzeug haben (wird in Fahrzeug umgewandelt)
  * in Fahrzeug nicht vorhandene Attribute entfallen
* Festlegen des Typs (`Fahrrad fahrzeug`) ist nicht möglich, da der Rückgabetyp der Fabrik nicht bekannt ist
* Referenzen sind ebenfalls nicht praktikabel, da der Gültigkeitsbereich verlassen wird und somit das Originalobjekt nicht mehr existiert

* Lösung mit Zeigern
```c++
class Fabrik {
public:
    virtual Fahrzeug* Fahrzeug() = 0;
};

class FahrradFabrik : public Fabrik
{
public:
    Fahrzeug* neuesFahrzeug() {         // erzeuge ein neues Objekt auf dem Heap
        return new Fahrrad();           // und übergebe die Speicheradresse
    }
};

class AutoFabrik : public Fabrik
{
public:
    Fahrzeug* neuesFahrzeug() {
        return new PKW();
    }
};

FahrradFabrik f;
Fahrzeug* fahrzeug = f.neuesFahrzeug;
```

#### Vektoren
```c++
class Vektor {
public:
    Vektor(unsigned int size) {     // Erzeuge size Werte auf dem Heap (Feld)
        data = new double[size];    // speichere die Adresse des ersten in data
                                    // alle anderen Einträge liegen hinter data im Speicher
    }
    ~Vektor() {                     // Destruktor
        delte[] data;               // löscht das Feld data
    }

    double at(unsigned int i) {     // ruft Wert an Stelle i auf (Fehlerbehandlung notwendig)
        return data[i];             // gehe von data i double-Stellen weiter
        return*(data + i);          // Selbiges nur besser ;)
    }

    // etc.

private:
    double *data;                   // der Zeiger data liegt auf dem Stack
};

Vektor a(10);   // erstelle neuen Vektor
a.at(0);        // Eintrag von a an erster Stelle
a.at(1);        // Eintrag von a an zweiter Stelle
```

#### Einfach Verkettete Listen
* Datenstruktur, wobei jedes Element *einen Verweis auf den Nachfolger* enthält
* Einfügen bzw. Löschen am Anfang sind einfachste Operationen
* Zugriff bzw. Operationen mit dem letzten Element einfach umzusetzen aber eventuell zeitaufwendig
  * Schleife notwendig

* Stack (Stapel): vorne hinzufügen bzw. wegnehmen
* Queue (Warteschlange): hinten hinzufügen bzw. wegnehmen

```
         +----+     +----+     +----+     +----+     +----+
HEAD  +->|DATA|  +->|DATA|  +->|DATA|  +->|DATA|  +->|DATA|
+--+  |  +----+  |  +----+  |  +----+  |  +----+  |  +----+
| *|--+  |   *|--+  |   *|--+  |   *|--+  |   *|--+  |NULL|
+--+     +----+     +----+     +----+     +----+     +----+
```

```c++
class Element {
public:
    double data;
    Element* next;
};

class Liste {
public:
    Liste() {                               // Konstruktor
        head = nullptr;                     // erdeute leere Liste
    }    
    ~Liste() {                              // Destruktor
        while( !empty() ) {                 // Solange Liste nicht leer, entferne erstes Element
            pop_front();
        }
    }
        
    void push_front( double wert ) {        // An Anfang anfügen
        if( !head ) {                       // falls Liste leer (head == nullptr)
            head = new Element;             // neues Element anlegen
            head->data = wert;              // Daten von Element auf wert setzen
            head->next = nullptr;           // Nachfolger auf nullptr setzen
        } else {
            Element* temp = new Element;
            temp->data = wert;
            temp->next = head;              // Lass neues Element auf alten head zeigen
            head = temp;                    // Lass head auf neues Element zeigen
        }
    }

    void pop_front() {                      // Entfernt das erste Element
        if( head ) {                        // wenn Liste nicht leer
            Element *temp = head;           // Kopiere head
            head = head->next;              // Setzte head auf zweiten Eintrag
            delete temp;                    // lösche alten head
        } else {
            // Fehler ausgeben
        }
    }

    void pop_back() {                       // Entfernt das letzte Element
        Element* temp = head;
        while( temp->next->next ) {         // Solange next gültig ist, gehe weiter
            temp = temp->next;              // beim Listenende ist temp-> next == nullptr
        }                                       // suche vorletztes Element
        delete temp->next;                  // dann lösche das letzte Element
        temp->next = nullptr;               // setzte next vom Vorletzten auf nullptr
    }

    void push_back( double d ) { ... }

    bool empty() {                          // prüft, ob die Liste leer ist
        return head == nullptr;
    }

    double at( int i ) {                    // gibt Element an der i-ten Stelle aus
        Element* temp = head;
        for( int z = 0; z < i; ++z ) {      // Solange temp gültig ist, gehe weiter
            if( temp ) {
                temp = temp->next;
            }
        }
        if( temp ) {                        // wenn temp gültig ist, gebe Daten zurück
            return temp->data;
        } else {
            // Fehler ausgaben
        }
    }

    void ausgabe() const {                          // Debugfunktion
        std::cout << "===================\n";           // Trennung
        std::cout << "head: " << head << "\n";          // Listenkopf
        Element* temp = head;
        while( temp ) {                                 // gehe ganze Liste durch; für jedes Element:
            std::cout << "addr: " << temp << " ";           // gebe Adresse aus
            std::cout << "data: " << temp->data << " ";     // gebe Daten von Element aus
            std::cout << "next: " << temp->next << "\n";    // gebe Nachfolgeradresse aus
            temp = temp->next;
        }
        std::cout << "===================\n";           // Trennung
    }
        
private:
    Element *head;
};


int main()
{
    Liste liste;
    liste.ausgabe();
    liste.push_front(3);
    liste.push_front(2);
    liste.ausgabe();
}
```

**Verbesserungen**
* `tail` in Listenklasse als Attribut speichern
* „Rückverbindungen“ zum Vorgänger speichern → Schleifen fallen weg

## Fehlerbehandlung und Ausnahmen
* Programm wird nach Spezifikation geschrieben, welche einen Teil der möglichen Eingaben abdeckt
* Es muss entschieden werden, was im Fehlerzustand passiert
  * Manchmal ist es sinnvoll, den Kontrollfluss kontrolliert zu verlassen → **Ausnahme**
  * der Fehler kann auch ignoriert werden (fehleranfällig)
  * Fehlerwert implementieren (aufwendig)

### Definitionen
**Korrektheit**
* Eigenschaft eines Systems, die Anforderungsspezifikation vollständig zu erfüllen
* Ein System ist korrekt, wenn es die explizit spezifizierten Anforderungen erfüllt

**Zuverlässigkeit**
* Fähigkeit eines Systems (aus Hard- und Software), in einer gegebenen Zeitspanne unter zulässigen Betriebsbedingungen, das spezifizierte Verhalten zu erbringen

**Robustheit**
* System reagiert vernünftig auf Eingaben, die nicht in der Anforderungsspezifikation erfasst sind

### Ausnahmen
* Tritt eine Ausnahmesituation auf, so kann eine Ausnahme (*exception*) geworfen (*throw*) werden
* verlässt Kontrollfluss an der Stelle, an der das Ausnahmeobjekt geworfen wird
* Fangen (*catch*) der Ausnahme führt zum fortsetzen an der Stelle des Fanges
  * nicht gefangen → beenden

**Aufbau**
```c++
try {
    // ...
    // wird bis hierher normal ausgeführt
    // bis Ende durch return- bzw. break-Anweisung
    throw std::runtime_error( "Laufzeitfehler" );
    // ab hier wird nicht mehr ausgeführt
    // ...
}

catch( std::out_of_range& e ) {
    // Behandung von Ausnahmen, des Typs std::out_of_range
}

catch( std::runtime_error& e ) {
    // Behandung von Ausnahmen, des Typs std::runtime_error
}

catch(...) {
    std::cerr << "Fehler \"" << e.what() << "\" aufgetreten." << std::endl;
    throw; // wirft e weiter
}
```

**Beispiel**
```c++
class KleinerNull {};                   // Kann leer sein

double Wurzel(double a) {   <───╮
    if(a < 0) {                 │
        throw KleinerNull();    │
    }                           │
    return a;   ────────────────┼───╮
}                               │   │
int main() {                    │   │
    double a = +1;              │   │
    try {                       │   │
        double b = Wurzel(a);  ─╯ <─╯
        std::cout << "sqrt: " << a;
    } catch(KleinerNull& ausnahme) {    ────────╮
        std::cout << "KleinerNull-Ausnahme";    │
    }   <───────────────────────────────────────╯
}
```
```c++
class KleinerNull {};                   // Kann leer sein

double Wurzel(double a) {   <───╮
    if(a < 0) {                 │
        throw KleinerNull(); ───┼───╮   
    }                           │   │
    return a;                   │   v
}                            ───┼───╮
int main() {                    │   │
    double a = -1;              │   │
    try {                       │   │
        double b = Wurzel(a);  ─╯   │
        std::cout << "sqrt: " << a; │
    }                               │
    catch(KleinerNull& ausnahme){ <─╯
        std::cout << "KleinerNull-Ausnahme";
    }
}
```

#### Klassenhierarchie der Ausnahmen der Standardbibliothek
`std::exception`
* `std::logic_error` *Programmlogikfehler*
  * `std::invalid_argument`
  * `std::domain_error`
  * `std::length_error`
  * `std::out_of_range`
  * `std::future_error` (C++11)
* `std::runtime_error` *Laufzeitfehler*
  * `std::range_error`
  * `std::overflow_error`
  * `std::underflow_error`
* `std::system_error` (C++11)
  * `std::ios_base::failure` (C++11)

Wird `std::runtime_error` gefangen, so werden auch alle Unterklassen davon gefangen.

**Laufzeitfehler**
* machen Software weniger robust
* Fehlerhafte Buntziereingaben
* fehlende bzw. fehlerhafte Dateien
* Zu wenig Speicher

**Programmlogikfehler**
* in der Regel Programmierfehler
* Zugriffe auf ungültigen Speicher bzw. Elemente außerhalb Reichweite
