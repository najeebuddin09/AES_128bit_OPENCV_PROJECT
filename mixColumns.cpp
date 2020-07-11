/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/

#include "AES.hpp"
#include "lookup_tables.hpp"

Mat mixColumns(Mat state) {

    Mat temp(NumberofBlocks,NumberofBlocks,CV_8UC1);

    temp = state;

    /*

        for mix columns we have to dot product each column of our state
        or data with the matrix to get the each column which will be reult of mix columns
        {
            2 , 3 , 1 , 1
            1 , 2 , 3 , 1
            1 , 1 , 2 , 3
            3 , 1 , 1 , 2
        }

    */

   uint8_t column_picker[NumberofBlocks];
   uint8_t mix_column_value[NumberofBlocks];

   // first step is to pick all rows data from a single column like 0,0 1,0 2,0 3,0 etc
   // and then looking for lookup tables for that value

   for (int col=0;col<NumberofBlocks;col++)
   {
       for(int row=0;row<NumberofBlocks;row++)
       {
           // picking each column data
           column_picker[row] = state.at<uint8_t>(row,col);
       }
        // calculating values from lookup tables
        mix_column_value[0] = multiplier2[column_picker[0]/16][column_picker[0]%16] ^ multiplier3[column_picker[1]/16][column_picker[1]%16] ^ column_picker[2] ^ column_picker[3];
        mix_column_value[1] = column_picker[0] ^ multiplier2[column_picker[1]/16][column_picker[1]%16] ^ multiplier3[column_picker[2]/16][column_picker[2]%16] ^ column_picker[3];
        mix_column_value[2] = column_picker[0] ^ column_picker[1] ^ multiplier2[column_picker[2]/16][column_picker[2]%16] ^ multiplier3[column_picker[3]/16][column_picker[3]%16];
        mix_column_value[3] = multiplier3[column_picker[0]/16][column_picker[0]%16] ^ column_picker[1] ^ column_picker[2] ^ multiplier2[column_picker[3]/16][column_picker[3]%16]; 

        // storing the mix column results column wise
        for (int rows=0;rows<NumberofBlocks;rows++)
        {
            temp.at<uint8_t>(rows,col) = mix_column_value[rows];
        }
   }

    // returning the newly Mat
    return temp;

}
