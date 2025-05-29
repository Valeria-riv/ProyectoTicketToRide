#include "Jugador.h"
#include <iostream>
#include <algorithm>

using namespace std;

Jugador::Jugador(int id) : id(id), vagonesRestantes(18), puntos(0) {
    // Inicializar contadores para todos los colores
    cartasPorColor[ColorCarta::ROJO] = 0;
    cartasPorColor[ColorCarta::AZUL] = 0;
    cartasPorColor[ColorCarta::VERDE] = 0;
    cartasPorColor[ColorCarta::MORADO] = 0;
    cartasPorColor[ColorCarta::GRIS] = 0;
    cartasPorColor[ColorCarta::NARANJA] = 0;
    cartasPorColor[ColorCarta::COMODIN] = 0;
}

void Jugador::robarCarta(const Carta& carta) {
    mano.push_back(carta);
    if(!carta.esComodin()) {
        cartasPorColor[carta.getColor()]++;
    } else {
        cartasPorColor[ColorCarta::COMODIN]++;
    }
}

bool Jugador::puedeConstruirTramo(ColorCarta color, int cantidad) {
    return (cartasPorColor[color] + cartasPorColor[ColorCarta::COMODIN]) >= cantidad;
}

void Jugador::eliminarCartas(ColorCarta color, int cantidad) {
    int eliminadas = 0;
    for(auto it = mano.begin(); it != mano.end() && eliminadas < cantidad; ) {
        if(it->getColor() == color) {
            it = mano.erase(it);
            eliminadas++;
        } else {
            ++it;
        }
    }
    cartasPorColor[color] -= eliminadas;
}

void Jugador::eliminarComodines(int cantidad) {
    int eliminados = 0;
    for(auto it = mano.begin(); it != mano.end() && eliminados < cantidad; ) {
        if(it->esComodin()) {
            it = mano.erase(it);
            eliminados++;
        } else {
            ++it;
        }
    }
    cartasPorColor[ColorCarta::COMODIN] -= eliminados;
}

void Jugador::construirTramo(ColorCarta color, int cantidad) {
    int cartasColor = cartasPorColor[color];
    int comodinesUsados = max(0, cantidad - cartasColor);
    int cartasUsadas = cantidad - comodinesUsados;
    
    if(cartasUsadas > 0) eliminarCartas(color, cartasUsadas);
    if(comodinesUsados > 0) eliminarComodines(comodinesUsados);
    
    vagonesRestantes -= cantidad;
}

void Jugador::agregarPuntos(int pts) { 
    puntos += pts; 
}

int Jugador::getPuntos() const { 
    return puntos; 
}

int Jugador::getId() const { 
    return id; 
}

int Jugador::getVagonesRestantes() const { 
    return vagonesRestantes; 
}

const vector<Carta>& Jugador::getMano() const { 
    return mano; 
}

void Jugador::mostrarMano() const {
    cout << "Mano del jugador " << id << ":\n";
    for(size_t i = 0; i < mano.size(); i++) {
        cout << (i + 1) << ". " << mano[i].getImagen() << "  ";
        if ((i + 1) % 5 == 0)
        cout << "\n";
    }
    cout << "\n\n";
   }