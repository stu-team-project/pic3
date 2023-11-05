#include "T_Project.h"

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
{
    setCentralWidget(oPic);
    createActions();
    createMenus();

    setWindowTitle(tr("STU_TeamProject"));

    resize(1000, 1000);
}

T_Project::~T_Project()
{} 

void T_Project::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, &QAction::triggered, this, &T_Project::open);

    saveAct = new QAction(tr("&Save..."), this);
    saveAct->setShortcuts(QKeySequence::Save);
    connect(saveAct, &QAction::triggered, this, &T_Project::save);

    CenzoredAct = new QAction(tr("&Cenzored..."), this);
    connect(CenzoredAct, &QAction::triggered, oPic, &OriginPicture::censore);

    BlackAndWhiteAct = new QAction(tr("&BlackAndWhite..."), this);
    connect(BlackAndWhiteAct, &QAction::triggered, oPic, &OriginPicture::blackAndWhite);

    InverseAct = new QAction(tr("&Inverse..."), this);
    connect(InverseAct, &QAction::triggered, oPic, &OriginPicture::inverse);

    BlurAct = new QAction(tr("&Blur..."), this);
    connect(BlurAct, &QAction::triggered, oPic, &OriginPicture::blur);

    FisheyeAct = new QAction(tr("&Fisheye..."), this);
    connect(FisheyeAct, &QAction::triggered, oPic, &OriginPicture::fisheye);

    CMYKAct = new QAction(tr("&CMYK..."), this);
    connect(CMYKAct, &QAction::triggered, oPic, &OriginPicture::cmyk);
}

void T_Project::createMenus()
{

    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    

    filterMenu = new QMenu(tr("&Filters"), this);
    filterMenu->addAction(FisheyeAct);
    filterMenu->addAction(CMYKAct);
    filterMenu->addAction(CenzoredAct);
    filterMenu->addAction(BlackAndWhiteAct);
    filterMenu->addAction(InverseAct);
    filterMenu->addAction(BlurAct);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(filterMenu);
}

void T_Project::open() 
{
    
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());

    oPic->openImage(fileName);
}

void T_Project::save()
{
    QByteArray fileFormat = "ppm";

    QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
        initialPath,
        tr("%1 Files (*.%2);;All Files (*)")
        .arg(QString::fromLatin1(fileFormat.toUpper()))
        .arg(QString::fromLatin1(fileFormat)));
    if (fileName.isEmpty())
        return;

    oPic->saveImage(fileName);
}