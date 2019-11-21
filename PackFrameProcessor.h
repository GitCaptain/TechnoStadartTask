#ifndef TECHNOSTANDART_PACKFRAMEPROCESSOR_H
#define TECHNOSTANDART_PACKFRAMEPROCESSOR_H

#include <string>
#include <vector>
#include "PackFrame.h"

class PackFrameProcessor {

    std::vector<char> bytes;
    PackFrame packFrame;

public:

    void printReceivedInfo();

    void readByte(char byte);

    void createPackFrame();

    bool isPackFrameCorrect();

    void processPackFrame();

};


#endif //TECHNOSTANDART_PACKFRAMEPROCESSOR_H
