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
        0x00, 0x01, 0x02, 0x03,
        0x04, 0x05, 0x06, 0x07, 
        0x08, 0x09, 0x0a, 0x0b, 
        0x0c, 0x0d, 0x0e, 0x0f,
    };

    Mat block(NumberofBlocks,NumberofBlocks,CV_8UC1);

    for (int i=0; i<NumberofBlocks; i++){
        for (int j=0; j<NumberofBlocks; j++){
            block.at<uint8_t>(i,j) = data[i][j];
        }
    } 

    // here we declare a pointer expandedKey which will contain the expanded key of 176 bytes 
    uint8_t expandedKey[NumberofBlocks * NumberofBlocks * (NumberofRounds + 1)];
    // passsing the key to be expanded by 176 bytes for all rounds and storing in expandedKey algorithm
    keyExpansion(key , expandedKey);

    cout<<"Orignal Key"<<endl;
    for(int i=0;i<16;i++)
    {
        cout<<std::hex<<(int)key[i]<<" ";
    }

    cout<<endl<<"Expanded Key"<<endl;
    for(int i=0;i<176;i++)
    {
        cout<<std::hex<<(int)expandedKey[i]<<", ";
        if(i % 16 == 0 && i != 0)
        {
            cout<<endl;
        }
    }
    
    
    Mat afterSubByte = subByte(block);

    cout<<endl<<"Orignal Data"<<endl;
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