#ifndef VENTANACONTINUAR_H
#define VENTANACONTINUAR_H

#include <QWidget>

namespace Ui {
class ventanacontinuar;
}

class ventanacontinuar : public QWidget
{
    Q_OBJECT

public:
    explicit ventanacontinuar(QWidget *parent = nullptr);
    ~ventanacontinuar();

private slots:
    void on_btnRegresar_clicked();
    void generarJugadores();
    void eliminarUsuario();
    void on_btnactualizar_clicked();
    void editarUsuario();
    void actualizarListaUsuarios();

    void on_btnjugar_clicked();

    void jugarConUsuario();

private:
    Ui::ventanacontinuar *ui;

};

#endif // VENTANACONTINUAR_H
