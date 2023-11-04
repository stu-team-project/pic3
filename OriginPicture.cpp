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

std::string addPixelToString(QColor col) {
	std::string tmp;
	tmp.append(std::to_string(col.red()));
	tmp.append(" ");
	tmp.append(std::to_string(col.green()));
	tmp.append(" ");
	tmp.append(std::to_string(col.blue()));
	tmp.append(" ");
	return tmp;
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
	newSize.setWidth(getWidth()*2+10);
	newSize.setHeight(getHeight());

	resizeImage(&image, newSize);
	draw();

	setStatusModified(true);
	update();
	return true;
}

bool OriginPicture::saveImage(const QString& fileName)
{
	int maxIndexLine;							// maxLine is for boundary max lenght of line in PPM. It should not be more than 70 
	int index = 0;
	if (getWidth() * getHeight() > 20)			// 20 its because one pixel has 3 values. Red, Green and blue. Each value represent one number in line.
	{
		maxIndexLine = 20;
	}
	else
	{
		maxIndexLine = getWidth() * getHeight();
	}

	std::string stringFileName = fileName.toUtf8().constData();
	std::string line;

	if (fileName.isEmpty())
	{
		return false;
	}
	else
	{
		if (typeOfPPMpic == "P3")
		{
			std::ofstream newFile(stringFileName);
			if (newFile.is_open())
			{
				newFile << typeOfPPMpic << std::endl;
				newFile << "#" + stringFileName << std::endl;
				newFile << std::to_string(getWidth()) + " " + std::to_string(getHeight()) << std::endl;
				newFile << std::to_string(getMaxValueOfPix()) << std::endl;
				for (int i = 0; i < getHeight(); i++)
				{
					for (int j = 0; j < getWidth(); j++) 
					{
						line.append(addPixelToString(PixelColor2D.at(i).at(j)));
						index++;
						if (index == maxIndexLine)
						{
							newFile << line << std::endl;
							line.clear();
							index = 0;
						}
					}
				}
			}
		}
		else if (typeOfPPMpic == "P6")
		{
			qDebug() << "Jan has to do save for P6 Type";
		}
		else
		{
			return false;
		}
		return true;
	}
}

void OriginPicture::draw(int width)
{
	for (int i = 0; i < getHeight(); i++)
	{
		for (int j = 0; j < getWidth(); j++)
		{
			image.setPixelColor(j + width + 10, i, getColorFromVector(i, j));
		}
	}
	update();
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
		if (line == "P3" || line == "P6")
		{
			typeOfPPMpic = line;
			qDebug() << "correct format.";
		}
		else
		{	
			//TODO: it could by P6, so I have to do loadImage also for P6 format of PPM
			qDebug() << "incorrect format.";
			return false;
		}

		if (typeOfPPMpic == "P3")
		{
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
		else if (typeOfPPMpic == "P6")
		{
			qDebug() << "jan has to do reading for P6 file";
		}
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

void OriginPicture::censore()
{
	censoreActivate = true;
	if (censoreActivate&&secondPointForCensoreClicked)
	{
		filter->censore(this->getVec2D(), &firstPointCensored, &secondPointCensored);
		draw(getWidth());																//getWidth is for drawing second picture next to first picture.
		censoreActivate = false;
	}
}

void OriginPicture::blackAndWhite()
{
	filter->blackAndWhite(this->getVec2D(), this->getHeight(), this->getWidth());
	draw(getWidth());
}

void OriginPicture::fisheye()
{
	filter->fisheyeFilter(this->getVec2D());
	draw(getWidth());
}

void OriginPicture::cmyk()
{
	filter->cmykFilter(this->getVec2D());
	draw(getWidth());
}

void OriginPicture::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	QRect dirtyRect = event->rect();
	painter.drawImage(dirtyRect, image, dirtyRect);
}

void OriginPicture::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton && censoreActivate)
	{
		if (firstPointForCensoreClicked)
		{
			secondPointCensored = event->pos();
			secondPointForCensoreClicked = true;
			censore();
			secondPointForCensoreClicked = false;
			firstPointForCensoreClicked = false;
		}
		else
		{
			firstPointCensored = event->pos();
			firstPointForCensoreClicked = true;
		}
	}

	/*if (event->button() == Qt::LeftButton) {
		lastPoint = event->pos();
	}*/
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

void OriginPicture::draw()
{
	for (int i = 0; i < getHeight(); i++)
    {
		for (int j = 0; j < getWidth(); j++) 
		{
			image.setPixelColor(j , i, getColorFromVector(i, j));
		}
	}
	update();
}
