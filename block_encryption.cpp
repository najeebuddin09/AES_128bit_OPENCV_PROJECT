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

    /*
        practice data

        0x19, 0xa0, 0x9a, 0xe9,
        0x3d, 0xf4, 0xc6, 0xf8,
        0xe3, 0xe2, 0x8d, 0x48,
        0xbe, 0x2b, 0x2a, 0x08

        0x32, 0x88, 0x31, 0xe0,
        0x43, 0x5a, 0x31, 0x37,
        0xf6, 0x30, 0x98, 0x07,
        0xa8, 0x8d, 0xa2, 0x34
    
    */

    uint8_t data[NumberofBlocks][NumberofBlocks] = 
    {
        0x32, 0x88, 0x31, 0xe0,
        0x43, 0x5a, 0x31, 0x37,
        0xf6, 0x30, 0x98, 0x07,
        0xa8, 0x8d, 0xa2, 0x34
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
        0x2b, 0x28, 0xab, 0x09,
        0x7e, 0xae, 0xf7, 0xcf,
        0x15, 0xd2, 0x15, 0x4f,
        0x16, 0xa6, 0x88, 0x3c
    };

    // creating 2 open CV matrix of 4x4 size
    Mat block(NumberofBlocks, NumberofBlocks, CV_8UC1);
    Mat keyBlock(NumberofBlocks, NumberofBlocks, CV_8UC1);
    Mat afterAddRoundKey(NumberofBlocks, NumberofBlocks, CV_8UC1);

    // copying the data from 2d arrays to matrix
    dataCopytoMatrix(block, data);
    dataCopytoMatrix(keyBlock, key);
    

    // for 10 rounds and one initial round we will need different keys for encryption
    // so we will use AES keyExpansion concept to expand the key upto 176 bytes
    // 11 rounds  = 16 bytes for each round but first 16 bytes will be orignal key which will
    // be used in the inital Round
    // here we declare expandedKey array which will contain the expanded key of 176 bytes
    uint8_t expandedKey[NumberofBlocks * NumberofBlocks * (NumberofRounds + 1)];

    // passsing the key to be expanded by 176 bytes for all rounds and storing in expandedKey array
    // keyExpansion method wiil return a expanded key for all rounds consisting of 176 bytes
    
    keyExpansion(keyBlock, expandedKey);
    
    //PrintMatrix(keyBlock,"The orignal key is");
    //PrintExpandedKey(expandedKey, "The expanded key is");

    // now from here we will call AES encryption rounds to encrypt our data
    // first will be inital round where data and orignal cipher key will be XORED
    Mat state = addRoundKey(block,expandedKey); 
    PrintMatrix(state,"after Initial Round");

    // total rounds = 10 by in one round Mix Column will not be called
    for (int i=1; i <= NumberofRounds-1; i++)
    {
        state = subByte(state);
        //PrintMatrix(state,"After Sub Byte");
        state = shiftRows(state);
        //PrintMatrix(state,"After Shift Rows");
        state = mixColumns(state);
        //PrintMatrix(state,"After Mix Column");
        state = addRoundKey(state, expandedKey + i * 16 );
        //PrintMatrix(state,"After add round key");
    }
    
    // final round without mix column
    state = subByte(state);
    state = shiftRows(state);
    state = addRoundKey(state, expandedKey + 160);


    PrintMatrix(state,"The final cipher text is");
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
