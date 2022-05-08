#include "c2gray.h"
void convert(AXI_STREAM& inStream, AXI_STREAM & outStream,int rows,int cols)
{
#pragma HLS INTERFACE s_axilite port=return bundle=CRTL
#pragma HLS INTERFACE port=cols bundle=CRTL
#pragma HLS INTERFACE s_axilite port=rows bundle=CRTL
#pragma HLS INTERFACE axis register both port=outStream
#pragma HLS INTERFACE axis register both port=inStream

	RGB_IMG img0(rows,cols);
	GRAY_IMG img1(rows,cols);
	RGB_IMG img2(rows,cols);
#pragma HLS DATAFLOW
	hls::AXIvideo2Mat(inStream,img0);
	hls::CvtColor<HLS_BGR2GRAY>(img0,img1);
	hls::CvtColor<HLS_GRAY2RGB>(img1,img2);
	hls::Mat2AXIvideo(img2,outStream);
}
