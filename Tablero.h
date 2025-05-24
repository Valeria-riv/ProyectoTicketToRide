#include <iomanip>
#include <iostream>
#include <map>
#include <string>

#define BG_BLACK   "\x1B[40m"
#define BG_RED     "\x1B[41m"
#define BG_GREEN   "\x1B[42m"
#define BG_BLUE    "\x1B[44m"
#define BG_MAGENTA "\x1B[45m"
#define BG_ORANGE  "\x1B[48;2;255;128;0m"
#define BG_GRAY    "\x1B[48;2;176;174;174m"
#define  RESET "\x1b[0m"

using namespace std;


struct celda {
    string fondo = BG_BLACK;
    string texto = " ";
};


class Tablero {
public:
    int filas;
    int columnas;
    map<pair<int, int>, celda> tablero;

    Tablero();  
    void generarTablero();
    void mostrar();
};



