#ifndef INSTRUCTIONS_H_INCLUDED
    #define INSTRUCTIONS_H_INCLUDED
    #include "byte.h"

    void mov_m(byte* mem1, byte* mem2);             //1,0x01
    void mov_l(byte* mem1, byte literal);           //2,0x02

    void add_m(byte* mem1, byte* mem2);             //3,0x03
    void add_l(byte* mem1, byte literal);           //4,0x04
    void sub_m(byte* mem1, byte* mem2);             //5,0x05
    void sub_l(byte* mem1, byte literal);           //6,0x06
    void mul_m(byte* mem1, byte* mem2);             //7,0x07
    void mul_l(byte* mem1, byte literal);           //8,0x08
    void div_m(byte* mem1, byte* mem2);             //9,0x09
    void div_l(byte* mem1, byte literal);           //10,0x0a
    void mod_m(byte* mem1, byte* mem2);             //11,0x0b
    void mod_l(byte* mem1, byte literal);           //12,0x0c

    void and_m(byte* mem1, byte* mem2);             //13,0x0d
    void and_l(byte* mem1, byte literal);           //14,0x0e
    void or_m(byte* mem1, byte* mem2);              //15,0x0f
    void or_l(byte* mem1, byte literal);            //16,0x10
    void not_m(byte* mem1);                         //17,0x11
    void neg_m(byte* mem1);                         //18,0x12
    void xor_m(byte* mem1, byte* mem2);             //19,0x13
    void xor_l(byte* mem1, byte literal);           //20,0x14

    void cmp_m(byte* reg1, byte* reg2);             //21,0x15
    void cmp_l(byte* reg1, byte literal);           //22,0x16

    void jmp(byte flag, byte es_add);               //23,0x17
    void def(byte es_add,byte cs_add);              //24,0x18
#endif
