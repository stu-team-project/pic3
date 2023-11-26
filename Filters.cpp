#include "Filters.h"
#include <cmath>
//next 2 for randomness
#include <random>
#include <time.h>


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

int randlimit(int limit) { //run """srand((unsigned int)time(NULL));""" first
	return rand() % limit;
}

void Filters::cmykFilter(QVector<QVector<QColor>>* VecOfPixelsColor2D)
{
	//no halftone
	//use 4pixel dithering
	srand((unsigned int)time(NULL));
	QVector<QColor> tmpVec;
	QColor newColor;
	for (int i = 0; i < VecOfPixelsColor2D->size(); i++) {
		for (int j = 0; j < VecOfPixelsColor2D->at(i).size(); j++) {
			int c, m, y, k;
			VecOfPixelsColor2D->at(i).at(j).getCmyk(&c, &m, &y, &k);
			newColor.setCmyk(0, 0, 0, 0);
			if (i % 2 == 0 && j % 2 == 0) {
				if ( c > randlimit(255) ) { newColor.setCmyk(255, 0, 0, 0); }
			}
			else if (i % 2 == 1 && j % 2 == 0) {
				if (m > randlimit(255)) { newColor.setCmyk(0, 255, 0, 0); }
			}
			else if (i % 2 == 0 && j % 2 == 1) {
				if (y > randlimit(255)) { newColor.setCmyk(0, 0, 255, 0); }
			}
			else if (i % 2 == 1 && j % 2 == 1) {
				if (k > randlimit(255)) { newColor.setCmyk(0, 0, 0, 255); }
			}
			tmpVec.append(newColor);
		}
		VecOfPixelsColor2D->replace(i, tmpVec);
		tmpVec.clear();
	}
}

void Filters::densecmykFilter(QVector<QVector<QColor>>* VecOfPixelsColor2D)
{
	srand((unsigned int)time(NULL));
	QVector<QColor> tmpVec;
	QColor newColor;
	int decider;
	int pixel;
	for (int i = 0; i < VecOfPixelsColor2D->size(); i++) {
		for (int j = 0; j < VecOfPixelsColor2D->at(i).size(); j++) {
			int c, m, y, k;
			VecOfPixelsColor2D->at(i).at(j).getCmyk(&c, &m, &y, &k);
			pixel = (j%2) + 2 * (i%2);
			newColor.setCmyk(0, 0, 0, 0);
			switch (pixel)
			{
			case 0: 
				decider = randlimit(m + y + k + 1);
				if (decider < m) { newColor.setCmyk(0, 255, 0, 0); }
				else if (decider < m + y) { newColor.setCmyk(0, 0, 255, 0); }
				else { newColor.setCmyk(0, 0, 0, 255); }
				break;
			case 1:
				decider = randlimit(c + y + k + 1);
				if (decider < c) { newColor.setCmyk(255, 0, 0, 0); }
				else if (decider < c + y) { newColor.setCmyk(0, 0, 255, 0); }
				else  { newColor.setCmyk(0, 0, 0, 255); }
				break;
			case 2:
				decider = randlimit(c + m + k + 1);
				if (decider < c) { newColor.setCmyk(255, 0, 0, 0); }
				else if (decider < c+m) { newColor.setCmyk(0, 255, 0, 0); }
				else  { newColor.setCmyk(0, 0, 0, 255); }
				break;
			case 3:
				decider = randlimit(c + m + y + 1);
				if (decider < c) { newColor.setCmyk(255, 0, 0, 0); }
				else if (decider < c + m) { newColor.setCmyk(0, 255, 0, 0); }
				else  { newColor.setCmyk(0, 0, 255, 0); }
				break;
			default:
				break;
			}

			tmpVec.append(newColor);
		}
		VecOfPixelsColor2D->replace(i, tmpVec);
		tmpVec.clear();
	}
}

void modifyColor(QColor& color, int errorR, int errorG, int errorB, int weight) { //doesn't work, changes nothing
	color.setRed(qBound(0, color.red() + errorR * weight / 16, 255));
	color.setGreen(qBound(0, color.green() + errorG * weight / 16, 255));
	color.setBlue(qBound(0, color.blue() + errorB * weight / 16, 255));
}
QColor findClosestColor(QColor& color,  QVector<QColor>& colorset) {
	int minDist = INT_MAX;
	QColor closestColor;
	for (const QColor& col : colorset) {
		int dist = qPow(col.red() - color.red(), 2) +
			qPow(col.green() - color.green(), 2) +
			qPow(col.blue() - color.blue(), 2);
		if (dist < minDist) {
			minDist = dist;
			closestColor = col;
		}
	}
	return closestColor;
}
void Filters::dithercmykFilter(QVector<QVector<QColor>>* VecOfPixelsColor2D) {
	https://en.wikipedia.org/wiki/Floyd%E2%80%93Steinberg_dithering
	QVector<QVector<QColor>> tmpPixels = *VecOfPixelsColor2D;
	QVector<QColor> colorset = {
		QColor::fromRgb(0, 0, 0),      // Black
		QColor::fromRgb(255, 255, 255),// White
		QColor::fromRgb(0, 255, 255),  // Cyan
		QColor::fromRgb(255, 0, 255),  // Magenta
		QColor::fromRgb(255, 255, 0)   // Yellow
	};
	int width = VecOfPixelsColor2D->size();
	int height = VecOfPixelsColor2D->at(0).size();
	QColor oldColor, newColor;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			QColor oldColor = VecOfPixelsColor2D->at(x).at(y);
			QColor newColor = findClosestColor(oldColor, colorset);
			tmpPixels[x][y] = newColor;

			int errorR = oldColor.red() - newColor.red();
			int errorG = oldColor.green() - newColor.green();
			int errorB = oldColor.blue() - newColor.blue();

			if (x + 1 < width) {
				modifyColor(tmpPixels[x+1][y], errorR, errorG, errorB, 7);
			}
			if (y + 1 < height) {
				if (x - 1 >= 0) {
					modifyColor(tmpPixels[x-1][y+1], errorR, errorG, errorB, 3);
				}
				modifyColor(tmpPixels[x][y+1], errorR, errorG, errorB, 5);
				if (x + 1 < width) {
					modifyColor(tmpPixels[x+1][y+1], errorR, errorG, errorB, 1);
				}
			}
		}
	}
	*VecOfPixelsColor2D = tmpPixels;
	/*for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			VecOfPixelsColor2D->at(x).at(y).fromRgb(tmpPixels[x][y].rgb());
		}
	}*/
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

void Filters::redFilter(QVector<QVector<QColor>>* VecOfPixelsColor2D, int height, int width)
{
	int red, green, blue, average;
	QVector<QColor>tmpVec;
	QColor redTmpColor;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			red = VecOfPixelsColor2D->at(i).at(j).red();
			green = VecOfPixelsColor2D->at(i).at(j).green();
			blue = VecOfPixelsColor2D->at(i).at(j).blue();

			average = (red + green + blue) / 3;

			if (red + 100 >255)
			{
				red = 255;
			}
			else
			{
				red += 100;
			}

			redTmpColor.setRed(red);
			redTmpColor.setGreen(green);
			redTmpColor.setBlue(blue);

			tmpVec.append(redTmpColor);
		}
		VecOfPixelsColor2D->replace(i, tmpVec);
		tmpVec.clear();
	}
}

void Filters::blur(QVector<QVector<QColor>>* VecOfPixelsColor2D, int height, int width, int variance)
{
	const QVector<QVector<QColor>> tmpVecOfPixelsColor2D = *VecOfPixelsColor2D;
	QVector<QColor>boundaryOfPixel;
	QVector<QColor>tmpVec;
	QVector<int> RGB;
	QColor blurColor, averageColor;
	
	averageColor = getAveragePixel(VecOfPixelsColor2D);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) 
		{
			boundaryOfPixel = fillMask(&tmpVecOfPixelsColor2D, averageColor,i,j,height,width,variance);

			RGB = gaussMask(&boundaryOfPixel, variance);
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

void Filters::blur3x3(QVector<QVector<QColor>>* VecOfPixelsColor2D, int height, int width)
{
	blur(VecOfPixelsColor2D, height, width,1);
}

void Filters::blur5x5(QVector<QVector<QColor>>* VecOfPixelsColor2D, int height, int width)
{
	blur(VecOfPixelsColor2D, height, width, 2);
}

void Filters::blur7x7(QVector<QVector<QColor>>* VecOfPixelsColor2D, int height, int width)
{
	blur(VecOfPixelsColor2D, height, width, 3);
}

void Filters::fidingEdge(QVector<QVector<QColor>>* VecOfPixelsColor2D, int height, int width)
{
	const QVector<QVector<QColor>> tmpVecOfPixelsColor2D = *VecOfPixelsColor2D;
	QVector<QColor>boundaryOfPixel;
	QVector<QColor>tmpVec;
	QVector<int> RGBForXDirection, RGBForYDirection;
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
			boundaryOfPixel = fillMask(&tmpVecOfPixelsColor2D, averageColor, i, j, height, width, 1);

			RGBForXDirection = SobelOperatorX(&boundaryOfPixel);
			RGBForYDirection = SobelOperatorY(&boundaryOfPixel);

			red = (RGBForXDirection.at(0) * RGBForXDirection.at(0) + RGBForYDirection.at(0) * RGBForYDirection.at(0));
			red = pow(red, 0.5);
			green = (RGBForXDirection.at(1) * RGBForXDirection.at(1) + RGBForYDirection.at(1) * RGBForYDirection.at(1));
			green = pow(green, 0.5);
			blue = (RGBForXDirection.at(2) * RGBForXDirection.at(2) + RGBForYDirection.at(2) * RGBForYDirection.at(2));
			blue = pow(blue, 0.5);


			blurColor.setRed(red);
			blurColor.setGreen(green);
			blurColor.setBlue(blue);

			tmpVec.append(blurColor);
			boundaryOfPixel.clear();
		}
		VecOfPixelsColor2D->replace(i, tmpVec);
		tmpVec.clear();
	}
}

const QVector<int> Filters::gaussMask(QVector<QColor>* mask, int variance)
{
	QVector<int> returnRGB;
	QVector<int> valueOfMask;
	if (variance == 1)
	{
		valueOfMask = { 1,2,1,2,4,2,1,2,1 };
	}
	else if (variance == 2)
	{
		valueOfMask = { 1,4,7,4,1,4,16,26,16,4,7,26,41,26,7,4,16,26,16,4,1,4,7,4,1 };
	}
	else if (variance == 3)
	{
		valueOfMask = { 0,0,1,2,1,0,0,0,3,13,22,13,3,0,1,13,59,97,59,13,1,2,22,97,159,97,22,2,1,13,59,97,59,13,1,0,3,13,22,13,3,0,0,0,1,2,1,0,0 };
	}
	else
	{
		qDebug() << "incorrect value of Variance in function gaussMask";
	}
	
	int red(0), green(0), blue(0), sumOfMaskValues(0);

	for (int i = 0; i < valueOfMask.size(); i++)
	{
		red += mask->at(i).red() * valueOfMask.at(i);
		green += mask->at(i).green() * valueOfMask.at(i);
		blue += mask->at(i).blue() * valueOfMask.at(i);
		sumOfMaskValues += valueOfMask.at(i);
	}

	red = red / sumOfMaskValues;
	returnRGB.append(red);

	green = green / sumOfMaskValues;
	returnRGB.append(green);

	blue = blue / sumOfMaskValues;
	returnRGB.append(blue);

	return returnRGB;
}

const QVector<int> Filters::SobelOperatorX(QVector<QColor>* mask)
{
	QVector<int> returnRGB;
	QVector<int> valueOfMask{ -1,0,1,-2,0,2,-1,0,1 };
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

const QVector<int> Filters::SobelOperatorY(QVector<QColor>* mask)
{
	QVector<int> returnRGB;
	QVector<int> valueOfMask{ -1,-2,-1,0,0,0,1,2,1 };
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

const QVector<QColor> Filters::fillMask(const QVector<QVector<QColor>>* tmpVecOfPixelsColor2D, QColor averageColor, int i, int j, int height ,int width, int variance)
{
	QVector<QColor> vecOfMask;
	
	for (int x = i - variance; x <= i + variance; x++)
	{
		for (int y = j - variance; y <= j + variance; y++) 
		{
			if (x < 0 || y < 0 || x >= height || y >= width)
			{
				vecOfMask.append(averageColor);
			}
			else
			{
				vecOfMask.append(tmpVecOfPixelsColor2D->at(x).at(y));
			}
		}
	}

	return vecOfMask;
}

const QColor Filters::getAveragePixel(const QVector<QVector<QColor>>* VecOfPixelsColor2D)
{
	QColor averageColor;
	int red(0), green(0), blue(0), sum(0);
	int height = VecOfPixelsColor2D->size();
	int width = VecOfPixelsColor2D->at(0).size();
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

	return averageColor;
}
