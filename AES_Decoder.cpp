/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/
#include "AES.hpp"

void data_decryption(uint8_t [],Mat ,uint8_t []);

int main(int argc, char ** argv)
{

    stringstream cipherString;
    string cipherData;
	ifstream cipherfile;
	cipherfile.open("EncodedFile.txt", ios::in | ios::binary);
    if (cipherfile.is_open()) 
    {
        cipherString << cipherfile.rdbuf();
        cipherfile.close();
    }

    // displaying data stored in array
    cipherData = cipherString.str();

    // counting all characters in the file
    int x = 0;
    while(cipherData[x] != '\0')
    {
        x++;
    }

    // declaring array for the data
    uint8_t cipheredData[x];
    
    for (int i=0;i<sizeof(cipheredData);i++)
    {
        cipheredData[i] = cipherData[i];
    }

    unsigned int cipherLength = strlen((const char *) cipheredData);
    //cipherLength = cipherLength - 1;

    uint8_t decryptedData[cipherLength];

    /* 
        // printing the hex of data 
        // da for new line
    
    for(int i=0;i<sizeof(cipheredData);i++)
    {
        cout<<std::hex<<(int)cipheredData[i];
    }

    */
    
     // declaring our key
    // 16 bytes of key or 128 bits of key
    uint8_t key[NumberofBlocks][NumberofBlocks] = 
    {
        0x2b, 0x28, 0xab, 0x09,
        0x7e, 0xae, 0xf7, 0xcf,
        0x15, 0xd2, 0x15, 0x4f,
        0x16, 0xa6, 0x88, 0x3c
    };

    Mat keyBlock(NumberofBlocks, NumberofBlocks, CV_8UC1);
    dataCopytoMatrix(keyBlock,key);

    // now calling the decryption function to decrypt our ciphered data
    for(int i=0;i<cipherLength;i+=NumberofBytes)
    {
        data_decryption(cipheredData + i , keyBlock , decryptedData + i);
    }

    //PrintArrayWithRange(decryptedData,"The orignal data is : ",cipherLength);

    ofstream outfile;
	outfile.open("DecodedFile.txt", ios::out | ios::binary);
	if (outfile.is_open())
	{
		outfile.write((char *)decryptedData,cipherLength);
		outfile.close();
		cout << endl << "Wrote decrypted message to file" << endl;
	}
	else
    {
        cout << "Unable to open file";
    }


    return 0;
}

void data_decryption(uint8_t data[],Mat key,uint8_t plain[])
{
    // declaring 2d array to store 16 bytes of ciphered data recieved to be decrypted
    uint8_t cipherText[NumberofBlocks][NumberofBlocks];

    int index = 0;
    for (int row=0;row<NumberofBlocks;row++)
    {
        for(int col=0;col<NumberofBlocks;col++)
        {
            cipherText[row][col] = data[index];
            index++;
        }
    }

    // declaring Mat to copy the 16 bytes of data
    Mat cipherBlock(NumberofBlocks, NumberofBlocks, CV_8UC1);
    
    // copying data
    dataCopytoMatrix(cipherBlock,cipherText);

    // encrypting data
    Mat decrypted_data = block_decryption(cipherBlock,key);
    PrintMatrix(decrypted_data,"The orignal text is : ");

    int ind = 0;
    for (int row=0;row<NumberofBlocks;row++)
    {
        for(int col=0;col<NumberofBlocks;col++)
        {
            plain[ind] = decrypted_data.at<uint8_t>(row,col);
            ind++;
        }
    }   
}


/*

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
*/