/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/

// This file will contain the whole algorithm and steps for encryption of data

#include "AES.hpp"

void PrintMatrix (Mat ,const char *);
void PrintArray(uint8_t *, const char *);
void PrintExpandedKey(uint8_t *, const char *);

void block_encryption() {
    uint8_t data[NumberofBlocks][NumberofBlocks] = {
        0x19, 0xa0, 0x9a, 0xe9,
        0x3d, 0xf4, 0xc6, 0xf8,
        0xe3, 0xe2, 0x8d, 0x48,
        0xbe, 0x2b, 0x2a, 0x08
    };

    // one d array for key which is 16 bytes of key or 128 bit key
    uint8_t key[NumberofBlocks*NumberofBlocks] = {
        0xa0, 0x88, 0x23, 0x2a,
        0xfa, 0x54, 0xa3, 0x6c,
        0xfe, 0x2c, 0x39, 0x76,
        0x17, 0xb1, 0x39, 0x05
    };

    Mat block(NumberofBlocks,NumberofBlocks,CV_8UC1);

    for (int i=0; i<NumberofBlocks; i++){
        for (int j=0; j<NumberofBlocks; j++){
            block.at<uint8_t>(i,j) = data[i][j];
        }
    } 


    // for 10 rounds and one initial round we will need different keys for encryption
    // so we will use AES keyExpansion concept to expand the key upto 176 bytes 
    // 11 rounds  = 16 bytes for each round
    // here we declare a pointer expandedKey which will contain the expanded key of 176 bytes 
    uint8_t expandedKey[NumberofBlocks * NumberofBlocks * (NumberofRounds + 1)];
    // passsing the key to be expanded by 176 bytes for all rounds and storing in expandedKey algorithm
    keyExpansion(key , expandedKey);
    
    Mat afterSubByte = subByte(block);
    Mat afterShiftRows = shiftRows(afterSubByte);
    Mat afterMixColumns = mixColumns(afterShiftRows);
    Mat afterAddRoundKey = addRoundKey(afterMixColumns,expandedKey);
}

void PrintMatrix(Mat matrix ,const char * sentence)
{
    cout<<endl<<sentence<<endl;
    for(int row=0;row<NumberofBlocks;row++)
    {
        for(int col=0;col<NumberofBlocks;col++)
        {
            cout<<std::hex<<(int)matrix.at<uint8_t>(row,col)<<" ";
        }
        cout<<endl;
    }
}

void PrintArray(uint8_t * array , const char * sentence)
{
    cout<<endl<<sentence<<endl;
    for (int i=0;i<16;i++)
    {
        cout<<std::hex<<(int)array[i]<<" ";
    }
}

void PrintExpandedKey(uint8_t * array , const char * sentence)
{
    int index = 1;
    cout<<endl<<sentence<<endl;
    for (int i=0;i<176;i++)
    {
        cout<<std::hex<<(int)array[i]<<" ";
        index++;
        if(index % 16 == 0)
        {
            cout<<endl;
        }
    }
}