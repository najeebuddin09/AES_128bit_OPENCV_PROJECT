/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/

#include "AES.hpp"
#include "lookup_tables.hpp"

Mat subByte (Mat state) {

    Mat temp(NumberofBlocks,NumberofBlocks,CV_8UC1);
    uint8_t x;
    for (int i=0;i<NumberofBlocks;i++)
    {
        for(int j=0;j<NumberofBlocks;j++)
        {
            x = state.at<uint8_t>(i,j);
            temp.at<uint8_t>(i,j) = sbox[x/16][x%16];
        }
    }
    return temp;
}
