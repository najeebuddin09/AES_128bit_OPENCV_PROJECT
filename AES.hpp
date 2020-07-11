/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/

// here all main libraries will be added that will be used in the project
#include <opencv2/opencv.hpp>
#include <stdint.h>
#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;

Mat subByte(Mat );
Mat shiftRows(Mat ); 
void block_encryption();

