#include "ventanacontinuar.h"
#include "ui_ventanacontinuar.h"
#include "ventanaactualizar.h"
#include "ventanajuego.h"
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMenu>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QIODevice>

ventanacontinuar::ventanacontinuar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ventanacontinuar)
{
    ui->setupUi(this);
    generarJugadores();
}

void ventanacontinuar::generarJugadores()
{
    QFile archivo("usuarios.txt");
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"No se puo abrir usuarios.txt";
        return;
    }
    QTextStream in(&archivo);
    QVBoxLayout *layoutPrincipal = new QVBoxLayout;

    while (!in.atEnd()){
        QString linea = in.readLine();
        QStringList datos = linea.split("|",Qt::SkipEmptyParts);
        if (datos.size()<3) continue;

        QString nombre=datos[0].trimmed();
        QString ganadas=datos[1].trimmed();
        QString perdidas=datos[2].trimmed();

        QWidget *contenedor = new QWidget;
        QVBoxLayout *layoutContenedor = new QVBoxLayout(contenedor);

        QLabel *labelNombre = new QLabel("Nombre: " + nombre);
        QLabel *labelGanadas = new QLabel(ganadas);
        QLabel *labelPerdidas = new QLabel(perdidas);

        layoutContenedor->addWidget(labelNombre);
        layoutContenedor->addWidget(labelGanadas);
        layoutContenedor->addWidget(labelPerdidas);

        QGroupBox *grupoBotones = new QGroupBox("Opciones");
        QHBoxLayout *layoutBotones = new QHBoxLayout;

        QPushButton *btnJugar = new QPushButton("Jugar");
        btnJugar->setProperty("nombre", nombre);
        connect(btnJugar, &QPushButton::clicked, this, &ventanacontinuar::jugarConUsuario);
        QPushButton *btnEditar = new QPushButton("Editar nombre");
        btnEditar->setProperty("nombre",nombre);
        connect(btnEditar, &QPushButton::clicked,this,&ventanacontinuar::editarUsuario);
        QPushButton *btnEliminar = new QPushButton("Eliminar");
        btnEliminar->setProperty("nombre",nombre);
        connect(btnEliminar, &QPushButton::clicked,this, &ventanacontinuar::eliminarUsuario);

        layoutBotones->addWidget(btnJugar);
        layoutBotones->addWidget(btnEditar);
        layoutBotones->addWidget(btnEliminar);

        grupoBotones->setLayout(layoutBotones);

        layoutContenedor->addWidget(grupoBotones);
        layoutPrincipal->addWidget(contenedor);
    }
    archivo.close();

    QWidget *widgetScroll = new QWidget;
    widgetScroll->setLayout(layoutPrincipal);
    ui->scrollArea->setWidget(widgetScroll);
    ui->scrollArea->setWidgetResizable(true);
}

ventanacontinuar::~ventanacontinuar()
{
    delete ui;
}

void ventanacontinuar::eliminarUsuario()
{
    QPushButton *boton=qobject_cast<QPushButton*>(sender());
    if (!boton) return;

    QString nombre = boton->property("nombre").toString();
    qDebug()<<"Eliminando usuario"<<nombre;

    QFile archivo("usuarios.txt");
    QFile archivoTemporal("usuarios_tmp.txt");

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text) ||
        !archivoTemporal.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir archivos para eliminar.";
        return;
    }

    QTextStream in(&archivo);
    QTextStream out(&archivoTemporal);

    while (!in.atEnd()) {
        QString linea = in.readLine();
        QString nombreEnLinea = linea.section(" |",0,0).trimmed();

        if (nombreEnLinea != nombre){
            out << linea << "\n";
        }else{
            qDebug()<<"Linea Eliminada: "<<linea;
        }
    }

    archivo.close();
    archivoTemporal.close();

    archivo.remove(); // Borra el original
    archivoTemporal.rename("usuarios.txt"); // Renombra el temporal

    // Reinicia la vista
    QWidget *widgetScroll = ui->scrollArea->widget();
    if (widgetScroll) delete widgetScroll;

    generarJugadores();
}

void ventanacontinuar::editarUsuario()
{
    QPushButton *boton = qobject_cast<QPushButton*>(sender());
    if (!boton) return;

    QString nombre = boton->property("nombre").toString();

    ventanaActualizar *ventana = new ventanaActualizar(nombre);
    connect(ventana, &ventanaActualizar::nombreActualizado, this, &ventanacontinuar::actualizarListaUsuarios);
    ventana->setAttribute(Qt::WA_DeleteOnClose); // Se borra sola al cerrarse
    ventana->show();
}

void ventanacontinuar::actualizarListaUsuarios(){
    QWidget *widgetScroll = ui->scrollArea->widget();
    if (widgetScroll)
        delete widgetScroll;

    generarJugadores();
}

void ventanacontinuar::jugarConUsuario()
{
    QPushButton *boton = qobject_cast<QPushButton*>(sender());
    if (!boton) return;

    QString nombre = boton->property("nombre").toString();
    qDebug() << "Abriendo juego con: " << nombre;

    ventanaJuego *ventana = new ventanaJuego(nombre);
    connect(ventana, &ventanaJuego::partidaTerminada, this, &ventanacontinuar::actualizarListaUsuarios);
    ventana->setAttribute(Qt::WA_DeleteOnClose);
    ventana->show();
}



void ventanacontinuar::on_btnRegresar_clicked()
{
    this->close();
}


void ventanacontinuar::on_btnactualizar_clicked()
{
    editarUsuario();
}




void ventanacontinuar::on_btnjugar_clicked()
{

}

