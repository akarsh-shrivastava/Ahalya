#ifndef MEMORY_H_DEFINED
    #define MEMORY_H_DEFINED
    #include "byte.h"

    extern byte* CS;
    extern byte* DS;
    extern byte* SS;

    extern byte* IP;
    extern byte* SP;
    extern byte* FLAGS;         /*{
                                        bit 0                                                       ; left most
                                        bit 1
                                        bit 2
                                        bit 3
                                        bit 4
                                        bit 5, 6 & 7 - cmp flag: 100- reg1>, 010- equal, 001- reg2> ; 7- right most
                                  }*/
    void init_memory();
#endif
