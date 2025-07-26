#ifndef VENTANAREGISTRO_H
#define VENTANAREGISTRO_H

#include <QWidget>

namespace Ui {
class VentanaRegistro;
}

class VentanaRegistro : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaRegistro(QWidget *parent = nullptr);
    ~VentanaRegistro();

private slots:
    void on_btnGuardar_clicked();

    void on_btnRegresar_clicked();

private:
    Ui::VentanaRegistro *ui;
};

#endif // VENTANAREGISTRO_H
