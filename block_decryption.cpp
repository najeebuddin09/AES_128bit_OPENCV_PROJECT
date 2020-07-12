/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/

// This file will contain the whole algorithm and steps for decryption of ciphered data

#include "AES.hpp"

void PrintMatrix(Mat, const char *);
void PrintArray(uint8_t *, const char *);
void PrintExpandedKey(uint8_t *, const char *);
void dataCopytoMatrix(Mat, uint8_t array[4][4]);

void block_decryption() 
{
    // ciphered practice data 
    uint8_t cipherData[NumberofBlocks][NumberofBlocks] = 
    {
        0x39, 0x02, 0xdc, 0x19,
        0x25, 0xdc, 0x11, 0x6a,
        0x84, 0x09, 0x85, 0x0b,
        0x1d, 0xfb, 0x97, 0x32
    };

    // 16 bytes of key or 128 bits of key
    uint8_t key[NumberofBlocks][NumberofBlocks] = 
    {
        0x2b, 0x28, 0xab, 0x09,
        0x7e, 0xae, 0xf7, 0xcf,
        0x15, 0xd2, 0x15, 0x4f,
        0x16, 0xa6, 0x88, 0x3c
    };

    // creating 2 open CV matrix of 4x4 size
    Mat cipherBlock(NumberofBlocks, NumberofBlocks, CV_8UC1);
    Mat keyBlock(NumberofBlocks, NumberofBlocks, CV_8UC1);

    // copying the data from 2d arrays to matrix
    dataCopytoMatrix(cipherBlock, cipherData);
    dataCopytoMatrix(keyBlock, key);

    // expanded key concept is just like explained in encryption
    // we will need 176 bytes of expanded key 
    uint8_t expandedKey[NumberofBlocks * NumberofBlocks * (NumberofRounds + 1)];

    //PrintMatrix(keyBlock,"The orignal key is");
    //PrintExpandedKey(expandedKey, "The expanded key is");

    // passsing the key to be expanded by 176 bytes for all rounds and storing in expandedKey array
    // keyExpansion method wiil return a expanded key for all rounds consisting of 176 bytes
    keyExpansion(keyBlock, expandedKey);

    // for here we will decypt the ciphered data back to orignal data
    // for decryption the expanded key will start from last
    Mat state = addRoundKey(cipherBlock,expandedKey+160);
    PrintMatrix(state,"after Initial Round");

    for (int i=NumberofRounds-1;i>=1;i--)
    {
        state = inverseSubByte(state);
        //PrintMatrix(state,"After Inverse Sub Byte");
        state = inverseShiftRows(state);
        //PrintMatrix(state,"After Inverse Shift Rows");
        state = addRoundKey(state,expandedKey + i * 16);
        //PrintMatrix(state,"After add round key");
        state = inverseMixColumns(state);
        //PrintMatrix(state,"After Inverse Mix Columns");
    }  

    state = inverseSubByte(state);
    state = inverseShiftRows(state);
    state = addRoundKey(state,expandedKey);

    PrintMatrix(state,"The orignal text is");

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
