//
//  main.cpp
//  openCV test2
//
//  Created by Steve X on 2018/3/4.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void drawText(Mat & image);

int main() {
    cout << "Built with OpenCV " << CV_VERSION << endl;
    Mat image;
    VideoCapture capture;
    capture.open(0);
    if (capture.isOpened()) {
        cout << "Capture is opened" << endl;
        for (;;) {
            capture >> image;
            if (image.empty())
                break;
            drawText(image);
            imshow("Sample", image);
            if (waitKey(10) == 27)
                break;
        }
    } else {
        cout << "No capture" << endl;
        image = Mat::zeros(480, 640, CV_8UC1);
        drawText(image);
        imshow("Sample", image);
        waitKey(0);
    }
    return 0;
}

void drawText(Mat & image) {
    putText(image, "Hello OpenCV",
            Point(20, 50),
            FONT_HERSHEY_COMPLEX, 1, // font face and scale
            Scalar(255, 255, 255), // white
            1, LINE_AA); // line thickness and type
}

/*
//

//  main.cpp

//  cvtest

//

//  Created by Sean on 16/1/19.

//  Copyright © 2016年 Sean. All rights reserved.

//



#include <iostream>

#include <opencv2/core/core.hpp>

#include <opencv2/highgui/highgui.hpp>

#include <opencv2/opencv.hpp>



using namespace std;

using namespace cv;



IplImage* doCanny(IplImage* image_input,
                  
                  double lowThresh,
                  
                  double highThresh,
                  
                  double aperture)

{
    
    if(image_input->nChannels != 1)
        
        return (0);
    
    
    
    IplImage* image_output = cvCreateImage(cvGetSize(image_input),
                                           
                                           image_input->depth,
                                           
                                           image_input->nChannels);
    
    
    
    cvCanny(image_input,image_output,lowThresh,highThresh,aperture);
    
    
    
    return(image_output);
    
}





int main(int argc, char* argv[])

{
    
    cvNamedWindow("Camera" , CV_WINDOW_AUTOSIZE );
    
    
    
    CvCapture* capture = cvCreateCameraCapture(CV_CAP_ANY);
    
    
    
    assert(capture != NULL);
    
    
    
    IplImage *frame = 0;
    
    frame = cvQueryFrame(capture);
    
    
    
    IplImage *frame_edge = cvCreateImage(cvGetSize(frame),
                                         
                                         IPL_DEPTH_8U,
                                         
                                         1);
    
    while(1)
        
    {
        
        frame = cvQueryFrame(capture);
        
        if(!frame) break;
        
        
        
        cvConvertImage(frame,frame_edge,0);
        
        frame = cvCloneImage(frame_edge);
        
        
        
        frame_edge = doCanny(frame_edge,70,90,3);
        
        
        
        cvShowImage("Camera",frame_edge);
        
        char c = cvWaitKey(15);
        
        if(c == 27)  break;
        
    }
    
    
    
    cvReleaseCapture(&capture);
    
    cvReleaseImage( &frame_edge );
    
    cvReleaseImage( &frame);
    
    
    
    
    
    return (int)0;
    
}*/
