#include <string>
#include <cmath>
#include <algorithm>
#include <mutex>

#define FLT_DIG         6                       /* # of decimal digits of precision */
#define FLT_EPSILON     1.192092896e-07F        /* smallest such that 1.0+FLT_EPSILON != 1.0 */
#define FLT_GUARD       0
#define FLT_MANT_DIG    24                      /* # of bits in mantissa */
#define FLT_MAX         3.402823466e+38F        /* max value */
#define FLT_MAX_10_EXP  38                      /* max decimal exponent */
#define FLT_MAX_EXP     128                     /* max binary exponent */
#define FLT_MIN         1.175494351e-38F        /* min positive value */
#define FLT_MIN_10_EXP  (-37)                   /* min decimal exponent */
#define FLT_MIN_EXP     (-125)                  /* min binary exponent */
#define FLT_NORMALIZE   0
#define FLT_RADIX       2                       /* exponent radix */
#define FLT_ROUNDS      1                       /* addition rounding: near */
#define DBL_MAX         1.7976931348623158e+308 /* max value */
#define DBL_MIN         2.2250738585072014e-308 /* min positive value */
#define FLT_EPSILON     1.192092896e-07F
#define DBL_EPSILON     __DBL_EPSILON__
#define LDBL_EPSILON    __LDBL_EPSILON__

#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/videoio/videoio.hpp"

#pragma comment(lib, "../../lib/opencv_calib3d452.lib")
#pragma comment(lib, "../../lib/opencv_core452.lib")
#pragma comment(lib, "../../lib/opencv_dnn452.lib")
#pragma comment(lib, "../../lib/opencv_features2d452.lib")
#pragma comment(lib, "../../lib/opencv_flann452.lib")
#pragma comment(lib, "../../lib/opencv_gapi452.lib")
#pragma comment(lib, "../../lib/opencv_highgui452.lib")
#pragma comment(lib, "../../lib/opencv_imgcodecs452.lib")
#pragma comment(lib, "../../lib/opencv_imgproc452.lib")
#pragma comment(lib, "../../lib/opencv_ml452.lib")
#pragma comment(lib, "../../lib/opencv_objdetect452.lib")
#pragma comment(lib, "../../lib/opencv_photo452.lib")
#pragma comment(lib, "../../lib/opencv_stitching452.lib")
#pragma comment(lib, "../../lib/opencv_video452.lib")
#pragma comment(lib, "H:\\Project\\MIDC\\lib\\opencv_videoio452.lib")

bool bmpToVideo(const char* format, int from, int to, int height, int width, int fps, const char* outputLoc){
	char image_name[50];
	cv::VideoWriter writer;
	int isColor = 1;
	int frame_fps = fps;
	int frame_width = width;
	int frame_height = height;
	using namespace cv;
	writer = VideoWriter(outputLoc,VideoWriter::fourcc('X', 'V', 'I', 'D'),frame_fps,Size(frame_width,frame_height),isColor);
	Mat img;
	for(int i=from;i<=to;i++){
		sprintf(image_name, format, i);
		img = imread(image_name);
		if (!img.data)	return false;
		writer.write(img);	
	}
	return true;
}