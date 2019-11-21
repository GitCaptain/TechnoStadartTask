#ifndef TECHNOSTANDART_BYTEGENERATOR_H
#define TECHNOSTANDART_BYTEGENERATOR_H


#include <string>
#include <vector>

class ByteGenerator {

    int need_to_generate;
    int current_index_to_generate;
    bool generation_process_over;
    char generated_crc;

public:

    ByteGenerator();

    bool isGenerationProcessOver();

    char getByte();

    char generateByte(char mn = -128, char mx = 127);
};


#endif //TECHNOSTANDART_BYTEGENERATOR_H
