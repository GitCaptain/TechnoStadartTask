#include "ByteGenerator.h"
#include <iostream>
#include <time.h>

ByteGenerator::ByteGenerator():
    generation_process_over(false),
    current_index_to_generate(0),
    need_to_generate(4),
    generated_crc(0)
{

    srand(time(NULL));
}

char ByteGenerator::getByte() {
    char byte;

    if(current_index_to_generate == 3) {
        byte = generateByte(1, 127);
        need_to_generate += byte;
    } else{
        byte = generateByte();
    }

    if(current_index_to_generate + 1 == need_to_generate) {
        byte = generated_crc - (rand()%2); //портим crc с вероятностью 0.5
    } else if(current_index_to_generate > 3){ // генерируем поле data
        generated_crc += byte;
    }

    std::cout << "generated: " << (int)byte << std::endl;

    if(current_index_to_generate + 1 == need_to_generate)
        generation_process_over = true;
    current_index_to_generate++;

    return byte;

}

char ByteGenerator::generateByte(char mn, char mx) {
    return (rand() % mx) + mn;
}

bool ByteGenerator::isGenerationProcessOver() {
    return generation_process_over;
}
