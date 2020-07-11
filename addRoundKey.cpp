/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/

#include "AES.hpp"

Mat addRoundKey(Mat state,uint8_t * key)
{
    
    Mat temp(NumberofBlocks,NumberofBlocks,CV_8UC1);
    temp = state;
    uint8_t index = 0;
    for(int row=0;row<NumberofBlocks;row++)
    {
        for(int col=0;col<NumberofBlocks;col++)
        {
            temp.at<uint8_t>(row,col) = state.at<uint8_t>(row,col) ^ key[index];
            index++;
        }
    }

    return temp;
}