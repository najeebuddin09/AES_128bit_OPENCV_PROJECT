g++ ^
                -g ^
                ./fileDecECB.cpp ./printFunctions.cpp ./keyExpansion.cpp ./inverseSubByte.cpp ./inverseShiftRows.cpp ./inverseMixColumns.cpp ./addRoundKey.cpp ./block_decryption.cpp ./AES_Decoder.cpp ^
                -o ^
                output_decrypt.exe ^
                -I D:\OpenCV-MinGW-Build-OpenCV-4.1.1-x64\include ^
                -L D:\OpenCV-MinGW-Build-OpenCV-4.1.1-x64\x64\mingw\bin ^
                -llibopencv_calib3d411 ^
                -llibopencv_core411 ^
                -llibopencv_imgcodecs411 ^
                -llibopencv_imgproc411 
.\output_decrypt.exe