#include "picture.h"
struct Point{
	double x, y;
	Point(double x = 0.0, double y = 0.0)
		:x(x),y(y){}
};
struct Video{
	Picture* stream;
	
}