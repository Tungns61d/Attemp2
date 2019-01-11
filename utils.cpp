#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//#include <opencv2/tracking.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat Laplace_Gaussian(Mat image){
    if(image.empty()){
    cout << "can't open or read image" << endl;
    }else{

        Mat src, src_gray, dst;
        int kernel_size = 3;
        int scale = 1;
        int delta = 0;
        int ddepth = CV_16S;
     
        src = image;

        GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );
     cvtColor( src, src_gray, CV_BGR2GRAY );

        Mat abs_dst;

        Laplacian( src_gray, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT );
        convertScaleAbs( dst, abs_dst );

         imshow("Laplace_Gaussian", abs_dst);
        return abs_dst;
    }
}
 

Mat Gaussian_Blur(Mat image){

  //check image valid
  if(image.empty()){
  cout << "can't open or read image" << endl;
  }else{

       Mat src = image;

      GaussianBlur( src, src, Size(5,5), 0, 0, BORDER_DEFAULT );
       imshow("GaussianBlur", src);
      return src;
  }
}

Mat Contrast(Mat image){

  //check image valid
  if(image.empty()){
  cout << "can't open or read image" << endl;
  }else{

       Mat imageContrastHigh;

       image.convertTo(imageContrastHigh, -1, 1.5, 0);
       imshow("Contrast", imageContrastHigh);
      return imageContrastHigh;
  }
}

Mat Threshold(Mat image){

  if(image.empty()){
    cout << "can't open or read image" << endl;
  }else{
    int threshold_value = 100;
    int threshold_type = 3;
    int const max_value = 255;//255;
    //int const max_type = 4;//4;
    int const max_BINARY_value = 255;//255;
    Mat src_gray, dst;

    cvtColor( image , src_gray, CV_BGR2GRAY );
   
    threshold( src_gray, dst, threshold_value, max_BINARY_value,threshold_type );
     imshow("Threshold", dst);
    return dst;
  
    }
}
