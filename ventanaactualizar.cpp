#include "ventanaactualizar.h"
#include "ui_ventanaactualizar.h"
#include <QMessageBox>
#include <QFile>

ventanaActualizar::ventanaActualizar(QString nombreJugador, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ventanaActualizar)
{
    ui->setupUi(this);
    ui->lineaNombreActual->setText(nombreJugador);
}

ventanaActualizar::~ventanaActualizar()
{
    delete ui;
}

void ventanaActualizar::on_btnRegresar_clicked()
{
    this -> close();
}


void ventanaActualizar::on_btnGuardar_clicked()
{
    QString nombreActual = ui->lineaNombreActual->text().trimmed();
    QString nuevoNombre = ui->lineaNuevoNombre->text().trimmed();

    if (nuevoNombre.isEmpty()) {
        QMessageBox::warning(this, "Error", "Debes ingresar un nuevo nombre.");
        return;
    }

    QFile archivo("usuarios.txt");
    QFile archivoTemp("usuarios_tmp.txt");

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text) ||
        !archivoTemp.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo.");
        return;
    }

    QTextStream in(&archivo);
    QTextStream out(&archivoTemp);

    while (!in.atEnd()) {
        QString linea = in.readLine();
        QString nombreEnLinea = linea.section(" |", 0, 0).trimmed();

        if (nombreEnLinea == nombreActual) {
            QString nuevaLinea = linea;
            nuevaLinea.replace(nombreEnLinea, nuevoNombre); // Cambia solo el nombre
            out << nuevaLinea << "\n";
        } else {
            out << linea << "\n";
        }
    }

    archivo.close();
    archivoTemp.close();

    archivo.remove();
    archivoTemp.rename("usuarios.txt");
    emit nombreActualizado();

    QMessageBox::information(this, "Listo", "Nombre actualizado.");
    this->close();

    this->close();
}

