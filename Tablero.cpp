#include "Tablero.h"
#include <iostream>

using namespace std;

Tablero::Tablero() {
    filas = 14;
    columnas = 19;
    
    // Inicializar todas las celdas como vacías
    for (int i = 1; i <= filas; ++i) {
        for (int j = 1; j <= columnas; ++j) {
            tablero[{i, j}] = celda();
            tablero[{i, j}].fondo = BG_BLACK;
            tablero[{i, j}].texto = " ";
        }
    }

    inicializarTrayectos();
    generarTablero();
}

void Tablero::inicializarTrayectos() {
    // Ejemplos de cada tipo:
    
    // Horizontal (A a F)
    trayectos.emplace_back(vector<pair<int,int>>{
        {8,2}, {8,3}, {8,4}, {8,5}}, 
        ColorCarta::AZUL, 4, Trayecto::HORIZONTAL);
    
    // Horizontal (F a H)
    trayectos.emplace_back(vector<pair<int,int>>{
        {8,7}, {8,8}},
        ColorCarta::NARANJA, 2, Trayecto::HORIZONTAL);
    
    // Horizontal (H a K)
    trayectos.emplace_back(vector<pair<int,int>>{
        {8,10}, {8,11}},
        ColorCarta::AZUL, 2, Trayecto::HORIZONTAL);
    
    // Horizontal (K a P)
    trayectos.emplace_back(vector<pair<int,int>>{
        {8,13}, {8,14}, {8,15}},
        ColorCarta::VERDE, 3, Trayecto::HORIZONTAL);
    
    // Horizontal (I a O)
    trayectos.emplace_back(vector<pair<int,int>>{
        {4,10}, {4,11}, {4,12}, {4,13}, {4,14}, {4,15}},
        ColorCarta::AZUL, 6, Trayecto::HORIZONTAL);
    
    // Horizontal (J a N)
    trayectos.emplace_back(vector<pair<int,int>>{
        {2,12}, {2,13}},
        ColorCarta::ROJO, 2, Trayecto::HORIZONTAL);
    
    // Vertical (F a G)
    trayectos.emplace_back(vector<pair<int,int>>{
        {9,6}, {10,6}, {11,6}}, 
        ColorCarta::NARANJA, 3, Trayecto::VERTICAL);
    
    // Vertical (E a F)
    trayectos.emplace_back(vector<pair<int,int>>{
        {5,6}, {6,6}, {7,6}}, 
        ColorCarta::VERDE, 3, Trayecto::VERTICAL);
    
    // Vertical (K a L)
    trayectos.emplace_back(vector<pair<int,int>>{
        {9,12}, {10,12}, {11,12}}, 
        ColorCarta::NARANJA, 3, Trayecto::VERTICAL);
    
    // Vertical (P a Q)
    trayectos.emplace_back(vector<pair<int,int>>{
        {9,16}, {10,16}, {11,16}}, 
        ColorCarta::VERDE, 3, Trayecto::VERTICAL);
    
    // Mixto (A a B)
    trayectos.emplace_back(vector<pair<int,int>>{
        {5,1}, {5,2}, {6,1}, {7,1}}, 
        ColorCarta::ROJO, 4, Trayecto::MIXTO);

    // Mixto (D a E)
    trayectos.emplace_back(vector<pair<int,int>>{
        {1,5}, {1,6}, {2,6}, {3,6}}, 
        ColorCarta::GRIS, 4, Trayecto::MIXTO);

    // Mixto (C a G)
    trayectos.emplace_back(vector<pair<int,int>>{
        {12,3}, {12,4}, {12,5}, {13,1}}, 
        ColorCarta::GRIS, 4, Trayecto::MIXTO);

    // Mixto (H a L)
    trayectos.emplace_back(vector<pair<int,int>>{
        {9,9}, {10,9}, {11,9}, {12,9}, {12,10}, {12,11}}, 
        ColorCarta::ROJO, 6, Trayecto::MIXTO);

    // Mixto (I a K)
    trayectos.emplace_back(vector<pair<int,int>>{
        {6,10}, {6,11}, {6,12}, {7,12}},
        ColorCarta::MORADO, 4, Trayecto::MIXTO);
    
    // Mixto (M a Q)
    trayectos.emplace_back(vector<pair<int,int>>{
        {14,14}, {14,15}, {14,16}, {13,16}},
        ColorCarta::MORADO, 4, Trayecto::MIXTO);

    // Mixto (N a O)
    trayectos.emplace_back(vector<pair<int,int>>{
        {2,15}, {2,16}, {3,16}},
        ColorCarta::VERDE, 3, Trayecto::MIXTO);

    // Mixto (O a R)
    trayectos.emplace_back(vector<pair<int,int>>{
        {4,17}, {4,18}, {4,19}, {5,19}},
        ColorCarta::MORADO, 4, Trayecto::MIXTO);

    // Mixto (S a Q)
    trayectos.emplace_back(vector<pair<int,int>>{
        {12,17}, {12,18}, {12,19}, {11,19}},
        ColorCarta::GRIS, 4, Trayecto::MIXTO);
    
}

void Tablero::generarTablero() {
    // Configurar las letras de las ciudades
    tablero[{8, 1}].texto = "A";
    tablero[{5, 3}].texto = "B";
    tablero[{14, 3}].texto = "C";
    tablero[{1, 4}].texto = "D";
    tablero[{4, 6}].texto = "E";
    tablero[{8, 6}].texto = "F";
    tablero[{12, 6}].texto = "G";
    tablero[{8, 9}].texto = "H";
    tablero[{5, 10}].texto = "I";
    tablero[{2, 11}].texto = "J";
    tablero[{8, 12}].texto = "K";
    tablero[{12, 12}].texto = "L";
    tablero[{14, 13}].texto = "M";
    tablero[{2, 14}].texto = "N";
    tablero[{4, 16}].texto = "O";
    tablero[{8, 16}].texto = "P";
    tablero[{12, 16}].texto = "Q";
    tablero[{6, 19}].texto = "R";
    tablero[{10, 19}].texto = "S";

    // Configurar colores de los trayectos
    // Azules (horizontales)
    for(int c = 2; c <= 5; ++c) tablero[{8, c}].fondo = BG_BLUE;
    for(int c = 10; c <= 15; ++c) tablero[{4, c}].fondo = BG_BLUE;
    for(int c = 10; c <= 11; ++c) tablero[{8, c}].fondo = BG_BLUE;

    // Naranjas (verticales)
    for(int f = 9; f <= 11; ++f) tablero[{f, 6}].fondo = BG_ORANGE;
    for(int f = 9; f <= 11; ++f) tablero[{f, 12}].fondo = BG_ORANGE;
    for(int c = 7; c <= 8; ++c) tablero[{8, c}].fondo = BG_ORANGE;
    for(int f = 5; f <= 7; ++f) tablero[{f, 16}].fondo = BG_ORANGE;

    // Verdes
    for(int c = 13; c <= 15; ++c) tablero[{8, c}].fondo = BG_GREEN;
    for(int f = 9; f <= 11; ++f) tablero[{f, 16}].fondo = BG_GREEN;
    for(int f = 5; f <= 7; ++f) tablero[{f, 6}].fondo = BG_GREEN;
    for(int c = 15; c <= 16; ++c) tablero[{2, c}].fondo = BG_GREEN;
    for(int f = 2; f <= 3; ++f) tablero[{f, 16}].fondo = BG_GREEN;

    // Rojos
    for(int c = 12; c <= 13; ++c) tablero[{2, c}].fondo = BG_RED;
    for(int c = 1; c <= 2; ++c) tablero[{5, c}].fondo = BG_RED;
    for(int f = 5; f <= 7; ++f) tablero[{f, 1}].fondo = BG_RED;
    for(int f = 9; f <= 12; ++f) tablero[{f, 9}].fondo = BG_RED;
    for(int c = 9; c <= 11; ++c) tablero[{12, c}].fondo = BG_RED;

    // Magentas
    for(int c = 14; c <= 16; ++c) tablero[{14, c}].fondo = BG_MAGENTA;
    for(int f = 13; f <= 14; ++f) tablero[{f, 16}].fondo = BG_MAGENTA;
    for(int c = 17; c <= 19; ++c) tablero[{4, c}].fondo = BG_MAGENTA;
    for(int f = 4; f <= 5; ++f) tablero[{f, 19}].fondo = BG_MAGENTA;
    for(int c = 10; c <= 12; ++c) tablero[{6, c}].fondo = BG_MAGENTA;
    for(int f = 6; f <= 7; ++f) tablero[{f, 12}].fondo = BG_MAGENTA;

    // Grises
    for(int c = 5; c <= 6; ++c) tablero[{1, c}].fondo = BG_GRAY;
    for(int f = 1; f <= 3; ++f) tablero[{f, 6}].fondo = BG_GRAY;
    for(int c = 3; c <= 5; ++c) tablero[{12, c}].fondo = BG_GRAY;
    for(int f = 12; f <= 13; ++f) tablero[{f, 3}].fondo = BG_GRAY;
    for(int f = 11; f <= 12; ++f) tablero[{f, 19}].fondo = BG_GRAY;
    for(int c = 17; c <= 18; ++c) tablero[{12, c}].fondo = BG_GRAY;
}

void Tablero::mostrar() {
    // Mostrar números de columnas
    cout << "    ";
    for (int j = 1; j <= columnas; ++j) {
        if (j < 10) cout << " " << j << " ";
        else cout << j << " ";
    }
    cout << endl;

    // Mostrar filas
    for (int i = 1; i <= filas; ++i) {
        // Número de fila
        if (i < 10) cout << " " << i << "  ";
        else cout << i << "  ";

        // Contenido de las celdas
        for (int j = 1; j <= columnas; ++j) {
            celda c = tablero[{i, j}];
            cout << c.fondo << " " << c.texto << " " << RESET;
        }
        cout << endl;
    }
}

void Tablero::marcarTrayectoOcupado(int fila, int col, const string& color, const string& texto) {
    auto it = tablero.find({fila, col});
    if(it != tablero.end()) {
        it->second.fondo = color;
        it->second.texto = texto;
    }
}