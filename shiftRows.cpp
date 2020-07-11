/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/

#include "AES.hpp"

void shiftRow(Mat , int , int);

Mat shiftRows(Mat state) {

    shiftRow(state,1,1);
    shiftRow(state,2,2);
    shiftRow(state,3,3);

    return state;
    
}

void shiftRow(Mat state,int row,int shifts) {

    uint8_t x;
    for(int i=0;i<shifts;i++)
    {
        x = state.at<uint8_t>(row,0);
        for (int j=0;j<NumberofBlocks - 1;j++)
        {
            state.at<uint8_t>(row,j) = state.at<uint8_t>(row,j+1);
        }
        state.at<uint8_t>(row,NumberofBlocks - 1) = x;
    }
}