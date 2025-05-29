#include "Juego.h"
#include <iostream>

using namespace std;

int main() {
    try {
        cout << "=== JUEGO DE TRENES ===\n";
        cout << "Cuantos jugadores? (2-4): ";
        int numJugadores;
        cin >> numJugadores;
        
        Juego juego(numJugadores);
        juego.comenzar();
        
    } catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    cout << "\nGracias por jugar!\n";
    return 0;
}
