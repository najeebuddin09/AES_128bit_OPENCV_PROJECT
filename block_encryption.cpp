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

    Mat afterAddRoundKey = addRoundKey(afterMixColumns,expandedKey);

    cout<<"After Add Round Key operation"<<endl;
    for (int i=0; i<NumberofBlocks; i++){
        for (int j=0; j<NumberofBlocks; j++){
            cout<<std::hex<<(int)afterAddRoundKey.at<uint8_t>(i,j)<<' ';
        }
        cout<<endl;
    }

}