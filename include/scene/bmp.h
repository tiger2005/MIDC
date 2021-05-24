#include "../constants/picture.h"

#include <cmath>
bool saveBitmap(Picture& pic, const char* loc){
	const int height = pic.height;
	const int width = pic.width;
	const int lineByte = (width * 24 / 8 + 3) / 4 * 4;
	const int size = lineByte * height;
	BYTE idlBy = 0;
	BITMAPFILEHEADER fileHeader;
	fileHeader.bfType = 0x4D42;
	fileHeader.bfReserved1 = 0;
	fileHeader.bfReserved2 = 0;
	fileHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + size;
	fileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	BITMAPINFOHEADER bitmapHeader = { 0 };
	bitmapHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitmapHeader.biHeight = height;
	bitmapHeader.biWidth = width;
	bitmapHeader.biPlanes = 1;
	bitmapHeader.biBitCount = 24;
	bitmapHeader.biSizeImage = size;
	bitmapHeader.biCompression = 0;
	FILE *output = fopen(loc, "wb");
	if (output == NULL)
		return false;
	fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, output);
	fwrite(&bitmapHeader, sizeof(BITMAPINFOHEADER), 1, output);
	const int idl = lineByte - 3 * width;
	for(int i=height-1;i>=0;i--){
		for(int j=0;j<width;j++){
			idlBy = (pic.pos(i,j)->B);
			fwrite(&idlBy, sizeof(BYTE), 1, output);
			idlBy = (pic.pos(i,j)->G);
			fwrite(&idlBy, sizeof(BYTE), 1, output);
			idlBy = (pic.pos(i,j)->R);
			fwrite(&idlBy, sizeof(BYTE), 1, output);
		}
		if(!idl)	continue;
		idlBy=0;
		for(int j=0;j<idl;j+=sizeof(BYTE))
			fwrite(&idlBy, sizeof(BYTE), 1, output);
	}
	fclose(output);
	return true;
}
inline bool saveBitmap(Picture& pic, std::string loc){
	return saveBitmap(pic, loc.c_str());
}