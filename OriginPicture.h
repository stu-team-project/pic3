#pragma once

#include <QColor>
#include <QImage>
#include <QVector>
#include <QtWidgets>

#include "T_Project.h"

class OriginPicture :public QWidget 
{
	Q_OBJECT
public:
	OriginPicture(QWidget* parent = Q_NULLPTR);
	~OriginPicture();

	bool getStatusModified() { return modified; };
	void setStatusModified(bool status) { modified = status; };
	bool openImage(const QString& fileName);
	void drawSomethink();
	void setPixel(int x, int y, QColor col) { image.setPixelColor(x, y, col); };

	void setWidth(int w) { widthOfPic = w; };
	void setHeight(int h) { heightOfPic = h; };
	void setMaxValueOfPix(int max) { maxValueOfPix = max; };

	int getWidth() { return widthOfPic; };
	int getHeight() { return heightOfPic; };
	int getMaxValueOfPix() { return maxValueOfPix; };

	void addVecToPixelCol(QVector<QColor> VecPixelCol) { PixelColor2D.append(VecPixelCol); };

	bool loadImage(const QString& fileName);
	void clearImage();
	void clearVector2D();


	QColor getColorFromVector(int x, int y) { return PixelColor2D.at(x).at(y); };
public slots:
	void cenzored();
protected:
	void paintEvent(QPaintEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
private:
	void resizeImage(QImage* image, const QSize& newSize);

	bool modified = false;

	int widthOfPic;
	int heightOfPic;
	int maxValueOfPix;
	QImage image;
	QColor col = Qt::red;

	QVector<QVector<QColor>> PixelColor2D;

	QPoint lastPoint;
	//
	//inspiration from computer graphics
	//
	//QPainter* painter = nullptr;
	//uchar* data = nullptr;
};




