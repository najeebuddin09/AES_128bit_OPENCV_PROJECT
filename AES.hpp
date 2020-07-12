/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/

// here all main libraries and different methods will be added that will be used in the project
#include <opencv2/opencv.hpp>
#include <stdint.h>
#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;

const int NumberofBlocks = 4;
const int NumberofRounds = 10;

// first step key expansion
void keyExpansion(Mat, uint8_t[]);

// method to be used for both encryption and decryption
Mat addRoundKey(Mat, uint8_t *);

// AES Encryption Rounds methods
Mat subByte(Mat);
Mat shiftRows(Mat);
Mat mixColumns(Mat);

// encryption method
void block_encryption();

// AES Decryption Rounds methods
Mat inverseSubByte(Mat );

// decryption method
void block_decryption();
