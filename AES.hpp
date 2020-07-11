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

const int NumberofBlocks = 4;

Mat subByte(Mat );
Mat shiftRows(Mat );
Mat mixColumns(Mat );
void block_encryption();

