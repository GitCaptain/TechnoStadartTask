
#ifndef TECHNOSTANDART_PACKFRAME_H
#define TECHNOSTANDART_PACKFRAME_H

struct PackFrame{
    char HEAD1 = 0x77;
    char HEAD2 = 0x66;
    char num = 0;
    char len = 0;
    char data[256];
};

#endif //TECHNOSTANDART_PACKFRAME_H
