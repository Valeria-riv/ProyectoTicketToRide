#pragma once
#include "Carta.h"
#include <vector>
#include <map>

using namespace std;

class Jugador {
private:
    int id;
    int vagonesRestantes;
    int puntos;
    vector<Carta> mano;
    map<ColorCarta, int> cartasPorColor;
    
    void eliminarCartas(ColorCarta color, int cantidad);
    void eliminarComodines(int cantidad);

public:
    Jugador(int id);
    void robarCarta(const Carta& carta);
    bool puedeConstruirTramo(ColorCarta color, int cantidad);
    void construirTramo(ColorCarta color, int cantidad);
    void agregarPuntos(int pts);
    int getPuntos() const;
    int getId() const;
    int getVagonesRestantes() const;
    const vector<Carta>& getMano() const;
    void mostrarMano() const;
};