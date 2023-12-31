#pragma once

#include <QColor>
#include <QImage>
#include <QPainter>
#include <QSize>
#include <Qstring>
#include <QtWidgets/QMainWindow>

#include "Filters.h"
#include "OriginPicture.h"

class OriginPicture;
class Filters;

class T_Project : public QMainWindow
{
    Q_OBJECT

public:
    T_Project(QWidget *parent = nullptr);
    ~T_Project();

    //QVector<QVector<QColor>>* getVectorColor2D() { return& PixelColor2D; };
public slots:
    void open();
    void save();
    //------------------------------------------

private:
    void createActions();
    void createMenus();

    OriginPicture* oPic;
    Filters* filter;

    QAction* openAct;
    QAction* saveAct;
    QAction* CenzoredAct;
    QAction* BlackAndWhiteAct;
    QAction* InverseAct;
    QList<QAction*> BlurActs;
    QAction* FidingEdgeAct;
    QAction* RedFilterAct;


    QAction* FisheyeAct;
    QAction* CMYKAct;
    QAction* denseCMYKAct;
    QAction* ditherCMYKAct;

    QMenu* blurMasksMenu;
    QMenu* fileMenu;
    QMenu* filterMenu;
    

    //---------------------------------------------
    //QVector<QVector<QColor>> PixelColor2D;
};

