#ifndef VENTANAACTUALIZAR_H
#define VENTANAACTUALIZAR_H

#include <QWidget>

namespace Ui {
class ventanaActualizar;
}

class ventanaActualizar : public QWidget
{
    Q_OBJECT

signals:
    void nombreActualizado();

public:
    explicit ventanaActualizar(QString nombreJugador, QWidget *parent = nullptr);
    ~ventanaActualizar();

private slots:
    void on_btnRegresar_clicked();

    void on_btnGuardar_clicked();

private:
    Ui::ventanaActualizar *ui;
};

#endif // VENTANAACTUALIZAR_H
