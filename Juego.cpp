#include "Juego.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <ctime>

using namespace std;

Juego::Juego(int numJugadores) : jugadorActual(0) {
    if(numJugadores < 2 || numJugadores > 4) {
        throw invalid_argument("El juego es para 2-4 jugadores");
    }

    for(int i = 0; i < numJugadores; ++i) {
        jugadores.push_back(Jugador(i+1));
    }

    inicializarMazo();
    
}

void Juego::inicializarMazo() {
    // 12 cartas de cada color (6 colores)
    for(int i = 0; i < 12; ++i) {
        mazo.push_back(Carta(ColorCarta::ROJO));
        mazo.push_back(Carta(ColorCarta::AZUL));
        mazo.push_back(Carta(ColorCarta::VERDE));
        mazo.push_back(Carta(ColorCarta::MORADO));
        mazo.push_back(Carta(ColorCarta::GRIS));
        mazo.push_back(Carta(ColorCarta::NARANJA));
    }

    // 4 comodines
    for(int i = 0; i < 6; ++i) {
        mazo.push_back(Carta());
    }

    barajarMazo();
}

void Juego::barajarMazo() {
    srand(time(0));
    random_shuffle(mazo.begin(), mazo.end());
}

Carta Juego::robarCarta() {
    if(mazo.empty()) {
        mazo = descarte;
        descarte.clear();
        barajarMazo();
        
        if(mazo.empty()) {
            throw runtime_error("No hay cartas disponibles");
        }
    }

    Carta carta = mazo.back();
    mazo.pop_back();
    return carta;
}

void Juego::mostrarTrayectosDisponibles() {
    cout << "\nTrayectos disponibles:\n";
    const vector<Trayecto>& trayectos = tablero.getTrayectos();
    int index = 1;
    
    for(const auto& trayecto : trayectos) {
        if(!trayecto.estaOcupado()) {
            cout << index++ << ". ";
            trayecto.mostrarInfo();
        }
    }
}

void Juego::turnoRobarCartas(Jugador& jugador) {
    if (zonacartas.empty()) {
        reponerZonaCartas();
        
    }
    
    cout << "\n Zona de cartas: \n";
    for (size_t i = 0; i < zonacartas.size(); i++) {
        cout << (i + 1) << ". " << zonacartas[i].getImagen() << "\n";
    }
    
    cout << "\nSeleccione 2 cartas (ingresa números separados por espacio); ";
    int carta1, carta2;
    cin >> carta1 >> carta2;
    
    //Validar seleccion
    if (1 > carta1 || carta1 > zonacartas.size() ||
        1 > carta2 || carta2 > zonacartas.size() || carta1 == carta2) {
        
        cout << "Seleccion incorrecta. \n";
        carta1 = 1;
        carta2 = 2;
    }
       
    if (zonacartas[carta1 - 1].tipo==TipoCarta::COMODIN){ 
        jugador.robarCarta(zonacartas[carta1 - 1]);
        cout << "Has robado: " << zonacartas[carta1 - 1].getImagen()<< "\n";
    }else {
        if(zonacartas[carta2 - 1].tipo==TipoCarta::COMODIN){
            jugador.robarCarta(zonacartas[carta2 - 1]);
            cout << "Has robado: " << zonacartas[carta2 - 1].getImagen() << "\n";
        }else{
            jugador.robarCarta(zonacartas[carta1 - 1]);
            jugador.robarCarta(zonacartas[carta2 - 1]);
            cout << "Has robado: " << zonacartas[carta1 - 1].getImagen()
            << " y " << zonacartas[carta2 - 1].getImagen() << "\n";
        }
    }
    
    vector<Carta> nuevasCartas;
    for (size_t i = 0; i < zonacartas.size(); i++){
        if (i != carta1 - 1 && i != carta2 - 1) {
            descarte.push_back(zonacartas[i]);
        }
    }
        
    zonacartas.clear();
    reponerZonaCartas();
    
}

void Juego::turnoConstruirTramo(Jugador& jugador) {
    tablero.mostrar();
    
    cout << "\n=== CONSTRUIR TRAYECTO ===\n";
    cout << "1. Horizontal (misma fila, columnas diferentes)\n";
    cout << "2. Vertical (misma columna, filas diferentes)\n";
    cout << "3. Mixto (combinación de ambos)\n";
    cout << "Seleccione el tipo (1-3) o 0 para cancelar: ";
    
    int opcionTipo;
    cin >> opcionTipo;
    
    if(opcionTipo < 1 || opcionTipo > 3) {
        cout << "Construcción cancelada.\n";
        return;
    }

    Trayecto::TipoTrayecto tipo = static_cast<Trayecto::TipoTrayecto>(opcionTipo - 1);
    
    // Pedir coordenadas
    int filaInicio, colInicio, filaFin, colFin;
    cout << "\nCoordenadas de INICIO:\n";
    cout << "Fila (1-14): ";
    cin >> filaInicio;
    cout << "Columna (1-19): ";
    cin >> colInicio;
    
    cout << "\nCoordenadas de FIN:\n";
    cout << "Fila (1-14): ";
    cin >> filaFin;
    cout << "Columna (1-19): ";
    cin >> colFin;

    // Validar tipo de trayecto
    bool valido = false;
    switch(tipo) {
        case Trayecto::HORIZONTAL:
            valido = (filaInicio == filaFin);
            break;
        case Trayecto::VERTICAL:
            valido = (colInicio == colFin);
            break;
        case Trayecto::MIXTO:
            valido = (filaInicio != filaFin && colInicio != colFin);
            break;
    }
    
    if(!valido) {
        cout << "Error: Las coordenadas no corresponden a un trayecto " 
             << Trayecto::tipoToString(tipo) << ".\n";
        return;
    }

    // Buscar trayecto
    Trayecto* trayecto = tablero.getTrayecto({filaInicio, colInicio}, {filaFin, colFin});
    
    if(!trayecto || trayecto->estaOcupado()) {
        cout << "No hay un trayecto disponible entre esos puntos.\n";
        return;
    }

    // Verificar cartas
    if(!jugador.puedeConstruirTramo(trayecto->getColor(), trayecto->getLongitud())) {
        cout << "No tienes suficientes cartas. Necesitas " 
             << trayecto->getLongitud() << " cartas " 
             << trayecto->getColorString() << ".\n";
        return;
        
    }

    // Confirmar
    cout << "\nResumen del trayecto:\n";
    trayecto->mostrarInfo();
    cout << "¿Construir? (s/n): ";
    
    char confirmar;
    cin >> confirmar;
    
    if(confirmar == 's' || confirmar == 'S') {
        jugador.construirTramo(trayecto->getColor(), trayecto->getLongitud());
        trayecto->ocupar(jugador.getId());
        jugador.agregarPuntos(trayecto->getPuntos());
        
        // Marcar en tablero
        for(const auto& punto : trayecto->getSegmentos()) {
            tablero.marcarTrayectoOcupado(
                punto.first, punto.second, 
                BG_LBLUE, to_string(jugador.getId())
            );
        }
        
        cout << "¡Trayecto construido! +" << trayecto->getPuntos() << " puntos.\n";
    } else {
        cout << "Construcción cancelada.\n";
        
    }

}

void Juego::comenzar() {
    cout << "\n=== COMIENZA EL JUEGO DE TRENES ===\n";
    
    while(true) {
        Jugador& jugador = jugadores[jugadorActual];
        
        // Mostrar siempre el tablero al inicio del turno
        cout << "\n--- Turno del Jugador " << jugador.getId() << " ---\n";
        tablero.mostrar();
        
        cout << "\nVagones restantes: " << jugador.getVagonesRestantes() << "\n";
        cout << "Puntos actuales: " << jugador.getPuntos() << "\n";
        jugador.mostrarMano();
        
        cout << "\nOpciones:\n";
        cout << "1. Robar cartas\n";
        cout << "2. Construir trayecto\n";
        cout << "Seleccione: ";
        
        int opcion;
        cin >> opcion;
        
        if(opcion == 1) {
            turnoRobarCartas(jugador);
        } else if(opcion == 2) {
            turnoConstruirTramo(jugador);
        } else {
            cout << "Opción no válida\n";
            continue;
        }
        cout << "Presiona Enter para continuar...";
			cin.ignore();
			cin.get();
			system("clear");
			
        // Verificar fin del juego
        if(jugador.getVagonesRestantes() < 5) {
            cout << "\n¡El jugador " << jugador.getId() << " tiene menos de 5 vagones!\n";
            cout << "Última ronda...\n";
            
            // Jugar última ronda
            int ultimoJugador = jugadorActual;
            jugadorActual = (jugadorActual + 1) % jugadores.size();
            
            while(jugadorActual != ultimoJugador) {
                Jugador& j = jugadores[jugadorActual];
                
                cout << "\n--- Turno final del Jugador " << j.getId() << " ---\n";
                tablero.mostrar();
                cout << "1. Robar cartas\n2. Construir trayecto\n";
                cin >> opcion;
                
                if(opcion == 1) {
                    turnoRobarCartas(j);
                } else if(opcion == 2) {
                    turnoConstruirTramo(j);
                }
                
                jugadorActual = (jugadorActual + 1) % jugadores.size();
            }
            
            break; // Terminar el juego
        }
        
        // Siguiente jugador
        jugadorActual = (jugadorActual + 1) % jugadores.size();
    }
    
    // Fin del juego
    calcularPuntuacion();
}

void Juego::calcularPuntuacion() {
    cout << "\n=== RESULTADOS FINALES ===\n";
    
    // Ordenar jugadores por puntos (mayor a menor)
    vector<Jugador> jugadoresOrdenados = jugadores;
    sort(jugadoresOrdenados.begin(), jugadoresOrdenados.end(), 
        [](const Jugador& a, const Jugador& b) {
            return a.getPuntos() > b.getPuntos();
        });
    
    // Mostrar puntuaciones
    for(const auto& jugador : jugadoresOrdenados) {
        cout << "Jugador " << jugador.getId() << ": " 
             << jugador.getPuntos() << " puntos\n";
    }
    
    // Verificar empate
    if(jugadoresOrdenados.size() > 1 && 
       jugadoresOrdenados[0].getPuntos() == jugadoresOrdenados[1].getPuntos()) {
        cout << "\n¡Hay un empate!\n";
    } else {
        cout << "\n¡El ganador es el Jugador " << jugadoresOrdenados[0].getId() << "!\n";
    }
}

void Juego::reponerZonaCartas() {
    for (const auto& carta : zonacartas) {
        descarte.push_back(carta);
    }
    zonacartas.clear();
    
    for (int i = 0; i < Cartas_visibles && !mazo.empty(); i++) {
        zonacartas.push_back(robarCarta());
    }
}