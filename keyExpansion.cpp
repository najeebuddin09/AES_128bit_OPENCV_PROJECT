/* 
    AES 128 Bit Project 
    implementation by Abdullah1428
    CS Project
*/

#include "AES.hpp"

void keyExpansion (uint8_t key[16]) {

    // used for key expansion 
    // we have 10 rounds plus one initial so 11 total
    // for 11 rounds 128 bits or 16 bytes keys have to be generated so total 176 bytes needed

    uint8_t expandedKeys[NumberofBlocks * NumberofBlocks * (NumberofRounds + 1) ]; //(4*4 *(11)) = 176

    uint8_t lastFourBytes[4];


    // now the first 16 bytes in the expanded key will be orignal key so copy the orignal key to expanded key
    for (int i=0;i<NumberofBlocks*NumberofBlocks;i++) 
    {
        expandedKeys[i] = key[i];
    }

    // now 16 bytes are already filled so we will start from 17 byte

    int doneBytes = 16;
    int numberofBytes = 176;
    while (doneBytes < numberofBytes )
    {

        /*
            for key generation few steps are required
            1) pick last 4 bytes and give a left rotation to the bytes
            2) now for the rotated bytes find SBOX values from the lookup table for SBOX
            3) now pick first 4 bytes from the key, then pick first column from RCON table 
            4) now XOR the first 4 bytes, RCON column value and the SBOX value column
            5) result generated from these 4 bytes will be the first column of the new 4 bytes for round 1 key
            6) now for rest 3 bytes of the round 1 key 
                for 2 byte => take the new column generated in round 1 key and 2 column from first 16 bytes and XOR it
                for 3 byte => take the 2 column generated in round 1 key and 3 column from first 16 bytes and XOR it
                for 4 byte => take the 3 column generated in round 1 key and 4 column from first 16 bytes and XOR it

            and tadahhhh!! key generated
            could it be any easier??

            repeat these steps to generate keys for all rounds so a total 176 bytes of expanded key will be generated
            which will be then added with each round in the addRoundKey step of encyption  

        */

       // picking last 4 bytes
       for (int x=0;x<4;x++)
       {
           lastFourBytes[x] = expandedKeys[x + doneBytes - 4]; 
       }

       
       // we know that this step has to be only repeated at the start of new round key
       // so we can generate a condition here that only repeat these steps when we are the start of new
       // round key generation

       if (doneBytes % 16 == 0) 
       {
           // now for rotation we will define a separate function
           rotateLastFourBytes(lastFourBytes);
           // now finding SBOX values 
           

       } 



    }

}

// method for roatation of the last four bytes picked
void rotateLastFourBytes (uint8_t *bytes)
{
    uint8_t temp = bytes[0];
    bytes[0] = bytes[1];
    bytes[1] = bytes[2];
    bytes[2] = bytes[3];
    bytes[3] = temp;
}













