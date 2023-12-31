#pragma once

#include <QColor>
#include <QImage>
#include <QVector>
#include <QtWidgets>

#include "T_Project.h"
#include "Filters.h"

class Filters;

class OriginPicture
	:public QWidget
{
	Q_OBJECT
public:
	OriginPicture(QWidget* parent = Q_NULLPTR);
	~OriginPicture();

	bool getStatusModified() { return modified; };
	void setStatusModified(bool status) { modified = status; };
	bool openImage(const QString& fileName);
	bool saveImage(const QString& fileName);
	void draw(int width);															//width is for drawing secong image next to first
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

	QVector<QVector<QColor>>* getVec2D() { return& PixelColor2D; };
	QColor getColorFromVector(int x, int y) { return PixelColor2D.at(x).at(y); };
public slots:
	void draw();
	void censore();
	void blackAndWhite();
	void inverse();
	void redFilter();
	void blur3x3();
	void blur5x5();
	void blur7x7();
	void fidingEdge();

	void fisheye();
	void cmyk();
	void densecmyk();
	void dithercmyk();

protected:
	void paintEvent(QPaintEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
private:
	void resizeImage(QImage* image, const QSize& newSize);

	bool modified = false;

	//parameters of picture
	int widthOfPic;
	int heightOfPic;
	int maxValueOfPix;
	std::string typeOfPPMpic;
	QImage image;
	//QColor col = Qt::red;

	QVector<QVector<QColor>> PixelColor2D;

	QPoint lastPoint;

	Filters* filter;

	//for censored filter
	bool censoreActivate = false;
	bool firstPointForCensoreClicked = false;
	bool secondPointForCensoreClicked = false;
	QPoint firstPointCensored;
	QPoint secondPointCensored;
};
