#include "estructura_carta.h"

vector<Carta> generar_mazo() {
    vector<Carta> mazo;
    for (const auto& palo : PALOS) {
        for (const auto& letra : LETRAS) {
            mazo.push_back({letra, palo});
        }
    }
    return mazo;
}
void barajar(vector<Carta>& mazo) {
    random_device rd;
    mt19937 g(rd());
    shuffle(mazo.begin(), mazo.end(), g);
}
bool esNumeroValido(const string& letra) {
    return valor_suma.count(letra);
}
int puntos_por_resultado(const string& r, bool esNuevaRonda) {
    if (r == "caida" && esNuevaRonda) {
        return 0; // No se otorgan puntos por caída en la primera jugada de ronda
    } else if (r == "caida" || r == "limpia") {
        return 2; // Caída o limpia valen 2 puntos
    }
    return 0; // Las demás jugadas no dan puntos inmediatos
}
string procesar_jugada(Carta carta, vector<CartaEnMesa>& mesa, vector<Carta>& carton,
                       bool& hizo_limpia, bool esJugador, int turnoActual, bool& esNuevaRonda)
{
    hizo_limpia = false;
    string resultado = "ninguna"; // resultado por defecto
    bool recogio_cartas = false;

    // 1. Buscar capturas directas (llevar/caída)
    vector<CartaEnMesa> capturadasDirectas;
    for (const auto& c : mesa) {
        if (c.carta.letra == carta.letra) {
            capturadasDirectas.push_back(c);
        }
    }

    // Preparar otras variables para continuar
    vector<CartaEnMesa> capturadasIniciales;
    bool esCapturaDirecta = false;
    vector<CartaEnMesa> capturadasSuma;
    int opcionInicio = 1;
    // 2. Buscar capturas por suma (si aplica)
    if (esNumeroValido(carta.letra)) {
        int objetivo = valor_suma[carta.letra];
        int n = mesa.size();
        for (int i = 1; i < (1 << n); ++i) {
            vector<CartaEnMesa> temp;
            int suma = 0;
            bool valido = true;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    if (!esNumeroValido(mesa[j].carta.letra)) {
                        valido = false;
                        break;
                    }
                    suma += valor_suma[mesa[j].carta.letra];
                    temp.push_back(mesa[j]);
                }
            }
            if (valido && suma == objetivo && temp.size() >= 2) {
                capturadasSuma = temp;
                break; // solo toma la primera válida
            }
        }
    }
    bool hayCaptura = !capturadasDirectas.empty() || !capturadasSuma.empty();
    int eleccion = 1;

    // Buscar jugada por escalera
    // Buscar jugada por escalera SOLO si la carta jugada está en la mesa
    vector<CartaEnMesa> capturadasEscalera;
    bool cartaJugadaEnMesa = false;

    // Buscar si la carta jugada está en la mesa
    for (const auto& c : mesa) {
        if (c.carta.letra == carta.letra) {
            cartaJugadaEnMesa = true;
            break;
        }
    }

    if (cartaJugadaEnMesa) {
        int siguiente = orden[carta.letra] + 1;

        // Ordenamos la mesa para evaluar la escalera en orden
        vector<CartaEnMesa> mesaOrdenada = mesa;
        sort(mesaOrdenada.begin(), mesaOrdenada.end(), [](const CartaEnMesa& a, const CartaEnMesa& b) {
            return orden[a.carta.letra] < orden[b.carta.letra];
        });

        for (const auto& c : mesaOrdenada) {
            if (orden[c.carta.letra] == siguiente) {
                capturadasEscalera.push_back(c);
                siguiente++;
            } else if (orden[c.carta.letra] > siguiente) {
                break;
            }
        }
    }


    // Si no se encontró al menos una carta que continúa, la escalera no es válida


    bool hayCaida = false;
    for (const auto& c : mesa) {
        if (c.carta.letra == carta.letra && c.colocadaPorJugador != esJugador && c.turno == turnoActual - 1) {
            hayCaida = true;
            capturadasDirectas.push_back(c);
            break;
        }
    }

    // Decisión para ambos jugadores
    if (!capturadasDirectas.empty()) {
        resultado = hayCaida ? "caida" : "llevar";
        capturadasIniciales = capturadasDirectas;
        esCapturaDirecta = true;
        recogio_cartas = true;

        // Si también hay escalera, añadirla
        if (!capturadasEscalera.empty()) {
            capturadasIniciales.insert(capturadasIniciales.end(), capturadasEscalera.begin(), capturadasEscalera.end());
        }

    } else if (!capturadasEscalera.empty()) {
        resultado = "escalera";
        capturadasIniciales = capturadasEscalera;
        esCapturaDirecta = false;
        recogio_cartas = true;

    } else if (!capturadasSuma.empty()) {
        resultado = "suma";
        capturadasIniciales = capturadasSuma;
        esCapturaDirecta = false;
        recogio_cartas = true;
    }

    // 3. Aplicar captura o descarte
    if (!capturadasIniciales.empty()) {
        carton.push_back(carta);
        for (const auto& c : capturadasIniciales) {
            carton.push_back(c.carta);
            auto it = find(mesa.begin(), mesa.end(), c);
            if (it != mesa.end()) mesa.erase(it);
        }

        if (mesa.empty()) {
            hizo_limpia = true;
            resultado = "limpia";
        }
    } else {
        mesa.push_back({carta, esJugador, turnoActual});
    }


    return resultado;
}
