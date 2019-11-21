#include "PackFrameProcessor.h"
#include <iostream>

bool PackFrameProcessor::isPackFrameCorrect() {

    char crc = 0;

    for(int i = 0; i < packFrame.len-1; ++i){
        crc += packFrame.data[i];
    }

    std::cout << "Полученное crc: " << (int)packFrame.data[packFrame.len-1] << std::endl
              << "Посчитанное crc: " << (int)crc << std::endl;

    return crc == packFrame.data[packFrame.len-1];

}

void PackFrameProcessor::readByte(char byte) {
    bytes.push_back(byte);
}

void PackFrameProcessor::createPackFrame(){

    if(bytes.size() < 4 || bytes.size() != 4 + bytes[3]) { // пришла неправильная последовательность байт, создаем неправильную структуру
        packFrame.len = 2;
        packFrame.data[0] = 0;
        packFrame.data[1] = 1;
    }

    packFrame.HEAD1 = bytes[0];
    packFrame.HEAD2 = bytes[1];
    packFrame.num = bytes[2];
    packFrame.len = bytes[3];
    for(int i = 0; i < packFrame.len; ++i)
        packFrame.data[i] = bytes[i+4];

}

void PackFrameProcessor::processPackFrame() {

    createPackFrame();

    printReceivedInfo();

    if(isPackFrameCorrect()){
        std::cout << "correct\n";
    }
    else{
        std::cout << "incorrect\n";
    }
}


void PackFrameProcessor::printReceivedInfo() {

    std::cout << "received:\n"
              << "HEAD1 = " << (int)packFrame.HEAD1 << std::endl
              << "HEAD2 = " << (int)packFrame.HEAD2 << std::endl
              << "num = " << (int)packFrame.num << std::endl
              << "len = " << (int)packFrame.len << std::endl
              << "data:\n";

    for(int i = 0; i < packFrame.len; ++i)
        std::cout << (int)packFrame.data[i] << " ";

    std::cout << std::endl;
}