#include "getPoint.h"
#define ___max(a, b) ((a) > (b) ? (a) : (b))
void getHorizontalLine(PicPoint startPoint, int length, int lineWidth, bool overlap, std::set<PicPoint>&pointSet)
{
	PicPoint point;
	int i = 0;
	if (overlap)
	{
		length = length + lineWidth - 1;
	}
	for (; i < length; ++i)
	{
		point = { startPoint.x + i,startPoint.y };
		pointSet.insert(point);

		//Bold
		for (int j = 1; j < lineWidth; ++j)
		{
			point = { startPoint.x + i,startPoint.y + j };
			pointSet.insert(point);
		}
	}
}

void getVerticalLine(PicPoint startPoint, int length, int lineWidth, bool overlap, std::set<PicPoint>&pointSet)
{
	PicPoint point;
	int i = 0;
	if (overlap)
	{
		length = length + lineWidth - 1;
	}
	for (; i < length; ++i)
	{
		point = { startPoint.x ,startPoint.y + i };
		pointSet.insert(point);

		//Bold
		for (int j = 1; j < lineWidth; ++j)
		{
			point = { startPoint.x + j,startPoint.y + i };
			pointSet.insert(point);
		}
	}
}

void getDiagonalLine(PicPoint startPoint, PicPoint endPoint, int lineWidth, std::set<PicPoint>& pointSet)
{
	int dx = endPoint.x - startPoint.x;
	int dy = endPoint.y - startPoint.y;

	int steps = ___max(std::abs(dx), std::abs(dy));
	float xIncrement = static_cast<float>(dx) / steps;
	float yIncrement = static_cast<float>(dy) / steps;

	float x = static_cast<float>(startPoint.x);
	float y = static_cast<float>(startPoint.y);

	for (int i = 0; i <= steps; ++i) 
	{
		for (int j = 0; j < lineWidth; ++j) 
		{
			pointSet.insert({ static_cast<unsigned int>(x + j), static_cast<unsigned int>(y + j) });
		}
		x += xIncrement;
		y += yIncrement;
	}
}

void getCirclePoints(PicPoint startPoint, int radius, int lineWidth, std::set<PicPoint>& pointSet) 
{
	for (int x = -radius - lineWidth; x <= radius + lineWidth; ++x)
	{
		for (int y = -radius - lineWidth; y <= radius + lineWidth; ++y) 
		{
			if (x * x + y * y <= (radius + lineWidth) * (radius + lineWidth)
				&& x * x + y * y >= (radius - lineWidth) * (radius - lineWidth))
			{
				pointSet.insert({ startPoint.x + x, startPoint.y + y });
			}
		}
	}
}

void getRectanglePoint(PicPoint leftTop, PicPoint rightBottom, std::set<PicPoint>& pointSet)
{
	for (unsigned int x = leftTop.x; x <= rightBottom.x; ++x)
	{
		for (unsigned int y = leftTop.y; y <= rightBottom.y; ++y)
		{
			pointSet.insert({ x, y });
		}
	}
}