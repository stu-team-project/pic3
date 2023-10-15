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
    //void openPic();
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

//class OriginPicture
//{
//public:
//    OriginPicture(QSize imgSize);
//    ~OriginPicture();
//
//    //
//    //inspiration from computer graphics
//    //
//   // void resizeWidget(QSize size);
//    void setPainter() { painter = new QPainter(img); }
//    void setDataPtr() { data = img->bits(); }
//
//private:
//    QImage* img = nullptr;
//
//    //
//    //inspiration from computer graphics
//    //
//    QPainter* painter = nullptr;
//    uchar* data = nullptr;
//};

//class pixel
//{
//public:
//    pixel();
//    ~pixel();
//
//    void setRed(int r) { red = r; };
//    void setGreen(int g) { green = g; };
//    void setBlue(int b) { blue = b; };
//
//    int getRed() { return red; };
//    int getGreen() { return green; };
//    int getBlue() { return blue; };
//private:
//    int red, green, blue;
//};

//class T_Picture
//{
//public:
//	T_Picture();
//	~T_Picture();
//    //void load_Picture(QString name, T_Picture *picture);
//    //void write_Picture(QString name, T_Picture *picture);
//    //void show_Picture();
//
//    /*void setWidth(int w)             { width = w; };
//    void setHeight(int h)            { height = h; };
//    void setMaxValueOfPixel(int max) { maxValueOfPixel = max; };
//    void setTransparency(int T)      { transparency = T; };
//
//    int getWidth()           { return width; };
//    int getHeight()          { return height; };
//    int getMaxValueOfPixel() { return maxValueOfPixel; };
//    int getTransparency()    { return transparency; };*/
//    
//    //void addPixel_ToVec(pixel p)         { T_vec.append(p); };
//    //pixel getPixel_fromVec(int position) { return T_vec.at(position); };
//
//    //void setPicture();
//
//    //void setPixelPic(int x, int y, QColor col);
//private:
//    /*int width, height;
//    int maxValueOfPixel;
//    int transparency;*/
//    //QVector<pixel> T_vec;
//    //QVector<QColor> T_ColPix;
//    
//    QImage* Picture;
//};

