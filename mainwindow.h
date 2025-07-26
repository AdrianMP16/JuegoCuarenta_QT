#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ventanaregistro.h"
#include "ventanacontinuar.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_salirboton_clicked();

    void on_continuarboton_clicked();

    void on_btnRegistrar_clicked();

    void on_imagenlabel1_linkActivated(const QString &link);

    void on_imagenlabel2_linkActivated(const QString &link);

private:
    Ui::MainWindow *ui;
    VentanaRegistro *ventanaRegistro;
    ventanacontinuar *ventanaContinuar;
};
#endif // MAINWINDOW_H
