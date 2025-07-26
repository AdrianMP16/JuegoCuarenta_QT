/********************************************************************************
** Form generated from reading UI file 'ventanajuego.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAJUEGO_H
#define UI_VENTANAJUEGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ventanaJuego
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTurnoActual;
    QLabel *labelMesa;
    QLabel *labelMensajes;
    QLabel *labelPuntajes;
    QLabel *labelCarton;
    QGroupBox *layoutCartasJugador;
    QHBoxLayout *horizontalLayout;
    QWidget *contenedorCartasJugador;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnCarta2;
    QPushButton *btnCarta3;
    QPushButton *btnCarta5;
    QPushButton *btnCarta4;
    QPushButton *btnCarta1;
    QPushButton *btnSalir;

    void setupUi(QWidget *ventanaJuego)
    {
        if (ventanaJuego->objectName().isEmpty())
            ventanaJuego->setObjectName("ventanaJuego");
        ventanaJuego->resize(743, 428);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        QBrush brush1(QColor(255, 255, 127, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush1);
        QBrush brush2(QColor(255, 255, 254, 255));
        brush2.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Light, brush2);
        QBrush brush3(QColor(255, 255, 190, 255));
        brush3.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Midlight, brush3);
        QBrush brush4(QColor(127, 127, 63, 255));
        brush4.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Dark, brush4);
        QBrush brush5(QColor(170, 170, 85, 255));
        brush5.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::BrightText, brush6);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush6);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Shadow, brush);
        QBrush brush7(QColor(255, 255, 191, 255));
        brush7.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipBase, brush8);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush9(QColor(0, 0, 0, 127));
        brush9.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush9);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Accent, brush6);
#endif
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Light, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Midlight, brush3);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Dark, brush4);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::BrightText, brush6);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush6);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::AlternateBase, brush7);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipBase, brush8);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush9);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Accent, brush6);
#endif
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Light, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Midlight, brush3);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Dark, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::BrightText, brush6);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::AlternateBase, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipBase, brush8);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush10(QColor(127, 127, 63, 127));
        brush10.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush10);
#endif
        QBrush brush11(QColor(255, 255, 203, 255));
        brush11.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Accent, brush11);
#endif
        ventanaJuego->setPalette(palette);
        verticalLayout = new QVBoxLayout(ventanaJuego);
        verticalLayout->setObjectName("verticalLayout");
        labelTurnoActual = new QLabel(ventanaJuego);
        labelTurnoActual->setObjectName("labelTurnoActual");

        verticalLayout->addWidget(labelTurnoActual);

        labelMesa = new QLabel(ventanaJuego);
        labelMesa->setObjectName("labelMesa");

        verticalLayout->addWidget(labelMesa);

        labelMensajes = new QLabel(ventanaJuego);
        labelMensajes->setObjectName("labelMensajes");

        verticalLayout->addWidget(labelMensajes);

        labelPuntajes = new QLabel(ventanaJuego);
        labelPuntajes->setObjectName("labelPuntajes");

        verticalLayout->addWidget(labelPuntajes);

        labelCarton = new QLabel(ventanaJuego);
        labelCarton->setObjectName("labelCarton");

        verticalLayout->addWidget(labelCarton);

        layoutCartasJugador = new QGroupBox(ventanaJuego);
        layoutCartasJugador->setObjectName("layoutCartasJugador");
        horizontalLayout = new QHBoxLayout(layoutCartasJugador);
        horizontalLayout->setObjectName("horizontalLayout");
        contenedorCartasJugador = new QWidget(layoutCartasJugador);
        contenedorCartasJugador->setObjectName("contenedorCartasJugador");
        horizontalLayout_2 = new QHBoxLayout(contenedorCartasJugador);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnCarta2 = new QPushButton(contenedorCartasJugador);
        btnCarta2->setObjectName("btnCarta2");

        horizontalLayout_2->addWidget(btnCarta2);

        btnCarta3 = new QPushButton(contenedorCartasJugador);
        btnCarta3->setObjectName("btnCarta3");

        horizontalLayout_2->addWidget(btnCarta3);

        btnCarta5 = new QPushButton(contenedorCartasJugador);
        btnCarta5->setObjectName("btnCarta5");

        horizontalLayout_2->addWidget(btnCarta5);

        btnCarta4 = new QPushButton(contenedorCartasJugador);
        btnCarta4->setObjectName("btnCarta4");

        horizontalLayout_2->addWidget(btnCarta4);

        btnCarta1 = new QPushButton(contenedorCartasJugador);
        btnCarta1->setObjectName("btnCarta1");

        horizontalLayout_2->addWidget(btnCarta1);


        horizontalLayout->addWidget(contenedorCartasJugador);


        verticalLayout->addWidget(layoutCartasJugador);

        btnSalir = new QPushButton(ventanaJuego);
        btnSalir->setObjectName("btnSalir");

        verticalLayout->addWidget(btnSalir);


        retranslateUi(ventanaJuego);

        QMetaObject::connectSlotsByName(ventanaJuego);
    } // setupUi

    void retranslateUi(QWidget *ventanaJuego)
    {
        ventanaJuego->setWindowTitle(QCoreApplication::translate("ventanaJuego", "Form", nullptr));
        labelTurnoActual->setText(QCoreApplication::translate("ventanaJuego", "TextLabel", nullptr));
        labelMesa->setText(QCoreApplication::translate("ventanaJuego", "TextLabel", nullptr));
        labelMensajes->setText(QCoreApplication::translate("ventanaJuego", "TextLabel", nullptr));
        labelPuntajes->setText(QCoreApplication::translate("ventanaJuego", "TextLabel", nullptr));
        labelCarton->setText(QCoreApplication::translate("ventanaJuego", "TextLabel", nullptr));
        layoutCartasJugador->setTitle(QCoreApplication::translate("ventanaJuego", "Tus Cartas", nullptr));
        btnCarta2->setText(QCoreApplication::translate("ventanaJuego", "PushButton", nullptr));
        btnCarta3->setText(QCoreApplication::translate("ventanaJuego", "PushButton", nullptr));
        btnCarta5->setText(QCoreApplication::translate("ventanaJuego", "PushButton", nullptr));
        btnCarta4->setText(QCoreApplication::translate("ventanaJuego", "PushButton", nullptr));
        btnCarta1->setText(QCoreApplication::translate("ventanaJuego", "PushButton", nullptr));
        btnSalir->setText(QCoreApplication::translate("ventanaJuego", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ventanaJuego: public Ui_ventanaJuego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAJUEGO_H
