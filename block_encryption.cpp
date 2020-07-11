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

    uint8_t key[NumberofBlocks*NumberofBlocks] = {
        0x2b, 0x28, 0xab, 0x09,
        0x7e, 0xae, 0xf7, 0xcf,
        0x15, 0xd2, 0x15, 0x4f,
        0x16, 0xa6, 0x88, 0x3c
    };

    Mat block(NumberofBlocks,NumberofBlocks,CV_8UC1);

    for (int i=0; i<NumberofBlocks; i++){
        for (int j=0; j<NumberofBlocks; j++){
            block.at<uint8_t>(i,j) = data[i][j];
        }
    } 

    // passsing the key to be expanded by 176 bytes for all rounds
    keyExpansion(key); 

    Mat afterSubByte = subByte(block);

    cout<<"Orignal Data"<<endl;
    for (int i=0; i<NumberofBlocks; i++){
        for (int j=0; j<NumberofBlocks; j++){
            cout<<std::hex<<(int)block.at<uint8_t>(i,j)<<' ';
        }
        cout<<endl;
    } 
    
    cout<<"After Sub Bytes operation"<<endl;
    for (int i=0; i<NumberofBlocks; i++){
        for (int j=0; j<NumberofBlocks; j++){
            cout<<std::hex<<(int)afterSubByte.at<uint8_t>(i,j)<<' ';
        }
        cout<<endl;
    }   

    Mat afterShiftRows = shiftRows(afterSubByte);

    cout<<"After Shift Rows operation"<<endl;
    for (int i=0; i<NumberofBlocks; i++){
        for (int j=0; j<NumberofBlocks; j++){
            cout<<std::hex<<(int)afterShiftRows.at<uint8_t>(i,j)<<' ';
        }
        cout<<endl;
    }

    Mat afterMixColumns = mixColumns(afterShiftRows);

    cout<<"After Mix Columns operation"<<endl;
    for (int i=0; i<NumberofBlocks; i++){
        for (int j=0; j<NumberofBlocks; j++){
            cout<<std::hex<<(int)afterMixColumns.at<uint8_t>(i,j)<<' ';
        }
        cout<<endl;
    }


}