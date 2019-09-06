//
// Created by indra on 25-08-2019.
//

#include "opencv2/core.hpp"
#include "jni.h"
#include <opencv2/imgproc.hpp>


using namespace cv;
using namespace std;
extern "C"
JNIEXPORT void JNICALL Java_com_example_dell_scenetextrecognizer_MainActivity_TextDetect(
        JNIEnv *env, jclass clazz, jlong addr_rgba){

      Mat &img = *(Mat *)addr_rgba;
      cvtColor(img,img,COLOR_RGB2GRAY);
}
