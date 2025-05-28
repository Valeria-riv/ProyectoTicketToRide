#pragma once
#include "Tablero.h"
#include "Jugador.h"
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Juego {
private:
    vector<Jugador> jugadores;
    Tablero tablero;
    vector<Carta> mazo;
    vector<Carta> descarte;
    int jugadorActual;
    vector<Carta> zonacartas;
    const int Cartas_visibles = 4;

    void inicializarMazo();
    void barajarMazo();
    Carta robarCarta();
    void turnoRobarCartas(Jugador& jugador);
    void turnoConstruirTramo(Jugador& jugador);
    void calcularPuntuacion();
    void mostrarTrayectosDisponibles();
    void reponerZonaCartas();

public:
Carta cta;
    Juego(int numJugadores);
    void comenzar();
};