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
//
//general functions. Maybe they suppose to be in another script
//
//int returnIntegerFromString(std::string& line) {
//    int intToReturn;
//    /*char* cstr = new char[line.length() + 1];
//    std::strcpy(cstr, line.c_str());
//
//    char* number = std::strtok(cstr, " ");
//    intToReturn = atoi(number);
//
//    line.clear();
//    line.append(cstr);
//
//    delete cstr;*/
//    std::string denom = " ";
//    std::string number;
//
//    std::size_t found = line.find(denom);
//    if (found != std::string::npos)
//    {
//        number = line.substr(0,found);
//        intToReturn = atoi(number.c_str());
//        line = line.substr(found + 1);
//    }
//    else
//    {
//        intToReturn = atoi(line.c_str());
//        line.clear();
//    }
//
//    return intToReturn;
//}



//
//End of general functions
//

T_Project::T_Project(QWidget *parent)
    : QMainWindow(parent), oPic(new OriginPicture(this))
{
    //ui.setupUi(this);

    setCentralWidget(oPic);

    createActions();
    createMenus();

    setWindowTitle(tr("STU_TeamProject"));


    resize(500, 500);
    //OriginPicture* oPic = new OriginPicture();
}

T_Project::~T_Project()
{}

//void T_Project::openPic() {
//    QString fileName = QFileDialog::getOpenFileName(this,
//        tr("Open File"), QDir::currentPath());
//    if (!fileName.isEmpty())
//        oPic->openImage(fileName);
//}

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

//OriginPicture::OriginPicture(QSize imgSize)
//{
//    if (imgSize != QSize(0, 0)) {
//        img = new QImage(imgSize, QImage::Format_ARGB32);
//        img->fill(Qt::white);
//        //resizeWidget(img->size());
//        setPainter();
//        setDataPtr();
//    }
//}
//
//OriginPicture::~OriginPicture()
//{
//}

//void OriginPicture::resizeWidget(QSize size)
//{
//    this->resize(size);
//    this->setMinimumSize(size);
//    this->setMaximumSize(size);
//}



//pixel::pixel()
//{
//}
//
//pixel::~pixel()
//{
//}

//T_Picture::T_Picture()
//{
//}
//
//T_Picture::~T_Picture()
//{
//}

//void T_Picture::load_Picture(QString name, T_Picture* picture)
//{
//    int width, height;
//    int red, green, blue;
//    pixel pixelTmp;
//
//    std::string path = "snail.ascii.ppm";
//    std::string line;
//    std::ifstream myfile(path);
//    if (myfile.is_open())
//    {
//        std::getline(myfile,line);
//        if (line == "P3")
//        {
//            qDebug() << "P3";
//        }
//        else
//        {
//            qDebug() << "file is not correct";
//            return;
//        }
//        //
//        //trying to find out if there is some coment in opening file
//        //
//        std::getline(myfile, line);
//        if (line.at(0) == '#')
//        {
//            qDebug() << line.at(0);
//
//            //
//            //if there is comment, we have to read line one more time.
//            //
//            std::getline(myfile, line);
//            width = returnIntegerFromString(line);
//            height = returnIntegerFromString(line);
//        }
//        else
//        {
//            qDebug() << "write width and high of the pics";
//
//            width = returnIntegerFromString(line); 
//            height = returnIntegerFromString(line);
//        }
//
//        picture->setWidth(width);
//        picture->setHeight(height);
//
//        std::getline(myfile, line);
//        picture->setMaxValueOfPixel(atoi(line.c_str()));
//
//        while (std::getline(myfile, line))
//        {
//            while (line.length())
//            {
//                //
//                //we read values for red, green and blue value for pixel
//                //
//                pixelTmp.setRed(returnIntegerFromString(line));
//                pixelTmp.setGreen(returnIntegerFromString(line));
//                pixelTmp.setBlue(returnIntegerFromString(line));
//                picture->addPixel_ToVec(pixelTmp);
//            }
//        }
//        
//        
//
//    }
//    else
//    {
//        qDebug() << "unable to open file";
//    }
//    OriginPicture org;
//    org.drawSomethink();
//}
//
//void T_Picture::write_Picture(QString name, T_Picture* picture)
//{
//}
//
//void T_Picture::show_Picture()
//{
//    int width = this->getWidth();
//    int height = this->getHeight();
//    int transparency = 255; //later change according to application
//    int index = 0; //first element from vector
//
//    QPainter picture;
//    pixel tmpPixel = this->getPixel_fromVec(0);
//    QColor tmpColor(tmpPixel.getRed(),tmpPixel.getGreen(),tmpPixel.getBlue(),transparency);
//    
//
//    for (int i = 0; i < height; i++)
//    {
//        for (int j = 0; j < width; j++) 
//        {
//            //
//            //index is counting for correct position of pixel in array 
//            //
//            index = (width * i) + j;
//            
//            tmpPixel = this->getPixel_fromVec(index);
//
//            tmpColor.setRed(tmpPixel.getRed());
//            tmpColor.setGreen(tmpPixel.getGreen());
//            tmpColor.setBlue(tmpPixel.getBlue());
//
//            picture.setPen(tmpColor);
//            picture.drawPoint(i, j);
//
//
//
//        }
//    }
//
//    
//}
//
//void T_Picture::setPicture()
//{
//    //Picture->set
//}


