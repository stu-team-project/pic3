
#pragma once
#include "OriginPicture.h"

class newPicture: public QWidget //: public OriginPicture::QWidget
{
	Q_OBJECT
public:
	newPicture(QVector<QVector<QColor>>& PixelColor2D);
	~newPicture();



//#include "T_Project.h"

#define _filters_connected true
#define _filters_available 0
// #define IMAGE Vector<Vector<Pixel>> //sth like that for return type

/* Nikita's part
IMAGE Filter_CMYK(IMAGE origin, int parameter){
	//copy origin into a new image Result

	//return Result;
}
*/

/*Jan's part

*/

