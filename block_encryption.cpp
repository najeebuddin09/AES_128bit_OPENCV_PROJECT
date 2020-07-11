/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/

// This file will contain the whole algorithm and steps for encryption of data

#include "AES.hpp"

void block_encryption() {
    uint8_t data[NumberofBlocks][NumberofBlocks] = {
        0x19, 0xa0, 0x9a, 0xe9,
        0x3d, 0xf4, 0xc6, 0xf8,
        0xe3, 0xe2, 0x8d, 0x48,
        0xbe, 0x2b, 0x2a, 0x08
    };

    Mat block(NumberofBlocks,NumberofBlocks,CV_8UC1);

    for (int i=0; i<NumberofBlocks; i++){
        for (int j=0; j<NumberofBlocks; j++){
            block.at<uint8_t>(i,j) = data[i][j];
        }
    } 

    Mat afterSubByte = subByte(block);

    cout<<"Orignal Data"<<endl;
    for (int i=0; i<NumberofBlocks; i++){
        for (int j=0; j<NumberofBlocks; j++){
            cout<<std::hex<<(int)block.at<uint8_t>(i,j)<<' ';
        }
        cout<<endl;
    } 
    
    cout<<"After subBytes operation"<<endl;
    for (int i=0; i<NumberofBlocks; i++){
        for (int j=0; j<NumberofBlocks; j++){
            cout<<std::hex<<(int)afterSubByte.at<uint8_t>(i,j)<<' ';
        }
        cout<<endl;
    }   

    Mat afterShiftRows = shiftRows(afterSubByte);

    cout<<"After shiftRows operation"<<endl;
    for (int i=0; i<NumberofBlocks; i++){
        for (int j=0; j<NumberofBlocks; j++){
            cout<<std::hex<<(int)afterShiftRows.at<uint8_t>(i,j)<<' ';
        }
        cout<<endl;
    }

}