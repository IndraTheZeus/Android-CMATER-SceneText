//
// Created by indra on 25-08-2019.
//

#include "opencv2/core.hpp"
#include "jni.h"
#include <opencv2/imgproc.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/features2d/features2d.hpp>



using namespace cv;
using namespace std;
void colorReg(Mat img,vector<Point>region);

extern "C"
JNIEXPORT jintArray JNICALL Java_com_example_dell_scenetextrecognizer_MainActivity_TextDetect(
        JNIEnv *env, jclass clazz, jlong addr_rgba){

    Mat *img = (Mat *)addr_rgba;
    Mat src;
    cvtColor(*img,src,COLOR_BGR2GRAY);
    Ptr<MSER> ms = MSER::create();
    vector<vector<Point> >regions;
    vector<cv::Rect> mser_bbox;
    ms->detectRegions(src,regions,mser_bbox);
    for(int i=0;i<regions.size();i++){
        colorReg(*img,regions[i]);
    }

    jintArray intJavaArray;
    intJavaArray = (env)->NewIntArray(3);
    int arr[] = {1,2,3};
    int *intCArray = arr;

    if ( NULL == intJavaArray ) {

        if ( NULL != intCArray ) {
            free(intCArray);
        }
        return NULL;
    }

    (env)->SetIntArrayRegion(intJavaArray, 0, 3, intCArray);

    return intJavaArray;
    //cv::Mat test(cv::Size(img.cols, img.rows), CV_64FC1);

    /*for(int i=0;i<img.rows;i++){
        for(int j=0;j<img.cols;j++){
            img.at<Vec3b>(i,j)[0] = uchar(0);
            img.at<Vec3b>(i,j)[1] = uchar(0);
            img.at<Vec3b>(i,j)[2] = uchar(255);
        }
    }*/
   // img = test;
      //cvtColor(img,img,COLOR_RGB2GRAY);

      //return out;
}



void colorReg(Mat img,vector<Point>region){
    int r = rand()%255,b=rand()%255,g=rand()%255;
    for(int j=0;j<region.size();j++){
        img.at<Vec4b>(region[j])[0] = b;
        img.at<Vec4b>(region[j])[1] = g;
        img.at<Vec4b>(region[j])[2] = r;
    }
}