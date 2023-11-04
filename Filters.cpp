#include "Filters.h"


//newPicture::newPicture(QVector<QVector<QColor>>& PixelColor2D)
//{
//	QSize newSize;
//	newSize.setHeight(1000);
//	newSize.setWidth(1000);
//	resizeImage(&updateImage,newSize);
//
//	for (int i = 0; i < 200; i++)
//	{
//		for (int j = 0; j < 200; j++) 
//		{
//			updateImage.setPixelColor(i, j, PixelColor2D.at(i).at(j));
//		}
//	}
//	update();
//}
//
//newPicture::~newPicture()
//{
//}
//
//void newPicture::paintEvent(QPaintEvent* event)
//{
//	QPainter painter(this);
//	QRect dirtyRect = event->rect();
//	painter.drawImage(dirtyRect, updateImage, dirtyRect);
//}
//
//void newPicture::resizeImage(QImage* updateImage, const QSize& newSize)
//{
//	if (updateImage->size() == newSize)
//		return;
//
//	QImage newImage(newSize, QImage::Format_RGB32);
//	newImage.fill(qRgb(0, 0, 0));
//	QPainter painter(&newImage);
//	painter.drawImage(QPoint(300, 300), *updateImage);
//	*updateImage = newImage;
//}

Filters::Filters()
{
	
}

Filters::~Filters()
{
}

void Filters::fisheyeFilter(QVector<QVector<QColor>>* VecOfPixelsColor2D)
{
}

void Filters::cmykFilter(QVector<QVector<QColor>>* VecOfPixelsColor2D)
{
}

void Filters::censore(QVector<QVector<QColor>>* VecOfPixelsColor2D, QPoint* firstClicked, QPoint* secondClicked)
{
	QColor black = Qt::black;
	int minX, maxX, minY, maxY;
	if (firstClicked->x() > secondClicked->x())
	{
		minX = secondClicked->x();
		maxX = firstClicked->x();
	}
	else
	{
		minX = firstClicked->x();
		maxX = secondClicked->x();
	}
	if (firstClicked->y() > secondClicked->y())
	{
		minY = secondClicked->y();
		maxY = firstClicked->y();
	}
	else
	{
		minY = firstClicked->y();
		maxY = secondClicked->y();
	}

	QVector<QColor>tmp;

	for (int i = minY; i < maxY; i++)
	{
		tmp = VecOfPixelsColor2D->at(i);
		for (int j = minX; j < maxX; j++)
		{
			tmp.replace(j, black);
		}
		VecOfPixelsColor2D->replace(i, tmp);
		tmp.clear();
	}

}

void Filters::blackAndWhite(QVector<QVector<QColor>>* VecOfPixelsColor2D, int height, int width)
{
	int gray, red, green, blue;
	QVector<QColor>tmpVec;
	QColor grayTmpColor;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			red = VecOfPixelsColor2D->at(i).at(j).red();
			green = VecOfPixelsColor2D->at(i).at(j).green();
			blue = VecOfPixelsColor2D->at(i).at(j).blue();

			gray = (red + green + blue) / 3;

			grayTmpColor.setRed(gray);
			grayTmpColor.setGreen(gray);
			grayTmpColor.setBlue(gray);

			tmpVec.append(grayTmpColor);
		}
		VecOfPixelsColor2D->replace(i, tmpVec);
		tmpVec.clear();
	}
}
