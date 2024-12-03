#pragma once
#include <set>

typedef struct tagPicPoint
{
	unsigned int x;
	unsigned int y;
	bool operator<(const tagPicPoint& other) const
	{
		return x < other.x || (x == other.x && y < other.y);
	}
} PicPoint;

void getHorizontalLine(PicPoint startPoint, int length, int lineWidth,bool overlap, std::set<PicPoint>&pointSet);
void getVerticalLine(PicPoint startPoint, int length, int lineWidth, bool overlap, std::set<PicPoint>&pointSet);
void getDiagonalLine(PicPoint startPoint, PicPoint endPoint, int lineWidth, std::set<PicPoint>& pointSet);
void getCirclePoints(PicPoint startPoint, int radius, int lineWidth, std::set<PicPoint>& pointSet);
void getRectanglePoint(PicPoint leftTop, PicPoint rightBottom, std::set<PicPoint>& pointSet);