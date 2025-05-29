#pragma once
#include "Enums.h"
#include <string>

using namespace std;

class Carta {
private:
    ColorCarta color;
    string imagen;
    string obtenerImagenColor();

public:
    TipoCarta tipo;
    Carta(ColorCarta c);
    Carta();
    bool esComodin() const;
    ColorCarta getColor() const;
    string getImagen() const;
};