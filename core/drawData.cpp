#include "drawData.h"

/***
YYYYYYYY
YYYYYYYY
YYYYYYYY
YYYYYYYY
UUUU
UUUU
VVVV
VVVV
			x
(0,0)------------>
 |
 |
y|
\|/

***/
void draw_YUV420P(unsigned char *dataY,
	unsigned char *dataU,
	unsigned char *dataV,
	int linesizeY,
	int linesizeU,
	int linesizeV,
	YUVcolor color,
	const std::set<PicPoint>&pointSet)
{
	auto it = pointSet.begin();
	for (; it != pointSet.end(); ++it)
	{
		//draw Y
		auto x = it->x;
		auto y = it->y;
		*(dataY + (y*linesizeY) + x) = color.y; 

		//draw U V
		auto xUV = it->x / 2;
		auto yUV = it->y / 2;
		*(dataU + (yUV*linesizeU) + xUV) = color.u;
		*(dataV + (yUV*linesizeV) + xUV) = color.v;
	}
}

void draw_YUV420P_by_RGB24(unsigned char *dataY,
	unsigned char *dataU,
	unsigned char *dataV,
	int linesizeY,
	int linesizeU,
	int linesizeV,
	PicPoint yuvStartPoint,
	unsigned char *dataRgb24,
	int linesizeRgb24,
	const std::set<PicPoint>&pointSet)
{
	auto it = pointSet.begin();
	for (; it != pointSet.end(); ++it)
	{
		auto xRgb = it->x - yuvStartPoint.x;
		auto yRGB = it->y - yuvStartPoint.y;
		unsigned char *rgb = dataRgb24 + (yRGB * linesizeRgb24 + xRgb) * 3;
		unsigned char R = *rgb;
		unsigned char G = *(rgb + 1);
		unsigned char B = *(rgb + 2);
		
		/*ITU-R BT.709 conversion*/
		unsigned char Y = (unsigned char)(0.299*R + 0.587*G + 0.114*B);
		unsigned char U = (unsigned char)(128-0.169*R - 0.331*G + 0.5*B);
		unsigned char V = (unsigned char)(128+0.5*R - 0.419*G - 0.081*B);
		//draw Y
		auto x = it->x;
		auto y = it->y;
		*(dataY + (y*linesizeY) + x) = Y;

		//draw U V
		auto xUV = it->x / 2;
		auto yUV = it->y / 2;
		*(dataU + (yUV*linesizeU) + xUV) = U;
		*(dataV + (yUV*linesizeV) + xUV) = V;
	}
}

void draw_YUV444P(unsigned char *dataY,
	unsigned char *dataU,
	unsigned char *dataV,
	int linesizeY,
	int linesizeU,
	int linesizeV,
	YUVcolor color,
	const std::set<PicPoint>&pointSet)
{
	auto it = pointSet.begin();
	for (; it != pointSet.end(); ++it)
	{
		//draw Y
		auto x = it->x;
		auto y = it->y;
		*(dataY + (y*linesizeY) + x) = color.y;

		//draw U V
		*(dataU + (y*linesizeU) + x) = color.u;
		*(dataV + (y*linesizeV) + x) = color.v;
	}
}
