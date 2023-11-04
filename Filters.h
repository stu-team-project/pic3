
#pragma once
#include "OriginPicture.h"

class OriginPicture;

//class newPicture: public QWidget //: public OriginPicture::QWidget
//{
//	Q_OBJECT
//public:
//	newPicture(QVector<QVector<QColor>>& PixelColor2D);
//	~newPicture();
//
//
//
////#include "T_Project.h"
//
//#define _filters_connected true
//#define _filters_available 0
//// #define IMAGE Vector<Vector<Pixel>> //sth like that for return type
//
///* Nikita's part
//IMAGE Filter_CMYK(IMAGE origin, int parameter){
//	//copy origin into a new image Result
//
//	//return Result;
//}
//*/
//
///*Jan's part
//
//*/
//
//protected:
//	void paintEvent(QPaintEvent* event);
//private:
//	void resizeImage(QImage* updateImage, const QSize& newSize);
//
//	QImage updateImage;
//};

class Filters
{
public:
	Filters();
	~Filters();

	// Nikitas Filters
	void fisheyeFilter(QVector<QVector<QColor>>* VecOfPixelsColor2D);
	void cmykFilter(QVector<QVector<QColor>>* VecOfPixelsColor2D);


	//Jans Filters
	void censore(QVector<QVector<QColor>>* VecOfPixelsColor2D, QPoint* firstClicked, QPoint* secondClicked);
	void blackAndWhite(QVector<QVector<QColor>>* VecOfPixelsColor2D, int height, int width);
	//void setCensorActivate(bool status) { censoreActivate = status; };
private:
	//QVector<QVector<QColor>>* VecOfPixelsColor2D;
	

	
};


