#include "./Tablero.h"

Tablero::Tablero() {
	filas = 14;
	columnas = 19;

	for (int i = 1; i <= (filas+1); ++i) {
		for (int j = 1; j <= (columnas+1); ++j) {
			tablero[ {i, j}] = BG_BLACK, " ";
		}
	}
}

void Tablero::generarTablero() {

	for(int c = 2; c <= 5; ++c) {
		tablero[ {8, c}] = BG_BLUE;
	}
	
	for(int c = 10; c <= 15; ++c) {
		tablero[ {4, c}] = BG_BLUE;
	}
	
	for(int c = 10; c <= 11; ++c) {
		tablero[ {8, c}] = BG_BLUE;
	}
	
	
	for (int f = 9; f <= 11; ++f) {
        tablero[{f, 6}] = BG_ORANGE;
    }
    
    for (int f = 9; f <= 11; ++f) {
        tablero[{f, 12}] = BG_ORANGE;
    }
    
    for(int c = 7; c <= 8; ++c) {
		tablero[ {8, c}] = BG_ORANGE;
	}
	
	for (int f = 5; f <= 7; ++f) {
        tablero[{f, 16}] = BG_ORANGE;
    }
    
    for(int c = 13; c <= 15; ++c) {
		tablero[ {8, c}] = BG_GREEN;
	}
    
    for (int f = 9; f <= 11; ++f) {
        tablero[{f, 16}] = BG_GREEN;
    }
    
    for (int f = 5; f <= 7; ++f) {
        tablero[{f, 6}] = BG_GREEN;
    }
    
    for(int c = 15; c <= 16; ++c) {
		tablero[ {2, c}] = BG_GREEN;
	}
	
	for (int f = 2; f <= 3; ++f) {
        tablero[{f, 16}] = BG_GREEN;
    }
    
    for(int c = 12; c <= 13; ++c) {
		tablero[ {2, c}] = BG_RED;
	}
    
    for(int c = 1; c <= 2; ++c) {
		tablero[ {5, c}] = BG_RED;
	}
	
	for(int f = 5; f <= 7; ++f) {
		tablero[ {f, 1}] = BG_RED;
	}
	
	for(int f = 9; f <= 12; ++f) {
		tablero[ {f, 9}] = BG_RED;
	}
	
	for(int c = 9; c <= 11; ++c) {
		tablero[ {12, c}] = BG_RED;
	}

    for(int c = 14; c <= 16; ++c) {
		tablero[ {14, c}] = BG_MAGENTA;
	}
	
	for(int f = 13; f <= 14; ++f) {
		tablero[ {f, 16}] = BG_MAGENTA;
	}
	
	for(int c = 17; c <= 19; ++c) {
		tablero[ {4, c}] = BG_MAGENTA;
	}
	
	for(int f = 4; f <= 5; ++f) {
		tablero[ {f, 19}] = BG_MAGENTA;
	}
	
	for(int c = 10; c <= 12; ++c) {
		tablero[ {6, c}] = BG_MAGENTA;
	}
	
	for(int f = 6; f <= 7; ++f) {
		tablero[ {f, 12}] = BG_MAGENTA;
	}
	
	for(int c = 5; c <= 6; ++c) {
		tablero[ {1, c}] = BG_GRAY;
	}
	
	for(int f = 1; f <= 3; ++f) {
		tablero[ {f, 6}] = BG_GRAY;
	}
	
	for(int c = 3; c <= 5; ++c) {
		tablero[ {12, c}] = BG_GRAY;
	}
	
	for(int f = 12; f <= 13; ++f) {
		tablero[ {f, 3}] = BG_GRAY;
	}
	
	for(int f = 11; f <= 12; ++f) {
		tablero[ {f, 19}] = BG_GRAY;
	}
	
	for(int c = 17; c <= 18; ++c) {
		tablero[ {12, c}] = BG_GRAY;
	}
	
    //tablero[ {8, 1}] = BG_BLACK FG_WHITE "A";

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
		} else  {
			cout << i << "  ";
		}
		for (int j = 1; j <= columnas; ++j) {
			cout << tablero[ {i, j}] << "   ";
		}
		cout << "\x1B[0m" << endl;
	}
};
