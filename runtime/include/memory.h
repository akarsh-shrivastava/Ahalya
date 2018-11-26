#ifndef MEMORY_H_DEFINED
    #define MEMORY_H_DEFINED
    #include "byte.h"
    extern byte* CS;
    extern byte* DS;
    extern byte* SS;
    extern byte* ES;
    
    extern byte* IP;
    extern byte* FLAGS;         /*{
                                        bit 0                                                   ; left most (most significant)
                                        bit 1
                                        bit 2
                                        bit 3
                                        bit 4
                                        bit 5, 6 & 7 - cmp flag: 100- reg1>, 010- equal, 001- reg2> ; 7- right most (least significant)
                                  }*/
    extern byte* PORT1;
    extern byte* PORT2;
    extern byte* PORT3;
    void init_memory();
#endif
