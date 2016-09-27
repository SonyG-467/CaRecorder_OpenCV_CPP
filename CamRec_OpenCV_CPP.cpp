#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
/*
Bus 001 Device 003: ID 05a3:9230 ARC International 
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 002 Device 003: ID 0e0f:0002 VMware, Inc. Virtual USB Hub
Bus 002 Device 002: ID 0e0f:0003 VMware, Inc. Virtual Mouse
Bus 002 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub

*/
int i=0;
    VideoCapture vcap(0); 
	//cout << "Webcam name  :: "<< vcap(9230) <<endl;
      if(!vcap.isOpened()){
             cout << "Error opening video stream or file" << endl;
             return -1;
      }

   int frame_width=   vcap.get(CV_CAP_PROP_FRAME_WIDTH);
   int frame_height=   vcap.get(CV_CAP_PROP_FRAME_HEIGHT);
   cout << "Frame Size :: " <<frame_width << "X"<<frame_height << endl;
   VideoWriter video("out.avi",CV_FOURCC('M','J','P','G'),10, Size(frame_width,frame_height),true);

   for(;;){

       Mat frame;
       vcap >> frame;
       video.write(frame);
       i++;
       cout << i;
       imshow( "Frame", frame );
       char c = (char)waitKey(33);
       if( c == 27 ) 
		{
			cout << "User pressed Esc key...." << endl;
			break;
		}
    }
  return 0;
}


