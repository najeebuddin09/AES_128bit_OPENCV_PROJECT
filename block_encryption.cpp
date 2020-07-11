/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/

// This file will contain the whole algorithm and steps for encryption of data

#include "AES.hpp"

const int numberofBlocks = 4;

void block_encryption() {
    uint8_t data[4][4] = {
        0x19, 0xa0, 0x9a, 0xe9,
        0x3d, 0xf4, 0xc6, 0xf8,
        0xe3, 0xe2, 0x8d, 0x48,
        0xbe, 0x2b, 0x2a, 0x08
    };

    Mat block(4,4,CV_8UC1);

    for (int i=0; i<numberofBlocks; i++){
        for (int j=0; j<numberofBlocks; j++){
            block.at<uint8_t>(i,j) = data[i][j];
        }
    } 

    


}