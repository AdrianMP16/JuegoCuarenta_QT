#ifndef ESTRUCTURA_CARTA_H
#define ESTRUCTURA_CARTA_H

#include <vector>
#include <string>
#include <map>
#include <random>
#include <algorithm>

using namespace std;

struct Carta {
    string letra;
    string palo;
    bool operator==(const Carta& other) const {
        return letra == other.letra && palo == other.palo;
    }
};

struct CartaEnMesa {
    Carta carta;
    bool colocadaPorJugador; // true: jugador, false: máquina
    int turno;               // Turno en que se colocó
    bool operator==(const CartaEnMesa& other) const {
        return carta == other.carta;
    }
};

// PALOS y LETRAS
const vector<string> PALOS = {"corazones R", "corazones N", "treboles", "brillos"};
const vector<string> LETRAS = {"A", "2", "3", "4", "5", "6", "7", "J", "Q", "K"};

// Orden para comparar
static map<string, int> orden = {
    {"A", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5},
    {"6", 6}, {"7", 7}, {"J", 8}, {"Q", 9}, {"K", 10}
};

// Valores sumables
static map<string, int> valor_suma = {
    {"A", 1}, {"2", 2}, {"3", 3}, {"4", 4},
    {"5", 5}, {"6", 6}, {"7", 7}
};

// Prototipos de funciones
vector<Carta> generar_mazo();
void barajar(vector<Carta>& mazo);
bool esNumeroValido(const string& letra);
string procesar_jugada(Carta carta, vector<CartaEnMesa>& mesa, vector<Carta>& carton,
                       bool& hizo_limpia, bool esJugador, int turnoActual, bool& esNuevaRonda);
int puntos_por_resultado(const string& r, bool esNuevaRonda);


#endif // ESTRUCTURA_CARTA_H
