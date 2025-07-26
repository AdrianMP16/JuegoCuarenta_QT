#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication> //ejecuta quit()

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap fondo("C:/Users/Usuario/Desktop/C de carpeta/U/Programación/proyecto bimestral/imagenes/rombito.png");
    if (!fondo.isNull()) {
        ui->imagenlabel1->setPixmap(fondo);
    } else {
        qDebug() << "Error al cargar imagen al iniciar.";
    }
    QPixmap foto("C:/Users/Usuario/Desktop/C de carpeta/U/Programación/proyecto bimestral/imagenes/corazoncito negro.png");
    if (!foto.isNull()) {
        ui->imagenlabel1->setPixmap(foto);
    } else {
        qDebug() << "Error al cargar imagen al iniciar.";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_salirboton_clicked()
{
    QApplication::quit();
}


void MainWindow::on_continuarboton_clicked()
{
    ventanaContinuar = new ventanacontinuar();

    ventanaContinuar->show();
}

void MainWindow::on_btnRegistrar_clicked()
{
    ventanaRegistro = new VentanaRegistro();  // sin `this` para que sea ventana independiente
    //ventanaRegistro->setWindowModality(Qt::ApplicationModal); // si quieres bloquear clics en la principal
    ventanaRegistro->show();
}

void MainWindow::on_imagenlabel1_linkActivated(const QString &link)
{
    QString ruta = "C:/Users/Usuario/Desktop/C de carpeta/U/Programación/proyecto bimestral/imagenes/rombito.png";
    QPixmap fondo(ruta);

    if (!fondo.isNull()) {
        ui->imagenlabel1->setPixmap(fondo);
    } else {
        qDebug() << "Error al cargar la imagen desde: " << ruta;
    }
}


void MainWindow::on_imagenlabel2_linkActivated(const QString &link)
{
    QString ruta = "C:/Users/Usuario/Desktop/C de carpeta/U/Programación/proyecto bimestral/imagenes/corazocito negro.png";
    QPixmap foto(ruta);

    if (!foto.isNull()) {
        ui->imagenlabel1->setPixmap(foto);
    } else {
        qDebug() << "Error al cargar la imagen desde: " << ruta;
    }
}

