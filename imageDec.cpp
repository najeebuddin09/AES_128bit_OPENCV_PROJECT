/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/
// this file contains the image decryption 

#include "AES.hpp"

void decryptBlock(Mat ,Mat );

void imageDec ()
{
    // 16 bytes of key or 128 bits of key
    uint8_t key[NumberofBlocks][NumberofBlocks] = 
    {
        0x2b, 0x28, 0xab, 0x09,
        0x7e, 0xae, 0xf7, 0xcf,
        0x15, 0xd2, 0x15, 0x4f,
        0x16, 0xa6, 0x88, 0x3c
    };

    // copying our key to Mat
    Mat keyBlock(NumberofBlocks, NumberofBlocks, CV_8UC1);
    dataCopytoMatrix(keyBlock,key);


    // reading input image which must be name InputFile
    // our input image is 316 x 316

    Mat EncodedImage = imread("EncodedImage.jpg",IMREAD_GRAYSCALE);

    // calculating total pixels in the image
    int totalPixels = EncodedImage.rows * EncodedImage.cols;

    // now reading 4x4 blocs from the image 
    for (int row=0;row<EncodedImage.rows;row+=NumberofBlocks)
    {
        for (int col=0;col<EncodedImage.cols;col+=NumberofBlocks)
        {
            // selecting 4x4 block now
            Mat tile = EncodedImage(cv::Range(row,min(row+NumberofBlocks,EncodedImage.rows)),
                        cv::Range(col,min(col+NumberofBlocks,EncodedImage.cols)));
            
            decryptBlock(tile,keyBlock);
        }        
    }

    imwrite("DecodedImage.jpg",EncodedImage);

    imshow("DecryptedImage",EncodedImage);

    waitKey();
}

void decryptBlock(Mat data,Mat key)
{
    data = block_decryption(data,key);
}