#pragma once
#include "OriginPicture.h"

class newPicture: public QWidget //: public OriginPicture::QWidget
{
	Q_OBJECT
public:
	newPicture(QVector<QVector<QColor>>& PixelColor2D);
	~newPicture();


protected:
	void paintEvent(QPaintEvent* event);
private:
	void resizeImage(QImage* updateImage, const QSize& newSize);

	QImage updateImage;
};

