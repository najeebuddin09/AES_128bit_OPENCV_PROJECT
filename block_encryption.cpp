/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/

// This file will contain the whole algorithm and steps for encryption of data

#include "AES.hpp"

void PrintMatrix(Mat, const char *);
void PrintArray(uint8_t *, const char *);
void PrintExpandedKey(uint8_t *, const char *);
void dataCopytoMatrix(Mat, uint8_t array[4][4]);

void block_encryption()
{
    // for AES one block of data will be 16 bytes or 4x4 2d array
    uint8_t data[NumberofBlocks][NumberofBlocks] = 
    {
        0x19, 0xa0, 0x9a, 0xe9,
        0x3d, 0xf4, 0xc6, 0xf8,
        0xe3, 0xe2, 0x8d, 0x48,
        0xbe, 0x2b, 0x2a, 0x08
    };

    /*
        practice keys

        0xa0, 0x88, 0x23, 0x2a,
        0xfa, 0x54, 0xa3, 0x6c,
        0xfe, 0x2c, 0x39, 0x76,
        0x17, 0xb1, 0x39, 0x05

        0x2b, 0x28, 0xab, 0x09,
        0x7e, 0xae, 0xf7, 0xcf,
        0x15, 0xd2, 0x15, 0x4f,
        0x16, 0xa6, 0x88, 0x3c

        0x00, 0x01, 0x02, 0x03,
        0x04, 0x05, 0x06, 0x07, 
        0x08, 0x09, 0x0a, 0x0b, 
        0x0c, 0x0d, 0x0e, 0x0f

    */

    // 16 bytes of key or 128 bits of key
    uint8_t key[NumberofBlocks][NumberofBlocks] = 
    {
        {0xa0, 0x88, 0x23, 0x2a},
        {0xfa, 0x54, 0xa3, 0x6c},
        {0xfe, 0x2c, 0x39, 0x76},
        {0x17, 0xb1, 0x39, 0x05}
    };

    // creating 2 open CV matrix of 4x4 size
    Mat block(NumberofBlocks, NumberofBlocks, CV_8UC1);
    Mat keyBlock(NumberofBlocks, NumberofBlocks, CV_8UC1);

    // copying the data from 2d arrays to matrix
    dataCopytoMatrix(block, data);
    dataCopytoMatrix(keyBlock, key);
    

    // for 10 rounds and one initial round we will need different keys for encryption
    // so we will use AES keyExpansion concept to expand the key upto 176 bytes
    // 11 rounds  = 16 bytes for each round but first 16 bytes will be orignal key which will
    // be used in the inital Round
    // here we declare expandedKey array which will contain the expanded key of 176 bytes
    uint8_t expandedKey[NumberofBlocks * NumberofBlocks * (NumberofRounds + 1)];
    // passsing the key to be expanded by 176 bytes for all rounds and storing in expandedKey algorithm
    keyExpansion(keyBlock, expandedKey);

    PrintExpandedKey(expandedKey, "The expanded key is");


    Mat afterSubByte = subByte(block);
    Mat afterShiftRows = shiftRows(afterSubByte);
    Mat afterMixColumns = mixColumns(afterShiftRows);
    Mat afterAddRoundKey = addRoundKey(afterMixColumns, expandedKey);
    PrintMatrix(afterAddRoundKey,"After round key");
}

void PrintMatrix(Mat matrix, const char *sentence)
{
    cout << endl << sentence << endl;
    for (int row = 0; row < NumberofBlocks; row++)
    {
        for (int col = 0; col < NumberofBlocks; col++)
        {
            cout << std::hex << (int)matrix.at<uint8_t>(row, col) << " ";
        }
        cout << endl;
    }
}

void PrintArray(uint8_t *array, const char *sentence)
{
    cout << endl << sentence << endl;
    for (int i = 0; i < 16; i++)
    {
        cout << std::hex << (int)array[i] << " ";
    }
}

void PrintExpandedKey(uint8_t *array, const char *sentence)
{
    int index = 0;
    cout << endl << sentence << endl;
    for (int i = 0; i < 176; i++)
    {
        cout << std::hex << (int)array[i] << " ";
        index++;
        if (index % 16 == 0 && index != 0)
        {
            cout << endl;
        }
    }
}

void dataCopytoMatrix(Mat mat, uint8_t array[4][4])
{
    for (int i = 0; i < NumberofBlocks; i++)
    {
        for (int j = 0; j < NumberofBlocks; j++)
        {
            mat.at<uint8_t>(i, j) = array[i][j];
        }
    }
}