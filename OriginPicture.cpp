#include "OriginPicture.h"

#include <fstream>
#include <QPainter>

OriginPicture::OriginPicture(QWidget* parent)
	: QWidget(parent)
{
	
}

OriginPicture::~OriginPicture()
{
	
}

int returnIntegerFromString(std::string& line) {
	int intToReturn;

	char const* digit = "0123456789";

	std::string denom = " ";
	std::string number;

	std::size_t found = line.find(denom);
	if (found == 0 && found != std::string::npos)
	{
		found = line.find_first_of(digit);
		if (found != std::string::npos)
		{
			std::size_t const den = line.find_first_not_of(digit, found);
			number = line.substr(found,den);
			intToReturn = atoi(number.c_str());
			line = line.substr(den + 1);
			if (den == std::string::npos)
			{
				line.clear();
			}
		}
	}
	else if (found != std::string::npos)
	{
		number = line.substr(0, found);
		intToReturn = atoi(number.c_str());
		line = line.substr(found + 1);
	}
	else
	{
		intToReturn = atoi(line.c_str());
		line.clear();
	}

	return intToReturn;
}

bool OriginPicture::openImage(const QString& fileName)
{
	if (getStatusModified())
	{
		clearImage();
		clearVector2D();
	}

	if (!loadImage(fileName))
		return false;

	QSize newSize;
	newSize.setWidth(getWidth());
	newSize.setHeight(getHeight());

	resizeImage(&image, newSize);
	
	for (int i = 0; i < getHeight(); i++)
	{
		for (int j = 0; j < getWidth(); j++) {
			image.setPixelColor(j, i, getColorFromVector(i,j));
		}
	}

	setStatusModified(true);
	update();
	return true;
}

void OriginPicture::drawSomethink()
{
	QColor tmp;
	int red = 0;
	int green = 0;
	int blue = 0;
	for (int i = 0; i < 300; i++)
	{
		for (int j = 0; j < 300; j++) {

			if (red >255)
			{
				red = 0;
				green = 0;
				blue = 0;
			}
			tmp.setRed(red);
			tmp.setGreen(green);
			tmp.setBlue(blue);

			this->setPixel(i, j, tmp);

			red++;
			green++;
			blue++;
		}
	}
}

bool OriginPicture::loadImage(const QString& fileName)
{
	int width, height, maxValueOfPix;
	QColor tmpCol;
	QVector<QColor> tmpVec;
	std::string line;
	std::string stringFileName = fileName.toUtf8().constData();

	std::ifstream myfile(stringFileName);

	if (myfile.is_open())
	{
		std::getline(myfile, line);
		if (line == "P3")
		{
			qDebug() << "P3";
		}
		else
		{	
			//TODO: it could by P6, so I have to do loadImage also for P6 format of PPM
			return false;
		}
		std::getline(myfile, line);
		while (line.at(0) == '#')
		{
			std::getline(myfile, line);
		}
		width = returnIntegerFromString(line);
		height = returnIntegerFromString(line);

		setWidth(width);	
		setHeight(height);

		std::getline(myfile, line);
		maxValueOfPix = returnIntegerFromString(line);
		setMaxValueOfPix(maxValueOfPix);
		
		while (std::getline(myfile, line))
		{
			while (line.length()) 
			{
				tmpCol.setRed(returnIntegerFromString(line));
				tmpCol.setGreen(returnIntegerFromString(line));
				tmpCol.setBlue(returnIntegerFromString(line));
				tmpVec.append(tmpCol);
				if (tmpVec.size() == getWidth())
				{
					addVecToPixelCol(tmpVec);
					tmpVec.clear();
				}
			}
		}

		return true;
	}
	else
	{
		return false;
	}
	
}

void OriginPicture::clearImage()
{
	image.fill(qRgb(255, 255, 255));
	setStatusModified(false);
	update();
}

void OriginPicture::clearVector2D()
{
	/*for (int i = getHeight(); i >= 0; i--)
	{
		PixelColor2D.clear();
	}*/
	PixelColor2D.clear();
}

void OriginPicture::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	QRect dirtyRect = event->rect();
	painter.drawImage(dirtyRect, image, dirtyRect);
}

void OriginPicture::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		lastPoint = event->pos();
	}
}

void OriginPicture::resizeImage(QImage* image, const QSize& newSize)
{
	if (image->size() == newSize)
		return;

	QImage newImage(newSize, QImage::Format_RGB32);
	newImage.fill(qRgb(255, 255, 255));
	QPainter painter(&newImage);
	painter.drawImage(QPoint(0, 0), *image);
	*image = newImage;
}

void OriginPicture::cenzored()
{
	QPoint first, second;

	
}
