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
    int       a =         3;
//  Datentyp  Bezeichner  Literal → Variable
//            L-Wert      R-Wert
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
double d;           // deklariert aber nicht initialiert
double e = 1.0;     // reserviert Speicher und initialisiert ihn mit dem Wert 1
double f( 1.0 );
double g{ 1.0 };    // deklariert und initialisert, Prüfung auf Richtigkeit beim kompilieren
double i = double();// reserviert Speicher und initialisiert ihn mit dem Wert 0
double j{};         // reserviert Speicher und initialisiert ihn mit dem Wert 0
```

**Konstanten**
```c++
double d{ 1.0 };              // defiert d und setzt den Wert von d auf 1.0
                              // d kann im Programm verändert werden
contexpr double e{ 0.5/3.1};  // e ist ein konstanter Ausdruck und nach Definition nicht veränderbar
const double f{ 0.5/3.1 };    // f ist eine Konstante, die nach dem kompilieren konstant ist
constexpr double g{ f };      // in Ordnung, da ableitbar
```

**Statische Variablen**
```c++
void f(int a, int b) {
  static int n = 0; // beim ersten Funktionsdurchlauf: definiert und setzt n auf 0
  // …              // bei folgenden Aufrufen: wird n vom vorhergehenden Aufruf verwendet
}                   // für Rekursion nützlich (siehe Hanoi)
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
enum class Ampelfarbe { Rot, Gruen }; // Neuer Datentyp wird definiert
Ampelfarbe ampel1 = Ampelfarbe::Rot;  // Variablen können nur Rot und Gruen annehmen
if( anfrageVonFussgaenger ) {
  ampel1 = Ampelfarbe::Gruen;
}
```
* Interne Speicherung als Ganzzahl
```c++
enum class Ampelfarbe { Rot = 0, Gruen = 1};  // Explizite Zuweisung
```

###Typumwandlungen
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
    * `std::cout << std : : setw ( 4 ) << 1 ;` gibt `   1` aus
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
  std::ofstream fileOut("test.txt") // Anlegen einer Variable mit Dateinamen als Argument
                                    // → öffnen der Datei
  if( fileOut ) {                   // falls die Datei schreibbar ist
    fileOut << "Hallo Welt"         // schreibt "Hallo Welt" in die Datei
  }
}                                   // Ende des Blockes, fileOut verliert Gültigkeit
                                    // Resource wird freigegeben; Datei geschlossen
```

### Namensräume
* `std` ist der Namensraum der Standardbibliothek
* Namensräume werden mit `::` von Variablen abgetrennt
  * `using namespace std;` setzt `std` als Standard *nicht empfohlen*
  * `using std::cout;` ermöglicht partielle Nutzung
  * `std::cout << a` → `cout << a`
* Eigene Namensräume erstellen
```c++
namespace htwk {            // Deklaration eines eigenen Namensraums
  const int dozenten{ 1 };  // Variable im Namensraum
  const int studenten{ 2 };
  namespace info {          // Verschachtelung möglich
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
int a = 5;    // Deklaration einer globalen Variable
int main() {
  // …
  int b = a;  // Die Variable ist überall gültig
  // …        // und kann nicht neu definiert werden
}
```

### if, else und der geschleifte Spaß
* Fallunterscheidung (wahr oder falsch)
```c++
if( … ) {   // wenn …
  // …      // dann …
} else {    // sonst …
  // …      // optional
}
```
* Fallunterscheidung
```c++
switch( … ) {       // Unterscheidung anhand von …
  case 1:           // Fall, dass Wert == 1
    // …            // dann
    break;          // beendet Ausführung des switch-Blocks
  case 'b':         // zulässig char
    // …
    break;
  case farbe::blau: // zulässig enum
  case farbe::gelb: // wenn einer übereinstimmt
  case farbe::cyan: // dann
    // …
    break;
  default:          // falls kein anderer Fall eintritt
    // …
}
```
* Schleifen
  * `break;` Sofortiger Abbruch der nächstäußeren switch/while/do-while/for-Anweisung
  * `continue;` Abbruch der aktuellen und sofortiger Start des nächsten Zykels einer while/do-while/for-Anweisung
```c++
while( … ) {    // Kopfgesteuerte Schleife
  // …          // Solange …
}               // tue …

do{             // Fußgesteuerte Schleife
  // …          // wird mindestens 1x ausgeführt
} while( … );

// Zählschleife
for (int i; i < 100; ++i) {
  // …
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

double Quadrat( double x);    // Deklaration einer Funktion, die einen double-Wert
                              // zurückgibt und einen als Eingabe nimmt (x)
double Quadrat( double x) {   // Implementierung bzw. Definition
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
 */
double wurzel( double c, unsigned int n = 20 ) {
  // …
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
    // Löse den einfachsten Fall          // (mehere möglich)
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
  } else // ( a < b )
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
std::array< int, 10 >       feld;
Datentyp  Templateparameter Variablenname
          Inhaltstyp, Größe
                            //definiert ein statisches Feld der Länge 3
std::array< int, 10 > feld = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
                            // deklariert das Feld feld, vom Typ int mit 10 Elementen
int feld[10] = {…}          // veraltet

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

prim.at(0) = 2;     // setzt das 0. Element auf 2
prim[2] = 5;
prim.pop.back();    // !entfernt das letzte Element
prim.push.back(3);  // !fügt 3 an das Ende es Vektors an
                    // Führt zu unnötigen Kopieroperationen wenn Kapazität überschritten
                    // Speicher nach Feld belegt → neuen Speicher anfordern
                    // Wenn möglich immer mehr reservieren bzw. statischs Feld nutzen

std::cout << prim.at(n);  // liefert das n-te Element
prim.front();             // liefert das erste Element
prim.back();              // liefert das letzte Elemement

prim.empty();             // test, ob prim Werte enthält
prim.clear();             // !leert das Feld *erntet es :P*

prim.resize();            // !Ändern der Größe des Feldes
prim.size();              // liefert Größe des Feldes
prim.capacity();          // liefert maximale Größe, ohne neuen Speicher anzufragen
prim.reserve( size_t N);  // !Allokation von Speicher, ohne die Größe zu ändern
```

**Textfelder bzw. Zeichenketten**
```c++
std::string text;     // Feld aus Bruchstaben
text = "Hallo Welt!";
std::cout << text[0]; // liefert "H"
text.length();        // liefert Länge des Feldes
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
array<array<double, N>, M> A; // Deklaration eines 2D-Feldes
A[3][1] = 5;                  // Zuweisung
A.at(3).at(1) = 5;

array<array<double, 3>, 4> A = {
  { 8.0, 20.3, 14.2 },
  { 7.6, 18.3, 12.2 },
  { 5.3, 20.1, 12.2 },
  { 1.2, 1.0,   1.1 }
};

// 2D als 1D-Feld → Linearisierung
array<double, M*N> A;
A[ 3*M + 1 ] = 5.0;
A.at( 3*M + 1 ) = 5.0;

// Vektor → Jede Zeile muss sepatat in der Größe gesetzt werden
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
