#include "ventanajuego.h"
#include "ui_ventanajuego.h"

#include "estructura_carta.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <vector>
#include <QTimer>

ventanaJuego::ventanaJuego(const QString& nombreJugador, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ventanaJuego)
    , jugadorNombre(nombreJugador)
{
    ui->setupUi(this);
    connect(ui->btnSalir, &QPushButton::clicked, this, &ventanaJuego::salirDelJuego);

    iniciarJuego();
}

void ventanaJuego::iniciarJuego()
{
    mazo=generar_mazo();
    barajar(mazo);
    repartirCartas();

    turnoActual=0;
    puntosJugador=0;
    puntosMaquina=0;
    cartonJugador.clear();
    cartonMaquina.clear();
    mesa.clear();
    nuevaRonda=false;
    esTurnoJugador=true;

    actualizarVista();
}

void ventanaJuego::repartirCartas()
{
    manoJugador.clear();
    manoMaquina.clear();

    const int CARTAS_POR_JUGADOR = 5;  // o 4 según tus reglas

    for (int i = 0; i < CARTAS_POR_JUGADOR && !mazo.empty(); ++i) {
        // Reparte al jugador
        manoJugador.push_back(mazo.back());
        mazo.pop_back();

        // Reparte a la máquina si queda carta
        if (!mazo.empty()) {
            manoMaquina.push_back(mazo.back());
            mazo.pop_back();
        }
    }
}


void ventanaJuego::actualizarVista()
{
    // Limpia layout de botones de cartas
    QLayout *layout = ui->contenedorCartasJugador->layout();

    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    // Crear botones para cada carta del jugador
    for (size_t i = 0; i < manoJugador.size(); ++i) {
        QPushButton *botonCarta = new QPushButton(QString::fromStdString(manoJugador[i].letra + " de " + manoJugador[i].palo));
        botonCarta->setProperty("indice", static_cast<int>(i)); // Asignamos el índice como propiedad
        connect(botonCarta, &QPushButton::clicked, this, &ventanaJuego::jugarCarta);
        layout->addWidget(botonCarta);
    }

    // Mostrar cartas en la mesa
    QString textoMesa = "Mesa: ";
    for (const auto& c : mesa) {
        textoMesa += QString::fromStdString(c.carta.letra + " de " + c.carta.palo + " | ");
    }
    ui->labelMesa->setText(textoMesa.isEmpty() ? "Mesa: vacía" : textoMesa);

    // Mostrar puntajes
    ui->labelPuntajes->setText("Jugador: " + QString::number(puntosJugador) + " | Máquina: " + QString::number(puntosMaquina));
    ui->labelCarton->setText("Cartón Jugador: " + QString::number(cartonJugador.size()) +
                             " | Máquina: " + QString::number(cartonMaquina.size()));

    // Mostrar turno
    ui->labelTurnoActual->setText(esTurnoJugador ? "Turno del Jugador" : "Turno de la Máquina");

    // Mensajes se actualizan por separado con setText() desde lógica
}

void ventanaJuego::jugarCarta()
{
    if (!esTurnoJugador) return;

    QPushButton *boton = qobject_cast<QPushButton*>(sender());
    if (!boton) return;

    int indice = boton->property("indice").toInt();
    if (indice < 0 || indice >= static_cast<int>(manoJugador.size())) return;

    Carta carta = manoJugador[indice];
    manoJugador.erase(manoJugador.begin() + indice);

    ui->labelMensajes->setText("Jugaste: " + QString::fromStdString(carta.letra + " de " + carta.palo));

    bool hizoLimpia = false;
    string resultado = procesar_jugada(
        carta, mesa, cartonJugador,
        hizoLimpia, true, turnoActual, nuevaRonda
        );

    if (resultado == "caida" || resultado == "limpia") {
        puntosJugador += puntos_por_resultado(resultado, nuevaRonda);
        ui->labelMensajes->setText("Jugador hizo: " + QString::fromStdString(resultado));
    }

    turnoActual++;
    esTurnoJugador = false;
    actualizarVista();

    QTimer::singleShot(1000, this, &ventanaJuego::turnoMaquina); // Espera 1 segundo
}

void ventanaJuego::turnoMaquina()
{
    if (manoMaquina.empty()) return;

    Carta carta = manoMaquina.front();
    manoMaquina.erase(manoMaquina.begin());

    ui->labelMensajes->setText("Máquina juega: " + QString::fromStdString(carta.letra + " de " + carta.palo));

    bool hizoLimpia = false;
    string resultado = procesar_jugada(
        carta, mesa, cartonMaquina,
        hizoLimpia, false, turnoActual, nuevaRonda
        );

    if (resultado == "caida" || resultado == "limpia") {
        puntosMaquina += puntos_por_resultado(resultado, nuevaRonda);
        ui->labelMensajes->setText("Máquina hizo: " + QString::fromStdString(resultado));
    }

    turnoActual++;
    esTurnoJugador = true;
    verificar_final_mano();
    actualizarVista();
}

void ventanaJuego::verificar_final_mano()
{
    if (manoJugador.empty() && manoMaquina.empty() && !mazo.empty()) {
        repartirCartas();
        nuevaRonda = true;
        ui->labelMensajes->setText("Nueva ronda...");
    }

    if (mazo.empty() && manoJugador.empty() && manoMaquina.empty()) {
        auto evaluar_carton = [](int carton) {
            if (carton == 19) return 2;
            if (carton < 19) return 0;
            int nuevo = carton - 19 + 6;
            if (nuevo % 2 != 0) ++nuevo;
            return nuevo;
        };

        int extra_j = evaluar_carton(cartonJugador.size());
        int extra_m = evaluar_carton(cartonMaquina.size());
        puntosJugador += extra_j;
        puntosMaquina += extra_m;

        QString resumen = "FIN DEL JUEGO\n";
        resumen += "Cartón Jugador: " + QString::number(cartonJugador.size()) + " → +" + QString::number(extra_j) + "\n";
        resumen += "Cartón Máquina: " + QString::number(cartonMaquina.size()) + " → +" + QString::number(extra_m) + "\n";

        if (puntosJugador > puntosMaquina) {
            resumen += "¡Ganaste con " + QString::number(puntosJugador) + " puntos!";
            guardarResultado(true);
        } else if (puntosMaquina > puntosJugador) {
            resumen += "Perdiste con " + QString::number(puntosJugador) + " puntos.";
            guardarResultado(false);
        } else {
            resumen += "Empate.";
        }

        QMessageBox::information(this, "Resultado", resumen);
        emit partidaTerminada();
        close();
    }
}

void ventanaJuego::guardarResultado(bool gano)
{
    QFile archivo("usuarios.txt");
    QFile temporal("temporal.txt");

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text) || !temporal.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo actualizar usuarios.txt");
        return;
    }

    QTextStream in(&archivo);
    QTextStream out(&temporal);
    bool actualizado = false;

    while (!in.atEnd()) {
        QString linea = in.readLine().trimmed();

        if (linea.startsWith(jugadorNombre + " |")) {
            // Extraer los valores de ganadas y perdidas
            QStringList partes = linea.split("|");
            if (partes.size() >= 3) {
                QString nombre = partes[0].trimmed();
                int ganadas = partes[1].trimmed().remove("Ganadas:").toInt();
                int perdidas = partes[2].trimmed().remove("Perdidas:").toInt();

                if (gano) ganadas++;
                else perdidas++;

                out << nombre << " | Ganadas: " << ganadas << " | Perdidas: " << perdidas << "\n";
                actualizado = true;
            } else {
                out << linea << "\n"; // Línea mal formada
            }
        } else {
            out << linea << "\n"; // Otro jugador
        }
    }

    // Si no se encontró el jugador, lo agrega al final
    if (!actualizado) {
        out << jugadorNombre << " | Ganadas: " << (gano ? "1" : "0") << " | Perdidas: " << (gano ? "0" : "1") << "\n";
    }

    archivo.close();
    temporal.close();

    archivo.remove();
    temporal.rename("usuarios.txt");
}


void ventanaJuego::salirDelJuego()
{
    close();
}



ventanaJuego::~ventanaJuego()
{
    delete ui;
}
