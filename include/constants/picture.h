#include "color.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

struct Picture{
	LONG width, height;
	Color* info;
	Picture(){width=height=0;info=NULL;}
	Picture(LONG height, LONG width)
		:width(width),height(height){
			info=(Color *)malloc(width*height*sizeof(Color));
			for(int i=0;i<height*width;i++)
				info[i]=Color(0,0,0);
		}
	inline void setSize(int x, int y){
		height = x;
		width = y;
		free(info);
		info=(Color *)malloc(width*height*sizeof(Color));
		for(int i=0;i<height*width;i++)
			info[i]=Color(0,0,0);
	}
	inline Color* pos(int x, int y){
		return info+(x*width)+y;
	}
	inline void setColor(int x, int y, Color p){
		*(pos(x,y)) = p;
	}
};

typedef struct {
	WORD    bfType;
	DWORD   bfSize;
	WORD    bfReserved1;
	WORD    bfReserved2;
	DWORD   bfOffBits;
} BITMAPFILEHEADER;
 
typedef struct {
	DWORD      biSize;
	LONG       biWidth;
	LONG       biHeight;
	WORD       biPlanes;
	WORD       biBitCount;
	DWORD      biCompression;
	DWORD      biSizeImage;
	LONG       biXPelsPerMeter;
	LONG       biYPelsPerMeter;
	DWORD      biClrUsed;
	DWORD      biClrImportant;
} BITMAPINFOHEADER;