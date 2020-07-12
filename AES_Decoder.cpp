/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/
#include "AES.hpp"

int main(int argc, char ** argv)
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


    Mat decrypted_data = block_decryption(cipherBlock,keyBlock);

    PrintMatrix(decrypted_data,"The decrypted value is");

    return 0;
}