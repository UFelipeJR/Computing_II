/********************************************************************************
** Form generated from reading UI file 'videojuego.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOJUEGO_H
#define UI_VIDEOJUEGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_videojuego
{
public:
    QWidget *centralwidget;
    QGraphicsView *main_scene;

    void setupUi(QMainWindow *videojuego)
    {
        if (videojuego->objectName().isEmpty())
            videojuego->setObjectName("videojuego");
        videojuego->resize(800, 600);
        videojuego->setMaximumSize(QSize(1280, 720));
        centralwidget = new QWidget(videojuego);
        centralwidget->setObjectName("centralwidget");
        main_scene = new QGraphicsView(centralwidget);
        main_scene->setObjectName("main_scene");
        main_scene->setGeometry(QRect(0, 0, 600, 800));
        videojuego->setCentralWidget(centralwidget);

        retranslateUi(videojuego);

        QMetaObject::connectSlotsByName(videojuego);
    } // setupUi

    void retranslateUi(QMainWindow *videojuego)
    {
        videojuego->setWindowTitle(QCoreApplication::translate("videojuego", "videojuego", nullptr));
    } // retranslateUi

};

namespace Ui {
    class videojuego: public Ui_videojuego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOJUEGO_H
