#include "instructions.h"
#include "memory.h"
#include "byte.h"

void mov_m(byte* mem1, byte* mem2)      {*mem1=*mem2;}
void mov_l(byte* mem1, byte literal)    {*mem1=literal;}

void add_m(byte* mem1, byte* mem2)      {*mem1+=*mem2;}
void add_l(byte* mem1, byte literal)    {*mem1+=literal;}
void sub_m(byte* mem1, byte* mem2)      {*mem1-=*mem2;}
void sub_l(byte* mem1, byte literal)    {*mem1-=literal;}
void mul_m(byte* mem1, byte* mem2)      {*mem1*=*mem2;}
void mul_l(byte* mem1, byte literal)    {*mem1*=literal;}
void div_m(byte* mem1, byte* mem2)      {*mem1/=*mem2;}
void div_l(byte* mem1, byte literal)    {*mem1/=literal;}
void mod_m(byte* mem1, byte* mem2)      {*mem1%=*mem2;}
void mod_l(byte* mem1, byte literal)    {*mem1%=literal;}

void and_m(byte* mem1, byte* mem2)      {*mem1&=*mem2;}
void and_l(byte* mem1, byte literal)    {*mem1&=literal;}
void or_m(byte* mem1, byte* mem2)       {*mem1|=*mem2;}
void or_l(byte* mem1, byte literal)     {*mem1|=literal;}
void not_m(byte* mem1)                  {*mem1=~(*mem1);}
void neg_m(byte* mem1)                  {*mem1=-(*mem1);}
void xor_m(byte* mem1, byte* mem2)      {*mem1^=*mem2;}
void xor_l(byte* mem1, byte literal)    {*mem1^=literal;}

void cmp_m(byte* reg1, byte* reg2)      {
                                            *FLAGS&=0xf8;
                                            if(*reg1>*reg2) *FLAGS|=0x04;
                                            else if(*reg1<*reg2) *FLAGS|=0x01;
                                            else *FLAGS|=0x02;
                                        }

void cmp_l(byte* reg1, byte literal)    {
                                            *FLAGS&=0xf8;
                                            if(*reg1>literal) *FLAGS|=0x04;
                                            else if(*reg1<literal) *FLAGS|=0x01;
                                            else *FLAGS|=0x02;
                                        }

void jmp(byte flag, byte es_add)        {
                                            byte x=(*FLAGS&flag);
                                            if(x!=0 || flag==252 ) IP = CS+*(ES+es_add);            //252 = always true
                                            else IP+=3;
                                        }

void def(byte es_add,byte cs_add)       {
                                            *(ES+es_add)=cs_add;
                                        }