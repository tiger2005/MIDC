#include "scene/bmp.h"
#include "video/video.h"

Picture pic;
char fName[50];
int main(){
	pic.setSize(1080, 1920);
	for(int q=0;q<3;q++){
		for(int i=0;i<1080;i++)
			for(int j=std::max(i-10, 0);j<=i;j++)
				pic.setColor(i, j, Color(i/2, j/2, q*2));
		sprintf(fName, "images/colorTest/%d.bmp", q);
		printf("%d - %d\n", q, saveBitmap(pic, fName));
	}
	printf("%d",bmpToVideo("images/colorTest/%d.bmp", 0, 1080, 1920, 60, "video/colorTest.mp4"));
}