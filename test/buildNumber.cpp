#include "buildNumber.h"

void getNumber_0(PicPoint startPoint, int fontSize, int lineWidth, std::set<PicPoint>&pointSet)
{
	/*
	fontSize
	.........
	.		.
	.		.
	.		. fontSize * 2
	.		.
	.........

	*/
	std::set<PicPoint> line[4];
	getHorizontalLine(startPoint, fontSize, lineWidth, true,line[0]);
	getVerticalLine(startPoint, fontSize * 2, lineWidth, true,line[1]);

	PicPoint startPoininct2 = { startPoint.x + fontSize,startPoint.y };
	getVerticalLine(startPoininct2, fontSize * 2, lineWidth, true,line[2]);

	PicPoint startPoint3 = { startPoint.x,startPoint.y + 2 * fontSize };
	getHorizontalLine(startPoint3, fontSize, lineWidth, true,line[3]);

	for (int i = 0; i<4; ++i)
	{
		pointSet.insert(line[i].begin(), line[i].end());
	}
}

void getNumber_1(PicPoint startPoint, int fontSize, int lineWidth, std::set<PicPoint>&pointSet)
{
	std::set<PicPoint> line[1];
	getVerticalLine(startPoint, fontSize * 2, lineWidth, true,line[0]);
	for (int i = 0; i<1; ++i)
	{
		pointSet.insert(line[i].begin(), line[i].end());
	}
}


void getNumber_2(PicPoint startPoint, int fontSize, int lineWidth, std::set<PicPoint>&pointSet)
{
	std::set<PicPoint> line[5];
	getHorizontalLine(startPoint, fontSize, lineWidth, true,line[0]);
	PicPoint startPoint2 = { startPoint.x + fontSize,startPoint.y };
	getVerticalLine(startPoint2, fontSize, lineWidth, true,line[1]);

	PicPoint startPoint3 = { startPoint.x,startPoint.y + fontSize };
	getHorizontalLine(startPoint3, fontSize, lineWidth, true,line[2]);
	getVerticalLine(startPoint3, fontSize, lineWidth, true,line[3]);

	PicPoint startPoint4 = { startPoint.x,startPoint.y + 2 * fontSize };
	getHorizontalLine(startPoint4, fontSize, lineWidth, true,line[4]);

	for (int i = 0; i<5; ++i)
	{
		pointSet.insert(line[i].begin(), line[i].end());
	}
}

void getNumber_3(PicPoint startPoint, int fontSize, int lineWidth, std::set<PicPoint>&pointSet)
{
	std::set<PicPoint> line[4];
	getHorizontalLine(startPoint, fontSize, lineWidth, true,line[0]);
	PicPoint startPoint2 = { startPoint.x + fontSize,startPoint.y };
	getVerticalLine(startPoint2, fontSize * 2, lineWidth, true,line[1]);

	PicPoint startPoint3 = { startPoint.x,startPoint.y + fontSize };
	getHorizontalLine(startPoint3, fontSize, lineWidth, true,line[2]);

	PicPoint startPoint4 = { startPoint.x,startPoint.y + 2 * fontSize };
	getHorizontalLine(startPoint4, fontSize, lineWidth, true,line[3]);

	for (int i = 0; i<4; ++i)
	{
		pointSet.insert(line[i].begin(), line[i].end());
	}
}

void getNumber_4(PicPoint startPoint, int fontSize, int lineWidth, std::set<PicPoint>&pointSet)
{
	std::set<PicPoint> line[3];
	getVerticalLine(startPoint, fontSize, lineWidth, true,line[0]);
	PicPoint startPoint2 = { startPoint.x ,startPoint.y + fontSize };
	getHorizontalLine(startPoint2, fontSize, lineWidth, true,line[1]);

	PicPoint startPoint3 = { startPoint.x + fontSize ,startPoint.y };
	getVerticalLine(startPoint3, fontSize * 2, lineWidth, true,line[2]);

	for (int i = 0; i<3; ++i)
	{
		pointSet.insert(line[i].begin(), line[i].end());
	}
}
void getNumber_5(PicPoint startPoint, int fontSize, int lineWidth, std::set<PicPoint>&pointSet)
{
	std::set<PicPoint> line[5];
	getHorizontalLine(startPoint, fontSize, lineWidth, true,line[0]);
	getVerticalLine(startPoint, fontSize, lineWidth, true,line[1]);

	PicPoint startPoint3 = { startPoint.x,startPoint.y + fontSize };
	getHorizontalLine(startPoint3, fontSize, lineWidth, true,line[2]);
	PicPoint startPoint2 = { startPoint.x + fontSize,startPoint.y + fontSize };
	getVerticalLine(startPoint2, fontSize, lineWidth, true,line[3]);

	PicPoint startPoint4 = { startPoint.x,startPoint.y + 2 * fontSize };
	getHorizontalLine(startPoint4, fontSize, lineWidth, true,line[4]);

	for (int i = 0; i<5; ++i)
	{
		pointSet.insert(line[i].begin(), line[i].end());
	}
}

void getNumber_6(PicPoint startPoint, int fontSize, int lineWidth, std::set<PicPoint>&pointSet)
{
	std::set<PicPoint> line[5];
	getHorizontalLine(startPoint, fontSize, lineWidth, true,line[0]);
	getVerticalLine(startPoint, fontSize * 2, lineWidth, true,line[1]);

	PicPoint startPoint3 = { startPoint.x,startPoint.y + fontSize };
	getHorizontalLine(startPoint3, fontSize, lineWidth, true,line[2]);
	PicPoint startPoint2 = { startPoint.x + fontSize,startPoint.y + fontSize };
	getVerticalLine(startPoint2, fontSize, lineWidth, true,line[3]);

	PicPoint startPoint4 = { startPoint.x,startPoint.y + 2 * fontSize };
	getHorizontalLine(startPoint4, fontSize, lineWidth, true,line[4]);

	for (int i = 0; i<5; ++i)
	{
		pointSet.insert(line[i].begin(), line[i].end());
	}
}

void getNumber_7(PicPoint startPoint, int fontSize, int lineWidth, std::set<PicPoint>&pointSet)
{
	std::set<PicPoint> line[2];
	getHorizontalLine(startPoint, fontSize, lineWidth, true,line[0]);

	PicPoint startPoint3 = { startPoint.x + fontSize,startPoint.y };
	getVerticalLine(startPoint3, fontSize * 2, lineWidth, true,line[1]);


	for (int i = 0; i<2; ++i)
	{
		pointSet.insert(line[i].begin(), line[i].end());
	}
}

void getNumber_8(PicPoint startPoint, int fontSize, int lineWidth, std::set<PicPoint>&pointSet)
{
	std::set<PicPoint> line[5];
	getHorizontalLine(startPoint, fontSize, lineWidth, true,line[0]);
	getVerticalLine(startPoint, fontSize * 2, lineWidth, true,line[1]);

	PicPoint startPoint2 = { startPoint.x + fontSize,startPoint.y };
	getVerticalLine(startPoint2, fontSize * 2, lineWidth, true,line[2]);

	PicPoint startPoint3 = { startPoint.x,startPoint.y + 2 * fontSize };
	getHorizontalLine(startPoint3, fontSize, lineWidth, true,line[3]);

	PicPoint startPoint4 = { startPoint.x,startPoint.y + fontSize };
	getHorizontalLine(startPoint4, fontSize, lineWidth, true,line[4]);
	for (int i = 0; i<5; ++i)
	{
		pointSet.insert(line[i].begin(), line[i].end());
	}
}
void getNumber_9(PicPoint startPoint, int fontSize, int lineWidth, std::set<PicPoint>&pointSet)
{
	std::set<PicPoint> line[5];
	getHorizontalLine(startPoint, fontSize, lineWidth, true,line[0]);
	getVerticalLine(startPoint, fontSize, lineWidth, true,line[1]);

	PicPoint startPoint3 = { startPoint.x,startPoint.y + fontSize };
	getHorizontalLine(startPoint3, fontSize, lineWidth, true,line[2]);

	PicPoint startPoint2 = { startPoint.x + fontSize,startPoint.y };
	getVerticalLine(startPoint2, fontSize * 2, lineWidth, true,line[3]);

	PicPoint startPoint4 = { startPoint.x,startPoint.y + 2 * fontSize };
	getHorizontalLine(startPoint4, fontSize, lineWidth, true,line[4]);

	for (int i = 0; i<5; ++i)
	{
		pointSet.insert(line[i].begin(), line[i].end());
	}
}

void getNumber_N(char n_, PicPoint startPoint, int fontSize, int lineWidth, std::set<PicPoint>&pointSet)
{
	switch (n_)
	{
	case '0':
		getNumber_0(startPoint, fontSize, lineWidth, pointSet);
		break;
	case '1':
		getNumber_1(startPoint, fontSize, lineWidth, pointSet);
		break;
	case '2':
		getNumber_2(startPoint, fontSize, lineWidth, pointSet);
		break;
	case '3':
		getNumber_3(startPoint, fontSize, lineWidth, pointSet);
		break;
	case '4':
		getNumber_4(startPoint, fontSize, lineWidth, pointSet);
		break;
	case '5':
		getNumber_5(startPoint, fontSize, lineWidth, pointSet);
		break;
	case '6':
		getNumber_6(startPoint, fontSize, lineWidth, pointSet);
		break;
	case '7':
		getNumber_7(startPoint, fontSize, lineWidth, pointSet);
		break;
	case '8':
		getNumber_8(startPoint, fontSize, lineWidth, pointSet);
		break;
	case '9':
		getNumber_9(startPoint, fontSize, lineWidth, pointSet);
		break;
	default:
		break;
	}
}

