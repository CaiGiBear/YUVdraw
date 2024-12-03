#pragma once
#include "getPoint.h"

typedef struct tagYUVcolor
{
	unsigned char y;
	unsigned char u;
	unsigned char v;
} YUVcolor;

void draw_YUV420P(unsigned char *dataY,
	unsigned char *dataU,
	unsigned char *dataV,
	int linesizeY,
	int linesizeU,
	int linesizeV,
	YUVcolor color,
	const std::set<PicPoint>&pointSet);

void draw_YUV420P_by_RGB24(unsigned char *dataY,
	unsigned char *dataU,
	unsigned char *dataV,
	int linesizeY,
	int linesizeU,
	int linesizeV,
	PicPoint yuvStartPoint,
	unsigned char *dataRgb24,
	int linesizeRgb24,
	const std::set<PicPoint>&pointSet);

void draw_YUV444P(unsigned char *dataY,
	unsigned char *dataU,
	unsigned char *dataV,
	int linesizeY,
	int linesizeU,
	int linesizeV,
	YUVcolor color,
	const std::set<PicPoint>&pointSet);