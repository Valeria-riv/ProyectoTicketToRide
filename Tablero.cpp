#include "./Tablero.h"

Tablero::Tablero() {
    
	filas = 14;
	columnas = 19;
	
	for (int i = 1; i <= filas; ++i) {
    for (int j = 1; j <= columnas; ++j) {
        tablero[{i, j}] = celda();
    }
}

	for (int i = 1; i <= (filas); ++i) {
		for (int j = 1; j <= (columnas); ++j) {
			tablero[{i, j}].fondo = BG_BLACK;
            tablero[{i, j}].texto = " ";

		}
	}

}

void Tablero::generarTablero() {
    
	tablero[ {8, 1}].texto = "A";
	tablero[ {5, 3}].texto = "B";
	tablero[ {14, 3}].texto = "C";
	tablero[ {1, 4}].texto = "D";
	tablero[ {4, 6}].texto = "E";
	tablero[ {8, 6}].texto = "F";
	tablero[ {12, 6}].texto = "G";
	tablero[ {8, 9}].texto = "H";
	tablero[ {5, 10}].texto = "I";
	tablero[ {2, 11}].texto = "J";
	tablero[ {8, 12}].texto = "K";
	tablero[ {12, 12}].texto = "L";
	tablero[ {14, 13}].texto = "M";
	tablero[ {2, 14}].texto = "N";
	tablero[ {4, 16}].texto = "O";
	tablero[ {8, 16}].texto = "P";
	tablero[ {12, 16}].texto = "Q";
	tablero[ {6, 19}].texto = "R";
	tablero[ {10, 19}].texto = "S";

	

	for(int c = 2; c <= 5; ++c) {
		tablero[ {8, c}].fondo = BG_BLUE;
	}

	for(int c = 10; c <= 15; ++c) {
		tablero[ {4, c}].fondo = BG_BLUE;
	}

	for(int c = 10; c <= 11; ++c) {
		tablero[ {8, c}].fondo = BG_BLUE;
	}


	for (int f = 9; f <= 11; ++f) {
		tablero[ {f, 6}].fondo = BG_ORANGE;
	}

	for (int f = 9; f <= 11; ++f) {
		tablero[ {f, 12}].fondo = BG_ORANGE;
	}

	for(int c = 7; c <= 8; ++c) {
		tablero[ {8, c}].fondo = BG_ORANGE;
	}

	for (int f = 5; f <= 7; ++f) {
		tablero[ {f, 16}].fondo = BG_ORANGE;
	}

	for(int c = 13; c <= 15; ++c) {
		tablero[ {8, c}].fondo = BG_GREEN;
	}

	for (int f = 9; f <= 11; ++f) {
		tablero[ {f, 16}].fondo = BG_GREEN;
	}

	for (int f = 5; f <= 7; ++f) {
		tablero[ {f, 6}].fondo = BG_GREEN;
	}

	for(int c = 15; c <= 16; ++c) {
		tablero[ {2, c}].fondo = BG_GREEN;
	}

	for (int f = 2; f <= 3; ++f) {
		tablero[ {f, 16}].fondo = BG_GREEN;
	}

	for(int c = 12; c <= 13; ++c) {
		tablero[ {2, c}].fondo = BG_RED;
	}

	for(int c = 1; c <= 2; ++c) {
		tablero[ {5, c}].fondo = BG_RED;
	}

	for(int f = 5; f <= 7; ++f) {
		tablero[ {f, 1}].fondo = BG_RED;
	}

	for(int f = 9; f <= 12; ++f) {
		tablero[ {f, 9}].fondo = BG_RED;
	}

	for(int c = 9; c <= 11; ++c) {
		tablero[ {12, c}].fondo = BG_RED;
	}

	for(int c = 14; c <= 16; ++c) {
		tablero[ {14, c}].fondo = BG_MAGENTA;
	}

	for(int f = 13; f <= 14; ++f) {
		tablero[ {f, 16}].fondo = BG_MAGENTA;
	}

	for(int c = 17; c <= 19; ++c) {
		tablero[ {4, c}].fondo = BG_MAGENTA;
	}

	for(int f = 4; f <= 5; ++f) {
		tablero[ {f, 19}].fondo = BG_MAGENTA;
	}

	for(int c = 10; c <= 12; ++c) {
		tablero[ {6, c}].fondo = BG_MAGENTA;
	}

	for(int f = 6; f <= 7; ++f) {
		tablero[ {f, 12}].fondo = BG_MAGENTA;
	}

	for(int c = 5; c <= 6; ++c) {
		tablero[ {1, c}].fondo = BG_GRAY;
	}

	for(int f = 1; f <= 3; ++f) {
		tablero[ {f, 6}].fondo = BG_GRAY;
	}

	for(int c = 3; c <= 5; ++c) {
		tablero[ {12, c}].fondo = BG_GRAY;
	}

	for(int f = 12; f <= 13; ++f) {
		tablero[ {f, 3}].fondo = BG_GRAY;
	}

	for(int f = 11; f <= 12; ++f) {
		tablero[ {f, 19}].fondo = BG_GRAY;
	}

	for(int c = 17; c <= 18; ++c) {
		tablero[ {12, c}].fondo = BG_GRAY;
	}



}

void Tablero::mostrar() {
    
	cout << "    ";
	for (int j = 1; j <= columnas; ++j) {
		if (j < 10) {
			cout << " " << j << " ";
		} else {
			cout << j << " ";
		}
	}
	cout << endl;

	for (int i = 1; i <= filas; ++i) {
		if (i < 10) {
			cout << " " << i << "  ";
		} else {
			cout << i << "  ";
		}

		for (int j = 1; j <= columnas; ++j) {
			celda celda = tablero[{i, j}];

			cout << celda.fondo << " " << celda.texto << " " << "\x1B[0m";
		}

		cout << endl;
	}
}
