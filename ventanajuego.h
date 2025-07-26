#ifndef VENTANAJUEGO_H
#define VENTANAJUEGO_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <vector>
#include <map>
#include <QString>
#include "estructura_carta.h"

QT_BEGIN_NAMESPACE
namespace Ui {class ventanaJuego;}
QT_END_NAMESPACE


class ventanaJuego : public QWidget
{
    Q_OBJECT

public:
    explicit ventanaJuego(const QString& nombreJugador, QWidget *parent = nullptr);
    ~ventanaJuego();

signals:
    void partidaTerminada();

private slots:
    void jugarCarta();
    void turnoMaquina();
    void actualizarVista();
    void salirDelJuego();

private:
    Ui::ventanaJuego *ui;
    QString jugadorNombre;

    std::vector<Carta> mazo;
    std::vector<Carta> manoJugador;
    std::vector<Carta> manoMaquina;
    std::vector<CartaEnMesa> mesa;
    std::vector<Carta> cartonJugador;
    std::vector<Carta> cartonMaquina;

    int puntosJugador = 0;
    int puntosMaquina = 0;
    int turnoActual = 0;
    bool nuevaRonda = false;
    bool esTurnoJugador = true;

    void iniciarJuego();
    void repartirCartas();
    void mostrarCartasJugador();
    void mostrarMesa();
    void actualizarPuntajeFinal(); // Lógica para sumar puntos del cartón
    void guardarResultado(bool gano);
    void verificar_final_mano();
};

#endif // VENTANAJUEGO_H
