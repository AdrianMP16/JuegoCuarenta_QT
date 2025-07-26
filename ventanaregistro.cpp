#include "ventanaregistro.h"
#include "ui_ventanaregistro.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

VentanaRegistro::VentanaRegistro(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VentanaRegistro)
{
    ui->setupUi(this);
}

VentanaRegistro::~VentanaRegistro()
{
    delete ui;
}

void VentanaRegistro::on_btnGuardar_clicked()
{
    QString nombre = ui->nombreLineEdit->text().trimmed();

    if (nombre.isEmpty()) {
        QMessageBox::warning(this, "Error", "El nombre no puede estar vacío.");
        return;
    }

    QFile archivo("usuarios.txt");

    // Verificar si el usuario ya existe
    if (archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&archivo);
        while (!in.atEnd()) {
            QString linea = in.readLine();
            if (linea.contains(nombre + " ")) {
                QMessageBox::warning(this, "Error", "Ese usuario ya existe.");
                archivo.close();
                return;
            }
        }
        archivo.close();
    }

    // Agregar nuevo usuario
    if (archivo.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&archivo);
        out << nombre << " | Ganadas: 0 | Perdidas: 0\n";
        archivo.close();
        QMessageBox::information(this, "Éxito", "Usuario guardado.");
        this->close();  // cierra la ventana si deseas
    } else {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo.");
    }
}



void VentanaRegistro::on_btnRegresar_clicked()
{
    this->close();
}


