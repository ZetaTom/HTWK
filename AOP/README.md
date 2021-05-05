# Anwendungsorientierte Programmierung – Java (Sprich Tschahwah)

## Konventionen
* Bezeichner für Klassen und Packages beginnen mit Großbuchstaben
* Bezeichner für Variablen und Funktionen bzw. Methoden beginnen mit Kleinbuchstaben
* *camelCase* ist üblich zur Strukturierung


## Datentypen
Typ|Wertebereich|Größe|Format
---|------------|-----|------
byte|-128..+127|8 Bit|Zweierkomplement
short|-32.768..+32.767|16 Bit|Zweierkomplement
int|-2.147.483.648..+ 2.147.483.647|32 Bit|Zweierkomplement
long|-263..+263-1|64 Bit|Zweierkomplement
float|+-1,40239846E-45..3,40282347E+38|32 Bit|IEEE 754
double| |64 Bit| IEEE 754
boolean|true oder false|nicht def.|
char|Unicode (Numerisch)|16 Bit|16-Bit-Unicode

**Notation in Java**
* `123` Dezimal, `0B10` bzw. `0b10` Binär, `0123` Oktal, `0xFFFF_FFFF` Hexadezimal
* `1233L`, `0b11l` als Long-Literal
* `12.3f`, `1e-1f`, `4.0E+5F` float
* `1.0`, `2D` double
* `'a'`, `'\0041'` `\u4EBA'` char
  * `\n` etc. funktioniert wie erwartet

**Wrapper-Datentypen**
Wrapper-Datentyp|primitiver Datentyp
----------------|-------------------
Byte            |byte
Short           |short
Integer         |int
Long            |long
Float           |float
Double          |double
Boolean         |boolean
Character       |char

Zur Konvertierung von Datentypen vorgesehen: `double x = Double.valueOf("3.1415962");`

**Strings – Zeichenketten**
* *String* ist eine Klasse
* Bsp.: `"blub."` und `"Ich\nbinn\b\n\tein\n\t\tString.\a"`
* Verkettung möglich `"3 × 3 macht" + " neune"`


## Ausdrücke und Schleifen
* Sichtbarkeitsregeln wie in c++
* Java führt automatische Garbage-Collection durch --> manuelles Löschen nicht notwendig

**Ein- und Ausgabe**
```java
public class InOutExample {
    public static void main(String[] args) {
        Scanner input;
        int read = 0;
        input = new Scanner(System.in);
        System.out.print("Eingabe: ");
        try {
            read = input.nextInt();
            System.out.println("Du hast " + read + " eingegeben.");
        } catch (java.util.InputMismatchException e) {
            System.out.println("Böse!");
            input.reset();
        }
        input.close();
    }
}
```
Java ist standardmäßig lokalisiert. D.h. Eingabe von z.B. Kommazahlen mit „3,14“.
Um die Eingabe mit „.“ zu ermöglichen muss die Lokalisierung geändert werden.
```java
input.useLocale(Locale.UK);
```

**Schleifen**
```java
while(bool'scher Ausdruck!)
    //eine einzelne Anweisung

while(bool'scher Ausdruck!) {
    // 1.
    // 2.
    if(...) {
        continue;               // Springe zum Schleifenkopf
        continue[Label];        // Ausführung wid bei Label fortgesetzt
        break;                  // Breche innerste Schleife ab
        break[Label];           // Breche ab un setze bei Label fort
    }
}

do {
    // Block wird min. 1x ausgeführt
} while (kaesekuchen > 0);

int sum = 0;
for(int i = 1; i <= 10; i++) {
    sum += i;
}
```

**Switch-Cases**
```java
switch (Ausdruck) {     // Konstante (String, Char, Byte, Int, etc.)
    case Marke1:
        //blub          // Im 1. Fall
        break;          // Restliche Fälle nicht betrachten
    case Marke2:
    case Marke3:
        //blub          // Im 2. und 3. Fall
        break;          // Restliche Fälle nicht betrachten
    default:
        //...           //Standardfall
}
```

### Operatoren
Zeichen|Beschreibung
-------|------------
~|bitweises Komplement
&|bitweises UND
\||bitweises ODER
^|bitweise Antivalenz
\<\<|Schieben links
\>\>|log. Schieben rechts
\<\<\<|arith. Schieben rechts
\=|Zuweisung
+=|Zuweisung mit Addition
-=|Zuweisung mit Subtraktion

## Felder
```java
// 1D Feld – Zusammenfassung gleichartiger Daten
String[] blub = {"Java", "ist", "eine", "Programmiersprache"};
for(String wort : blub)                 // For-Each-Schleife
    System.out.print(wort + ' ');       // Durchläuft jedes Element

double werte[];
int n = 10;
werte = new double[n];      // Reservierung nach Deklaration
werte.length;               // Länge des Feldes

// 3D Feld
double em[][] = {{1.0, 0.0, 0.0},
                 {0.0, 1.0, 0.0},
                 {0.0, 0.0, 1.0}};
```

## Klassen und Unterprogramme

### Referenzen
* Reservierung von Speicherplatz für Variable mit `new` --> Referenz
  * Felder sind *immer* Referenzen
  * Speicherung der eigentlichen Speicheradresse im Objekt
  * *Pointer* existieren in Java nicht
  * standardmäßig als *Null-Referenz*
* Parameterübergabe normalerweise über *Call-by-value*
  * falls mit `new` angelegt als Referenz
  * Referenzen ändern den ursprünglichen Wert (außerhalb des Unterprogramms)
    
### Klassen
* Jede *public*-Klasse gehört in eine einzelne Datei

**Deklaration von einer Klasse**
```java
Modifizierer class Klasse {
    // Klassenelemente
    // Attribute standardmäßig private

    double veryImportant = 2.0;
    private void Methodenname (int parameter) {
        // Anweisung
    }

    // Setter und Getter
    public void setValue(double a) { veryImportant = a; };
    public double getValue() { return veryImportant; };
}

Klasse instanz;                 // Deklaration
instanz = new Klasse();         // Initialisierung
instanz.setValue(4.3);          // Setzen von Werten
double a = instanz.getValue();  // Abrufen selbiger
```

### Unterprogramme
* Java für prozedurale Programmierung nicht vorgesehen
* identische Programmteile können in Unterprogrammen ausgelagert werden, um Wiederholungen zu vermeiden

**Deklaration eines Unterprogramms**
```java
static Rückgabetyp Name(Parameter) {
    // ...
    return Rückgabetyp;
}
```
* Rückgabedatentyp `void` gibt nichts zurück
* bei `return xy` wird das Unterprogramm mit dem entsprechenden Rückgabewert beendet

* Signaturen: Name, Reihenfolge der Parameter
* Unzulässig: mehrere Methoden mit gleicher Signatur in einer Klasse
```java
Deklaration
static void add(double x, int y) {...}
Stignatur
add(double, int)
```

### Rekursion
* Wenn ein Unterprogramm sich selbst aufruft heißt dies *rekursiver Aufruf*
* Rückführung auf trivial lösbaren Fall und Weitergabe von Problemen
* **Rekursionsanker nicht vergessen!**

```java
static void fak(int n) {
if(n < 0)
    return -1;      // Fehler

if(n <= 1)          // Rekursionsanker
    return 1;       // bzw. Rekursionsbasis
else
    return n * fak(n - 1);  // rekursiver Aufruf
}
```

### Vererbung, vordefinierte Klassen
```
                  ┌───────────┐   Oberklasse
                  │Fahrzeug   │   (Basisklasse)
                  │>Sitzplätze│
        ┌─────────┴─────┬─────┴──────┐
        │               │            │
┌───────▼──────┐    ┌───▼───┐    ┌───▼───┐  Unterklasse
│Kraftfahrzeug │    │Fahrrad│    │Kutsche│  (abgeleitet)
│>Motorleistung│    └───────┘    │>Pferde│
└─┬──────────┬─┘                 └───────┘
  │          │   erbt: Sitzplätze
┌─▼─┐      ┌─▼─┐       Motorleistung
│PKW│      │LKW│
└───┘      └───┘
```

### Fehlerbehandelung
**Exception Klasse**
* `package java.lang.Exception`
  * Exception e
      * IOException
          * FileNotFoundException
      * RuntimeException
          * IllegalArgumentException
              * NumberFormatException

* `e.getClass().getName()` liefert Ausnahme als Zeichenkette
* `e.getMessage()` liefert Fehlermeldung
* `e.toString()` Name und Fehlermeldung
* `e.printStackTrace()` Stapelabzug

**Try-Catch-Blöcke**
```java
try {
    // Anweisungen die eine allgemeine IOException, eine
    // FilenotFoundException oder eine NumberFormatException
    // auslösen
} catch (IOException e) {
    if (e instanceof FileNotFoundExcception) {
        // Behandlung von dieser Ausnahme
    } else {
        // allgemeiner Eingabefehler
    }
} catch (NumberFormatException e) {
    // Behandlung dieser Ausnahme
}
finally {
    // wird immer ausgeführrt
}
```

**Weiterleiten von Ausnahmen**
* Ausnahmen werden an Aufrufer weitergeleitet (*rethrow*)
```java
public static void getFile(String filename) {
    throws FileNotFoundException {
        // Anweisungen, die FileNotFoundException werfen können
    }
}
```

* Auslösen von Ausnahmen
```java
public static void setAge(int a) {
    thows IllegalArgumentException {
        if(a <= 0)
            throw new IllegalArgumentException("Age must be a positive integer!");
        age = a;
    }
}
```

* *Checked Exceptions*
  * müssen behandelt werden (durch *TryCatch* oder Weiterleitung)
  * Bsp.: `IOException`
* *Unchecked Exceptions*
  * können ohne Behandlung an den Aufrufer weitergeleitet werden
  * Bsp.: `Error`, `RunTimeException`, etc.

## Umgang mit Dateien
* Als Klasse `File`
* `File(String pathname)` erzeugt ein File-Objekt
* `File.seperatorChar` bzw. `File.seperator` liefern `/` bzw. `\`
* `boolean exists()` prüft, ob Datei vorhanden ist
* `boolean isDirectory()` true, falls Verzeichnis existiert
* `boolean isFile()` true, falls normale Datei existiert

**Schreiben in Dateien**
* Java behandelt Dateien als Ströme
```java
File f = new File("/home/blub/bar.txt");
OutputStream ostream = new FileOutputStream(f);
// eventuell tritt eine FileNotFoundException auf

PrintStream writer = new PrintStream(ostream, "UTF-8");
// eventuelle UnsupportedEncodingException
writer.println("Zwölf laxe Typen qualmen verdächtig süße Objekte.");
writer.flush();     // Ausgabe schreiben (Puffer)
writer.close();     // Datei schließen
```

**Lesen aus Dateien**
```java
File f = new File("/home/blub/foo.txt");
InputStream istream = new FileInputStream(f);
// eventuell tritt eine FileNotFoundException auf
Scanner reader = new Scanner(istream, "UTF-8");
// eventuelle UnsupportedEncodingException
if(reader.hasNextDATENTYP)      // falls DATENTYP als nächstes
    reader.nextDATENTYP();      // liest einen DATENTYP ein
```
