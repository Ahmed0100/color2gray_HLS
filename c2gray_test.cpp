#include <hls_opencv.h>
#include "convert.h"

int main()
{
	IplImage* src;
	IplImage* dst;
	AXI_STREAM src_axi,dst_axi;
	src= cvLoadImage("lena.bmp");
	dst = cvCreateImage(cvGetSize(src),src->depth,src->nChannels);
	IplImage2AXIvideo(src,src_axi);
	convert(src_axi,dst_axi, src->height,src->width);
	AXIvideo2IplImage(dst_axi,dst);
	cvSaveImage("lenaOut.bmp",dst);
	cvReleaseImage(&src);
	cvReleaseImage(&dst);
	return 0;
}
