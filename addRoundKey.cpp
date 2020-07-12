/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/

#include "AES.hpp"

Mat addRoundKey(Mat state, uint8_t * key)
{
    cout<<endl<<endl<<"This is me printing from round key"<<endl;
    for(int i=0;i<16;i++)
    {
       cout<<std::hex<<(int)key[i]<<" ";
    }
    cout<<endl<<endl<<"Finished"<<endl;


    Mat temp(NumberofBlocks, NumberofBlocks, CV_8UC1);
    temp = state;
    for (int row = 0; row < NumberofBlocks; row++)
    {
        for (int col = 0; col < NumberofBlocks; col++)
        {
            temp.at<uint8_t>(row, col) = state.at<uint8_t>(row, col) ^ key[row + 4 * col];
        }
    }

    return temp;
}