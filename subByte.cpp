/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/

#include "AES.hpp"
#include "SBOX.hpp"

Mat subByte (Mat state) {
    
    Mat temp(4,4,CV_8UC1);
    uint8_t x;
    for (int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            x = state.at<uint8_t>(i,j);
            temp.at<uint8_t>(i,j) = sbox[x/16][x%16];
        }
    }
    return temp;
}
