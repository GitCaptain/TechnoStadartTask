#include <string>
#include "ByteGenerator.h"
#include "PackFrameProcessor.h"

int main(int argc, char** argv) {

    std::string path = "bytes";

    if(argc == 2)
        path = argv[1];

    ByteGenerator byteGenerator;
    PackFrameProcessor packFrameProcessor;

    while(!byteGenerator.isGenerationProcessOver()){
        packFrameProcessor.readByte(byteGenerator.getByte());
    }

    packFrameProcessor.processPackFrame();

    return 0;

}