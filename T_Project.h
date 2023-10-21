#pragma once

#include <QColor>
#include <QImage>
#include <QPainter>
#include <QSize>
#include <Qstring>
#include <QtWidgets/QMainWindow>
#include "OriginPicture.h"
#include "ui_T_Project.h"

class OriginPicture;

class T_Project : public QMainWindow
{
    Q_OBJECT

public:
    T_Project(QWidget *parent = nullptr);
    ~T_Project();


public slots:
    void open();
    //------------------------------------------
    //void on_pushButtonShow_clicked();
    void on_pushButtonCenzored_clicked();
    void on_pushButtonEdge_clicked();
    void on_pushButtonBlur_clicked();
    void on_pushButtonKomiks_clicked();
    void on_pushButtonCmyk_clicked();
    void on_pushButtonDepthmap_clicked();
    void on_pushButtonColorInverse_clicked();
    void on_pushButtonBlackNWhite_clicked();
    void on_pushButtonISONoise_clicked();
    void on_pushButtonMirrorVertical_clicked();
    void on_pushButtonMirrorHorizontal_clicked();
    void on_pushButtonFire_clicked();
    void on_pushButtonPuzzle_clicked();
    void on_pushButtonFisheye_clicked();
    void on_pushButtonSave_clicked();
private:
    void createActions();
    void createMenus();

    //Ui::T_ProjectClass ui;
    OriginPicture* oPic;

    QAction* openAct;
    QAction* CenzoredAct;

    QMenu* fileMenu;
    QMenu* filterMenu;
};

