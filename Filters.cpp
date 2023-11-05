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

void Filters::inverse(QVector<QVector<QColor>>* VecOfPixelsColor2D, int height, int width)
{
	int diff;
	const int maxValue = 255;
	const int minValue = 0;
	QVector<QColor>tmpVec;
	QColor inverseColor;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			diff = maxValue - VecOfPixelsColor2D->at(i).at(j).red();
			inverseColor.setRed(minValue + diff);
			diff = maxValue - VecOfPixelsColor2D->at(i).at(j).green();
			inverseColor.setGreen(minValue + diff);
			diff = maxValue - VecOfPixelsColor2D->at(i).at(j).blue();
			inverseColor.setBlue(minValue + diff);

			tmpVec.append(inverseColor);
		}
		VecOfPixelsColor2D->replace(i, tmpVec);
		tmpVec.clear();
	}
}

void Filters::blur(QVector<QVector<QColor>>* VecOfPixelsColor2D, int height, int width)
{
	const QVector<QVector<QColor>> tmpVecOfPixelsColor2D = *VecOfPixelsColor2D;
	QVector<QColor>boundaryOfPixel;
	QVector<QColor>tmpVec;
	QVector<int> RGB;
	QColor blurColor, averageColor;
	int red(0), green(0), blue(0), sum(0);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			red += VecOfPixelsColor2D->at(i).at(j).red();
			green += VecOfPixelsColor2D->at(i).at(j).green();
			blue += VecOfPixelsColor2D->at(i).at(j).blue();
			sum++;
		}
	}	
	averageColor.setRed(red / sum);
	averageColor.setGreen(green / sum);
	averageColor.setBlue(blue / sum);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) 
		{
			//left upper corner of mask
			if (i - 1 < 0 || j - 1 < 0)
			{
				boundaryOfPixel.append(averageColor);
			}
			else
			{
				boundaryOfPixel.append(tmpVecOfPixelsColor2D.at(i-1).at(j-1));
			}
			//upper middle point of mask
			if (i - 1 < 0)
			{
				boundaryOfPixel.append(averageColor);
			}
			else
			{
				boundaryOfPixel.append(tmpVecOfPixelsColor2D.at(i-1).at(j));
			}
			//right upper corner of mask
			if (i - 1 < 0 || j + 1 >= width)
			{
				boundaryOfPixel.append(averageColor);
			}
			else
			{
				boundaryOfPixel.append(tmpVecOfPixelsColor2D.at(i - 1).at(j + 1));
			}
			//second line of mask
			//left point of mask
			if (j - 1 < 0)
			{
				boundaryOfPixel.append(averageColor);
			}
			else
			{
				boundaryOfPixel.append(tmpVecOfPixelsColor2D.at(i).at(j - 1));
			}
			//middle point of mask
			boundaryOfPixel.append(tmpVecOfPixelsColor2D.at(i).at(j));
			//right point of mask
			if (j + 1 >= width)
			{
				boundaryOfPixel.append(averageColor);
			}
			else
			{
				boundaryOfPixel.append(tmpVecOfPixelsColor2D.at(i).at(j + 1));
			}
			//bottom line
			//left bottom corner of mask
			if (i + 1 >= height || j - 1 < 0)
			{
				boundaryOfPixel.append(averageColor);
			}
			else
			{
				boundaryOfPixel.append(tmpVecOfPixelsColor2D.at(i + 1).at(j - 1));
			}
			//bottom middle point of mask
			if (i + 1 >= height)
			{
				boundaryOfPixel.append(averageColor);
			}
			else
			{
				boundaryOfPixel.append(tmpVecOfPixelsColor2D.at(i + 1).at(j));
			}
			//bottom right point of mask
			if (i + 1 >= height || j + 1 >= width)
			{
				boundaryOfPixel.append(averageColor);
			}
			else
			{
				boundaryOfPixel.append(tmpVecOfPixelsColor2D.at(i + 1).at(j + 1));
			}

			RGB = gaussMask(&boundaryOfPixel);
			blurColor.setRed(RGB.at(0));
			blurColor.setGreen(RGB.at(1));
			blurColor.setBlue(RGB.at(2));

			tmpVec.append(blurColor);
			boundaryOfPixel.clear();
		}
		VecOfPixelsColor2D->replace(i, tmpVec);
		tmpVec.clear();
	}
}

const QVector<int> Filters::gaussMask(QVector<QColor>* mask)
{
	QVector<int> returnRGB;
	QVector<int> valueOfMask{1,2,1,2,4,2,1,2,1};
	int red(0), green(0), blue(0);

	for (int i = 0; i < valueOfMask.size(); i++)
	{
		red += mask->at(i).red() * valueOfMask.at(i);
		green += mask->at(i).green() * valueOfMask.at(i);
		blue += mask->at(i).blue() * valueOfMask.at(i);
	}

	red = red / 16;
	returnRGB.append(red);

	green = green / 16;
	returnRGB.append(green);

	blue = blue / 16;
	returnRGB.append(blue);

	return returnRGB;
}
