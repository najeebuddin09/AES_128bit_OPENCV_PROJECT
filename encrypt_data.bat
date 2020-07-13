g++ ^
                -g ^
                ./fileEnc_ECB_CBC.cpp ./printFunctions.cpp ./keyExpansion.cpp ./subByte.cpp ./shiftRows.cpp ./mixColumns.cpp ./addRoundKey.cpp ./block_encryption.cpp ./AES_Encoder.cpp ^
                -o ^
                output_encrypt.exe ^
                -I D:\OpenCV-MinGW-Build-OpenCV-4.1.1-x64\include ^
                -L D:\OpenCV-MinGW-Build-OpenCV-4.1.1-x64\x64\mingw\bin ^
                -llibopencv_calib3d411 ^
                -llibopencv_core411 ^
                -llibopencv_imgcodecs411 ^
                -llibopencv_imgproc411 
.\output_encrypt.exe