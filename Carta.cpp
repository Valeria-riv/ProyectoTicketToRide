#include "Carta.h"

Carta::Carta(ColorCarta c) : tipo(TipoCarta::COLOR), color(c) {
    imagen = obtenerImagenColor();
}

Carta::Carta() : tipo(TipoCarta::COMODIN), color(ColorCarta::COMODIN) {
    imagen = "[COMODIN]";
}

bool Carta::esComodin() const { 
    return tipo == TipoCarta::COMODIN; 
}

ColorCarta Carta::getColor() const { 
    return color; 
}

string Carta::getImagen() const { 
    return imagen; 
}

string Carta::obtenerImagenColor() {
    switch(color) {
        case ColorCarta::ROJO: return "[ROJO]";
        case ColorCarta::AZUL: return "[AZUL]";
        case ColorCarta::VERDE: return "[VERDE]";
        case ColorCarta::MORADO: return "[MORADO]";
        case ColorCarta::GRIS: return "[GRIS]";
        case ColorCarta::NARANJA: return "[NARANJA]";
        default: return "[?]";
    }
}