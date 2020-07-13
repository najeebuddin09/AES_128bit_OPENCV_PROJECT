/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/

// here all main libraries and different methods will be added that will be used in the project
#include <opencv2/opencv.hpp> // open cv library
#include <stdint.h> // for uint8_t types library
#include <iostream> // input output stream library
#include <sstream> // providing string stream classes library
#include <fstream> // for file handling library
#include <string> // for string operations

using namespace std;
using namespace cv;

const int NumberofBlocks = 4;
const int NumberofRounds = 10;
const int NumberofBytes = NumberofBlocks * NumberofBlocks;

// Print functions methods
void PrintMatrix(Mat, const char *);
void PrintArray(uint8_t *, const char *);
void PrintArrayWithRange(uint8_t *, const char *,int);
void PrintExpandedKey(uint8_t *, const char *);
void dataCopytoMatrix(Mat, uint8_t array[4][4]);

// first step key expansion
void keyExpansion(Mat, uint8_t[]);

// method to be used for both encryption and decryption
Mat addRoundKey(Mat, uint8_t *);

// AES Encryption Rounds methods
Mat subByte(Mat);
Mat shiftRows(Mat);
Mat mixColumns(Mat);

// encryption method
Mat block_encryption(Mat,Mat);

// AES Decryption Rounds methods
Mat inverseSubByte(Mat);
Mat inverseShiftRows(Mat);
Mat inverseMixColumns(Mat);

// decryption method
Mat block_decryption(Mat,Mat);

