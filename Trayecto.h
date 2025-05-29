#pragma once
#include "Enums.h"
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class Trayecto {
public:
    enum TipoTrayecto {
        HORIZONTAL,
        VERTICAL,
        MIXTO
    };
    
        static string tipoToString(TipoTrayecto tipo) {
        switch(tipo) {
            case HORIZONTAL: return "Horizontal";
            case VERTICAL: return "Vertical";
            case MIXTO: return "Mixto";
            default: return "Desconocido";
        }
    }

private:
    vector<pair<int, int>> segmentos;
    ColorCarta color;
    int longitud;
    int puntos;
    bool ocupado;
    int jugadorId;
    TipoTrayecto tipo;

    void calcularPuntos() {
        if(longitud == 2) puntos = 1;
        else if(longitud == 3) puntos = 2;
        else if(longitud == 4) puntos = 4;
        else if(longitud == 5) puntos = 6;
        else if(longitud == 6) puntos = 9;
        else puntos = longitud * 2 - 3;
    }

public:
    Trayecto(const vector<pair<int, int>>& puntos, ColorCarta c, int l, TipoTrayecto t)
        : segmentos(puntos), color(c), longitud(l), ocupado(false), 
          jugadorId(-1), tipo(t) {
        calcularPuntos();
    }

    // Métodos de acceso
    ColorCarta getColor() const { return color; }
    int getLongitud() const { return longitud; }
    int getPuntos() const { return puntos; }
    bool estaOcupado() const { return ocupado; }
    int getJugadorId() const { return jugadorId; }
    TipoTrayecto getTipo() const { return tipo; }
    const vector<pair<int, int>>& getSegmentos() const { return segmentos; }
    pair<int, int> getInicio() const { return segmentos.front(); }
    pair<int, int> getFin() const { return segmentos.back(); }

    void ocupar(int idJugador) { 
        ocupado = true; 
        jugadorId = idJugador;
    }

    void mostrarInfo() const {
        cout << "Trayecto " << getTipoString() << ": ";
        cout << "(" << getInicio().first << "," << getInicio().second << ") a ";
        cout << "(" << getFin().first << "," << getFin().second << ")\n";
        cout << "Color: " << getColorString();
        cout << " | Longitud: " << longitud << " | Puntos: " << puntos;
        if(ocupado) cout << " (Ocupado por J" << jugadorId << ")";
        cout << endl;
        
    }

    string getTipoString() const {
        switch(tipo) {
            case HORIZONTAL: return "Horizontal";
            case VERTICAL: return "Vertical";
            case MIXTO: return "Mixto";
            default: return "Desconocido";
        }
    }

    string getColorString() const {
        switch(color) {
            case ColorCarta::ROJO: return "Rojo";
            case ColorCarta::AZUL: return "Azul";
            case ColorCarta::VERDE: return "Verde";
            case ColorCarta::MORADO: return "Morado";
            case ColorCarta::GRIS: return "Gris";
            case ColorCarta::NARANJA: return "Naranja";
            default: return "Comodín";
        }
    }
};