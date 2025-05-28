#pragma once
#include "Trayecto.h"
#include <map>
#include <utility>
#include <string>
#include <vector>

using namespace std;

#define BG_BLACK   "\x1B[40m"
#define BG_RED     "\x1B[41m"
#define BG_GREEN   "\x1B[42m"
#define BG_BLUE    "\x1B[44m"
#define BG_MAGENTA "\x1B[45m"
#define BG_WHITE   "\x1B[47m"
#define BG_ORANGE  "\x1B[48;2;255;165;0m"
#define BG_GRAY    "\x1B[48;2;128;128;128m"
#define BG_LBLUE    "\x1B[48;2;53;149;240m"
#define RESET      "\x1B[0m"

struct celda {
    string fondo = BG_BLACK;
    string texto = " ";
};

class Tablero {
private:
    int filas;
    int columnas;
    map<pair<int, int>, celda> tablero;
    vector<Trayecto> trayectos;

    string colorANSI(ColorCarta color) {
        switch(color) {
            case ColorCarta::ROJO: return BG_RED;
            case ColorCarta::AZUL: return BG_BLUE;
            case ColorCarta::VERDE: return BG_GREEN;
            case ColorCarta::MORADO: return BG_MAGENTA;
            case ColorCarta::GRIS: return BG_GRAY;
            case ColorCarta::NARANJA: return BG_ORANGE;
            default: return BG_BLACK;
        }
    }
    
    void inicializarTrayectos();

public:
    Tablero();
    void generarTablero();
    void mostrar();
    void marcarTrayectoOcupado(int fila, int col, const string& color, const string& texto);
    
    const vector<Trayecto>& getTrayectos() const { return trayectos; }
    
    Trayecto* getTrayecto(pair<int, int> inicio, pair<int, int> fin) {
        for(auto& t : trayectos) {
            if((t.getInicio() == inicio && t.getFin() == fin && !t.estaOcupado()) ||
               (t.getInicio() == fin && t.getFin() == inicio && !t.estaOcupado())) {
                return &t;
            }
        }
        return nullptr;
    }
};