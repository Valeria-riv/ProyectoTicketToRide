#include <iomanip>
#include <iostream>
#include <map>
#include <string>

#define FG_WHITE "\x1B[37m"
#define BG_BLACK   "\x1B[40m"
#define BG_RED     "\x1B[41m"
#define BG_GREEN   "\x1B[42m"
#define BG_BLUE    "\x1B[44m"
#define BG_MAGENTA "\x1B[45m"
#define BG_ORANGE  "\x1B[48;2;255;128;0m"
#define BG_LBLUE   "\x1B[48;2;53;149;240m"
#define BG_GRAY    "\x1B[48;2;176;174;174m"

using namespace std;


class Tablero {
public:
    int filas;
    int columnas;
    map<std::pair<int, int>, string> tablero; 
    Tablero();  
    void generarTablero();
    void mostrar();
};


