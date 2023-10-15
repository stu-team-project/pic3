/********************************************************************************
** Form generated from reading UI file 'T_Project.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T_PROJECT_H
#define UI_T_PROJECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_T_ProjectClass
{
public:
    QAction *actionBrowse;
    QWidget *centralWidget;
    QGroupBox *groupBoxMenu;
    QPushButton *pushButtonShow;
    QPushButton *pushButtonCenzored;
    QPushButton *pushButtonEdge;
    QPushButton *pushButtonBlur;
    QPushButton *pushButtonKomiks;
    QPushButton *pushButtonCmyk;
    QPushButton *pushButtonDepthmap;
    QPushButton *pushButtonColorInverse;
    QPushButton *pushButtonBlackNWhite;
    QPushButton *pushButtonISONoise;
    QPushButton *pushButtonMirrorVertical;
    QPushButton *pushButtonMirrorHorizontal;
    QPushButton *pushButtonFire;
    QPushButton *pushButtonPuzzle;
    QPushButton *pushButtonFisheye;
    QPushButton *pushButtonSave;
    QGroupBox *groupBoxOriginPic;
    QGraphicsView *graphicsView_OriginPic;
    QGroupBox *groupBoxNewPic;
    QGraphicsView *graphicsView_NewPic;
    QLineEdit *lineEditHint;
    QLabel *labelHint;
    QMenuBar *menuBar;
    QMenu *menuOpen;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *T_ProjectClass)
    {
        if (T_ProjectClass->objectName().isEmpty())
            T_ProjectClass->setObjectName(QString::fromUtf8("T_ProjectClass"));
        T_ProjectClass->resize(1831, 1070);
        actionBrowse = new QAction(T_ProjectClass);
        actionBrowse->setObjectName(QString::fromUtf8("actionBrowse"));
        centralWidget = new QWidget(T_ProjectClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBoxMenu = new QGroupBox(centralWidget);
        groupBoxMenu->setObjectName(QString::fromUtf8("groupBoxMenu"));
        groupBoxMenu->setGeometry(QRect(39, 39, 111, 801));
        pushButtonShow = new QPushButton(groupBoxMenu);
        pushButtonShow->setObjectName(QString::fromUtf8("pushButtonShow"));
        pushButtonShow->setGeometry(QRect(20, 30, 75, 24));
        pushButtonCenzored = new QPushButton(groupBoxMenu);
        pushButtonCenzored->setObjectName(QString::fromUtf8("pushButtonCenzored"));
        pushButtonCenzored->setGeometry(QRect(20, 80, 75, 24));
        pushButtonEdge = new QPushButton(groupBoxMenu);
        pushButtonEdge->setObjectName(QString::fromUtf8("pushButtonEdge"));
        pushButtonEdge->setGeometry(QRect(20, 110, 75, 24));
        pushButtonBlur = new QPushButton(groupBoxMenu);
        pushButtonBlur->setObjectName(QString::fromUtf8("pushButtonBlur"));
        pushButtonBlur->setGeometry(QRect(20, 140, 75, 24));
        pushButtonKomiks = new QPushButton(groupBoxMenu);
        pushButtonKomiks->setObjectName(QString::fromUtf8("pushButtonKomiks"));
        pushButtonKomiks->setGeometry(QRect(20, 170, 75, 24));
        pushButtonCmyk = new QPushButton(groupBoxMenu);
        pushButtonCmyk->setObjectName(QString::fromUtf8("pushButtonCmyk"));
        pushButtonCmyk->setGeometry(QRect(20, 200, 75, 24));
        pushButtonDepthmap = new QPushButton(groupBoxMenu);
        pushButtonDepthmap->setObjectName(QString::fromUtf8("pushButtonDepthmap"));
        pushButtonDepthmap->setGeometry(QRect(20, 230, 75, 24));
        pushButtonColorInverse = new QPushButton(groupBoxMenu);
        pushButtonColorInverse->setObjectName(QString::fromUtf8("pushButtonColorInverse"));
        pushButtonColorInverse->setGeometry(QRect(14, 260, 91, 24));
        pushButtonBlackNWhite = new QPushButton(groupBoxMenu);
        pushButtonBlackNWhite->setObjectName(QString::fromUtf8("pushButtonBlackNWhite"));
        pushButtonBlackNWhite->setGeometry(QRect(14, 290, 91, 24));
        pushButtonISONoise = new QPushButton(groupBoxMenu);
        pushButtonISONoise->setObjectName(QString::fromUtf8("pushButtonISONoise"));
        pushButtonISONoise->setGeometry(QRect(14, 320, 91, 24));
        pushButtonMirrorVertical = new QPushButton(groupBoxMenu);
        pushButtonMirrorVertical->setObjectName(QString::fromUtf8("pushButtonMirrorVertical"));
        pushButtonMirrorVertical->setGeometry(QRect(14, 350, 91, 24));
        pushButtonMirrorHorizontal = new QPushButton(groupBoxMenu);
        pushButtonMirrorHorizontal->setObjectName(QString::fromUtf8("pushButtonMirrorHorizontal"));
        pushButtonMirrorHorizontal->setGeometry(QRect(10, 380, 101, 24));
        pushButtonFire = new QPushButton(groupBoxMenu);
        pushButtonFire->setObjectName(QString::fromUtf8("pushButtonFire"));
        pushButtonFire->setGeometry(QRect(10, 410, 101, 24));
        pushButtonPuzzle = new QPushButton(groupBoxMenu);
        pushButtonPuzzle->setObjectName(QString::fromUtf8("pushButtonPuzzle"));
        pushButtonPuzzle->setGeometry(QRect(10, 440, 101, 24));
        pushButtonFisheye = new QPushButton(groupBoxMenu);
        pushButtonFisheye->setObjectName(QString::fromUtf8("pushButtonFisheye"));
        pushButtonFisheye->setGeometry(QRect(10, 470, 91, 24));
        pushButtonSave = new QPushButton(groupBoxMenu);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(20, 550, 75, 24));
        groupBoxOriginPic = new QGroupBox(centralWidget);
        groupBoxOriginPic->setObjectName(QString::fromUtf8("groupBoxOriginPic"));
        groupBoxOriginPic->setGeometry(QRect(150, 40, 801, 801));
        graphicsView_OriginPic = new QGraphicsView(groupBoxOriginPic);
        graphicsView_OriginPic->setObjectName(QString::fromUtf8("graphicsView_OriginPic"));
        graphicsView_OriginPic->setGeometry(QRect(10, 20, 791, 781));
        groupBoxNewPic = new QGroupBox(centralWidget);
        groupBoxNewPic->setObjectName(QString::fromUtf8("groupBoxNewPic"));
        groupBoxNewPic->setGeometry(QRect(950, 40, 801, 801));
        graphicsView_NewPic = new QGraphicsView(groupBoxNewPic);
        graphicsView_NewPic->setObjectName(QString::fromUtf8("graphicsView_NewPic"));
        graphicsView_NewPic->setGeometry(QRect(0, 20, 801, 781));
        lineEditHint = new QLineEdit(centralWidget);
        lineEditHint->setObjectName(QString::fromUtf8("lineEditHint"));
        lineEditHint->setGeometry(QRect(160, 850, 1591, 21));
        labelHint = new QLabel(centralWidget);
        labelHint->setObjectName(QString::fromUtf8("labelHint"));
        labelHint->setGeometry(QRect(110, 850, 31, 20));
        T_ProjectClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(T_ProjectClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1831, 22));
        menuOpen = new QMenu(menuBar);
        menuOpen->setObjectName(QString::fromUtf8("menuOpen"));
        T_ProjectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(T_ProjectClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        T_ProjectClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(T_ProjectClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        T_ProjectClass->setStatusBar(statusBar);

        menuBar->addAction(menuOpen->menuAction());
        menuOpen->addAction(actionBrowse);

        retranslateUi(T_ProjectClass);

        QMetaObject::connectSlotsByName(T_ProjectClass);
    } // setupUi

    void retranslateUi(QMainWindow *T_ProjectClass)
    {
        T_ProjectClass->setWindowTitle(QCoreApplication::translate("T_ProjectClass", "T_Project", nullptr));
        actionBrowse->setText(QCoreApplication::translate("T_ProjectClass", "Browse", nullptr));
        groupBoxMenu->setTitle(QCoreApplication::translate("T_ProjectClass", "Menu", nullptr));
        pushButtonShow->setText(QCoreApplication::translate("T_ProjectClass", "Show", nullptr));
        pushButtonCenzored->setText(QCoreApplication::translate("T_ProjectClass", "Cenzored", nullptr));
        pushButtonEdge->setText(QCoreApplication::translate("T_ProjectClass", "Edge", nullptr));
        pushButtonBlur->setText(QCoreApplication::translate("T_ProjectClass", "Blur", nullptr));
        pushButtonKomiks->setText(QCoreApplication::translate("T_ProjectClass", "Komiks", nullptr));
        pushButtonCmyk->setText(QCoreApplication::translate("T_ProjectClass", "Cmyk", nullptr));
        pushButtonDepthmap->setText(QCoreApplication::translate("T_ProjectClass", "Depthmap", nullptr));
        pushButtonColorInverse->setText(QCoreApplication::translate("T_ProjectClass", "Color inverse", nullptr));
        pushButtonBlackNWhite->setText(QCoreApplication::translate("T_ProjectClass", "Black n White", nullptr));
        pushButtonISONoise->setText(QCoreApplication::translate("T_ProjectClass", "ISO Noise", nullptr));
        pushButtonMirrorVertical->setText(QCoreApplication::translate("T_ProjectClass", "Mirror Vertical", nullptr));
        pushButtonMirrorHorizontal->setText(QCoreApplication::translate("T_ProjectClass", "Mirror Horizontal", nullptr));
        pushButtonFire->setText(QCoreApplication::translate("T_ProjectClass", "Fire", nullptr));
        pushButtonPuzzle->setText(QCoreApplication::translate("T_ProjectClass", "Puzzle", nullptr));
        pushButtonFisheye->setText(QCoreApplication::translate("T_ProjectClass", "Fisheye", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("T_ProjectClass", "Save", nullptr));
        groupBoxOriginPic->setTitle(QCoreApplication::translate("T_ProjectClass", "Original Picture", nullptr));
        groupBoxNewPic->setTitle(QCoreApplication::translate("T_ProjectClass", "New Picture", nullptr));
        labelHint->setText(QCoreApplication::translate("T_ProjectClass", "Hint", nullptr));
        menuOpen->setTitle(QCoreApplication::translate("T_ProjectClass", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class T_ProjectClass: public Ui_T_ProjectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T_PROJECT_H
