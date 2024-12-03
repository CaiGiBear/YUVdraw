
#include "core/getPoint.h"
#include "core/drawData.h"
#include "test/buildNumber.h"
#include <string>

int main()
{
	/* read file */
	FILE *file;
	char *buffer;
	long file_size;
	errno_t er = fopen_s(&file,"pic_640x480.yuv420", "rb");
	if (er != 0)
	{
		return 0;
	}

	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	rewind(file);

	buffer = (char *)malloc(file_size * sizeof(char));
	if (buffer == NULL)
	{
		return 0;
	}
	fread(buffer, 1, file_size, file);
	fclose(file);

	//yuv data
	int picH = 480;
	unsigned char *dataY = (unsigned char *)buffer;
	int lineSizeY = 640; //data no padding
	unsigned char *dataU = (unsigned char *)(buffer + lineSizeY * picH);
	int lineSizeU = 640 / 2;
	unsigned char *dataV = (unsigned char *)(dataU + lineSizeU * picH / 2);
	int lineSizeV = 640 / 2;

	/* draw data */ 
	//test number
	int drawNumber = 1234567890;
	const int maxNum = 10;
	std::set<PicPoint> number[maxNum];
	std::string strNumber = std::to_string(drawNumber);
	int fontSzie = 12, delta = 20, lineW = 1;
	PicPoint startPoint{50,50};
	for (unsigned int i = 0; i < strNumber.size(); ++i)
	{
		char charDigit = strNumber[i];
		getNumber_N(charDigit, startPoint, fontSzie, lineW, number[i]);
		startPoint = {startPoint .x + delta,startPoint.y };
	}
	std::set<PicPoint> allPoint;
	for (int i = 0; i <maxNum; ++i)
	{
		allPoint.insert(number[i].begin(), number[i].end());
	}
	draw_YUV420P(dataY,
		dataU,
		dataV,
		lineSizeY,
		lineSizeU,
		lineSizeV,
		{ 76,94,221 }, //red
		allPoint);

	//test triangle
	allPoint.clear();
	std::set<PicPoint> DlinePoints[3];
	getDiagonalLine({ 180,200 }, { 100,400 }, 1, DlinePoints[0]);
	allPoint.insert(DlinePoints[0].begin(), DlinePoints[0].end());
	getDiagonalLine({ 180,200 }, {250,360}, 1, DlinePoints[1]);
	allPoint.insert(DlinePoints[1].begin(), DlinePoints[1].end());
	getDiagonalLine({ 250,360 }, { 100,400 }, 1, DlinePoints[2]);
	allPoint.insert(DlinePoints[2].begin(), DlinePoints[2].end());
	draw_YUV420P(dataY,
		dataU,
		dataV,
		lineSizeY,
		lineSizeU,
		lineSizeV,
		{ 135,76,42 }, 
		allPoint);

	//test Circle
	std::set<PicPoint> CirclePoints;
	getCirclePoints({ 400 ,300 }, 80, 1, CirclePoints);
	draw_YUV420P(dataY,
		dataU,
		dataV,
		lineSizeY,
		lineSizeU,
		lineSizeV,
		{ 29,213,64 },
		CirclePoints);

	//test Rectangle draw pic
	char *bufferRGB24;
	FILE *fileRGB;
	errno_t err = fopen_s(&fileRGB, "ik_64x88.rgb24", "rb");
	if (err != 0)
	{
		return 0;
	}
	fseek(fileRGB, 0, SEEK_END);
	int fsize = ftell(fileRGB);
	rewind(fileRGB);
	bufferRGB24 = (char *)malloc(fsize * sizeof(char));
	if (bufferRGB24 == NULL)
	{
		return 0;
	}
	fread(bufferRGB24, 1, fsize, file);
	fclose(fileRGB);

	unsigned char *rgbData = (unsigned char *)bufferRGB24;
	int lineSizeRgb = 64;
	unsigned int rgbW = 64;
	unsigned int rgbH = 88;
	PicPoint dwStart{ 500,100 };

	allPoint.clear();
	std::set<PicPoint> RectanglePoints;
	getRectanglePoint(dwStart, { dwStart.x + rgbW-1 ,dwStart.y + rgbH-1 }, RectanglePoints);
	draw_YUV420P_by_RGB24(dataY,
		dataU,
		dataV,
		lineSizeY,
		lineSizeU,
		lineSizeV,
		dwStart,
		rgbData,
		lineSizeRgb,
		RectanglePoints);
	free(bufferRGB24);

	/* save data */
	FILE *fileSave;
	errno_t er2 = fopen_s(&fileSave, "pic_640x480_output.yuv420", "wb");
	if (er2 != 0)
	{
		return 0;
	}
	fwrite(buffer, 1, file_size, fileSave);
	fclose(fileSave);
	free(buffer);

	return 0;
}