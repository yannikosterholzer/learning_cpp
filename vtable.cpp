#include <iostream>
#include <iomanip>
#include <cstdint>
using namespace std;

// Basisklasse mit virtueller Methode
struct Basisklasse {
    // Virtuelle Methode, die später überschrieben wird
    virtual int getFaddr() const;  
};

// Implementierung der virtuellen Methode in der Basisklasse
int Basisklasse::getFaddr() const {
    // Zugriff auf die VTable:
    // - `this` zeigt auf das aktuelle Objekt.
    // - `reinterpret_cast` wandelt `this` in einen void-Zeiger um.
    // - VTable-Zeiger wird aus dem Objekt gelesen.
    auto** vtable = *reinterpret_cast<void***>(const_cast<void*>(static_cast<const void*>(this)));
    
    // Rückgabe der Adresse der ersten virtuellen Methode
    return reinterpret_cast<intptr_t>(vtable[0]); 
}

// Erste abgeleitete Klasse, die die virtuelle Methode überschreibt
struct Abgeleitet1 : Basisklasse {
    int getFaddr() const override {  
        // Ähnlicher Zugriff auf die VTable wie in der Basisklasse
        auto** vtable = *reinterpret_cast<void***>(const_cast<void*>(static_cast<const void*>(this)));
        return reinterpret_cast<intptr_t>(vtable[0]); 
    }
};

// Zweite abgeleitete Klasse, die die virtuelle Methode überschreibt
struct Abgeleitet2 : Basisklasse {
    int getFaddr() const override {  
        // Zugriff auf die VTable wie zuvor
        auto** vtable = *reinterpret_cast<void***>(const_cast<void*>(static_cast<const void*>(this)));
        return reinterpret_cast<intptr_t>(vtable[0]); 
    }
};

// Hilfsfunktion, um die Adresse der virtuellen Methode eines Objekts zu drucken
void printAddr(const Basisklasse& Objekt) {
    // Ausgabe der Adresse der virtuellen Methode in hexadezimaler Form
    cout << "Adresse der aufgerufenen Funktion: 0x"
        << hex << Objekt.getFaddr() << endl;
}

int main() {
    // Objekte der Basisklasse und der abgeleiteten Klassen
    Basisklasse Basis;
    Abgeleitet1 A1;
    Abgeleitet2 A2;

    // Polymorpher Aufruf der virtuellen Methode
    printAddr(Basis);  // Adresse der virtuellen Methode der Basisklasse
    printAddr(A1);     // Adresse der überschriebenen Methode in Abgeleitet1
    printAddr(A2);     // Adresse der überschriebenen Methode in Abgeleitet2

    return 0;
}
