#include "T_Project.h"
#include "OriginPicture.h"
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
    : QMainWindow(parent), oPic(new OriginPicture(this))
{
    //ui.setupUi(this);

    setCentralWidget(oPic);

    createActions();
    createMenus();

    setWindowTitle(tr("STU_TeamProject"));


    resize(1000, 1000);
}

T_Project::~T_Project()
{}


void T_Project::on_pushButtonCenzored_clicked()
{
}

void T_Project::on_pushButtonEdge_clicked()
{
}

void T_Project::on_pushButtonBlur_clicked()
{
}

void T_Project::on_pushButtonKomiks_clicked()
{
}

void T_Project::on_pushButtonCmyk_clicked()
{
}

void T_Project::on_pushButtonDepthmap_clicked()
{
}

void T_Project::on_pushButtonColorInverse_clicked()
{
}

void T_Project::on_pushButtonBlackNWhite_clicked()
{
}

void T_Project::on_pushButtonISONoise_clicked()
{
}

void T_Project::on_pushButtonMirrorVertical_clicked()
{
}

void T_Project::on_pushButtonMirrorHorizontal_clicked()
{
}

void T_Project::on_pushButtonFire_clicked()
{
}

void T_Project::on_pushButtonPuzzle_clicked()
{
}

void T_Project::on_pushButtonFisheye_clicked()
{
}

void T_Project::on_pushButtonSave_clicked()
{
}

void T_Project::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, &QAction::triggered, this, &T_Project::open);

    CenzoredAct = new QAction(tr("&Cenzored..."), this);
    connect(CenzoredAct, &QAction::triggered, oPic, &OriginPicture::cenzored);
}

void T_Project::createMenus()
{

    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(openAct);
    

    filterMenu = new QMenu(tr("&Filters"), this);
    filterMenu->addAction(CenzoredAct);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(filterMenu);
}

void T_Project::open() 
{
    
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());

    oPic->openImage(fileName);
}




