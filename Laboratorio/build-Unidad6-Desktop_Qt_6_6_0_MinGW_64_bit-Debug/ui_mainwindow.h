/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QDoubleSpinBox *Num_Yo;
    QLabel *radio;
    QPushButton *add;
    QPushButton *continue_2;
    QLabel *label_2;
    QDoubleSpinBox *Num_Xo;
    QDoubleSpinBox *masa_2;
    QLabel *Xo;
    QLabel *Yo;
    QLabel *label;
    QDoubleSpinBox *velx;
    QLabel *masa;
    QDoubleSpinBox *vely;
    QDoubleSpinBox *radio_2;
    QPushButton *continue_3;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1409, 750);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 80, 168, 242));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Num_Yo = new QDoubleSpinBox(layoutWidget);
        Num_Yo->setObjectName("Num_Yo");
        Num_Yo->setMinimum(-10000.000000000000000);
        Num_Yo->setMaximum(10000.000000000000000);
        Num_Yo->setSingleStep(0.010000000000000);

        gridLayout->addWidget(Num_Yo, 1, 1, 1, 1);

        radio = new QLabel(layoutWidget);
        radio->setObjectName("radio");

        gridLayout->addWidget(radio, 3, 0, 1, 1);

        add = new QPushButton(layoutWidget);
        add->setObjectName("add");

        gridLayout->addWidget(add, 6, 0, 1, 1);

        continue_2 = new QPushButton(layoutWidget);
        continue_2->setObjectName("continue_2");

        gridLayout->addWidget(continue_2, 6, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 5, 0, 1, 1);

        Num_Xo = new QDoubleSpinBox(layoutWidget);
        Num_Xo->setObjectName("Num_Xo");
        Num_Xo->setMinimum(-10000.000000000000000);
        Num_Xo->setMaximum(10000.000000000000000);
        Num_Xo->setSingleStep(0.010000000000000);

        gridLayout->addWidget(Num_Xo, 0, 1, 1, 1);

        masa_2 = new QDoubleSpinBox(layoutWidget);
        masa_2->setObjectName("masa_2");
        masa_2->setMinimum(-10000.000000000000000);
        masa_2->setMaximum(10000.000000000000000);
        masa_2->setSingleStep(0.010000000000000);

        gridLayout->addWidget(masa_2, 2, 1, 1, 1);

        Xo = new QLabel(layoutWidget);
        Xo->setObjectName("Xo");

        gridLayout->addWidget(Xo, 0, 0, 1, 1);

        Yo = new QLabel(layoutWidget);
        Yo->setObjectName("Yo");
        Yo->setEnabled(true);

        gridLayout->addWidget(Yo, 1, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 4, 0, 1, 1);

        velx = new QDoubleSpinBox(layoutWidget);
        velx->setObjectName("velx");
        velx->setMinimum(-10000.000000000000000);
        velx->setMaximum(10000.000000000000000);
        velx->setSingleStep(0.010000000000000);

        gridLayout->addWidget(velx, 4, 1, 1, 1);

        masa = new QLabel(layoutWidget);
        masa->setObjectName("masa");

        gridLayout->addWidget(masa, 2, 0, 1, 1);

        vely = new QDoubleSpinBox(layoutWidget);
        vely->setObjectName("vely");
        vely->setMinimum(-10000.000000000000000);
        vely->setMaximum(10000.000000000000000);
        vely->setSingleStep(0.010000000000000);

        gridLayout->addWidget(vely, 5, 1, 1, 1);

        radio_2 = new QDoubleSpinBox(layoutWidget);
        radio_2->setObjectName("radio_2");
        radio_2->setMinimum(-10000.000000000000000);
        radio_2->setMaximum(10000.000000000000000);
        radio_2->setSingleStep(0.010000000000000);

        gridLayout->addWidget(radio_2, 3, 1, 1, 1);

        continue_3 = new QPushButton(layoutWidget);
        continue_3->setObjectName("continue_3");

        gridLayout->addWidget(continue_3, 7, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(200, 10, 1101, 661));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        radio->setText(QCoreApplication::translate("MainWindow", "Radio", nullptr));
        add->setText(QCoreApplication::translate("MainWindow", "Agregar", nullptr));
        continue_2->setText(QCoreApplication::translate("MainWindow", "Continuar", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Vel Y ini", nullptr));
        Xo->setText(QCoreApplication::translate("MainWindow", "Pos X ini", nullptr));
        Yo->setText(QCoreApplication::translate("MainWindow", "Pos y ini", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Vel X Ini", nullptr));
        masa->setText(QCoreApplication::translate("MainWindow", "Masa", nullptr));
        continue_3->setText(QCoreApplication::translate("MainWindow", "Reiniciar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
