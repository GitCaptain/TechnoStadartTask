#include <string>
#include "ByteGenerator.h"
#include "PackFrameProcessor.h"

int main() {

    ByteGenerator byteGenerator;
    PackFrameProcessor packFrameProcessor;

    while(!byteGenerator.isGenerationProcessOver()){
        packFrameProcessor.readByte(byteGenerator.getByte());
    }

    packFrameProcessor.processPackFrame();

    return 0;

}