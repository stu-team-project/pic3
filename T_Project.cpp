#include "T_Project.h"
//#include "OriginPicture.h"
#include <fstream>
#include <QFileDialog>
#include <string>

#include <QApplication>
#include <QMenuBar>
#include <QInputDialog>
#include <QImageWriter>
#include <QFileDialog>
#include <QColorDialog>

T_Project::T_Project(QWidget *parent)
    : QMainWindow(parent), 
    oPic(new OriginPicture(this))
    //filter(new Filters(this))
    //censore(new censored(oPic))
{
    setCentralWidget(oPic);
    createActions();
    createMenus();

    setWindowTitle(tr("STU_TeamProject"));

    //oPic->setVectorColor(this->getVectorColor2D());
    //censore->setVectorColor(this->getVectorColor2D());

    resize(1000, 1000);
}

T_Project::~T_Project()
{} 

void T_Project::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, &QAction::triggered, this, &T_Project::open);

    CenzoredAct = new QAction(tr("&Cenzored..."), this);
    connect(CenzoredAct, &QAction::triggered, oPic, &OriginPicture::censore);

    FisheyeAct = new QAction(tr("&Fisheye..."), this);
    connect(FisheyeAct, &QAction::triggered, oPic, &OriginPicture::fisheye);

    CMYKAct = new QAction(tr("&CMYK..."), this);
    connect(CMYKAct, &QAction::triggered, oPic, &OriginPicture::cmyk);
}

void T_Project::createMenus()
{

    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(openAct);
    

    filterMenu = new QMenu(tr("&Filters"), this);
    filterMenu->addAction(FisheyeAct);
    filterMenu->addAction(CMYKAct);
    filterMenu->addAction(CenzoredAct);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(filterMenu);
}

void T_Project::open() 
{
    
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());

    oPic->openImage(fileName);
}




