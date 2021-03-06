#include <stdio.h>
#include "instructions.h"
#include "memory.h"
#include "byte.h"
#include "funct.h"

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

void cmp_m(byte* mem1, byte* mem2)      {
                                            *FLAGS&=0xf8;
                                            if(*mem1>*mem2) *FLAGS|=0x04;
                                            else if(*mem1<*mem2) *FLAGS|=0x01;
                                            else *FLAGS|=0x02;
                                        }

void cmp_l(byte* mem1, byte literal)    {
                                            *FLAGS&=0xf8;
                                            if(*mem1>literal) *FLAGS|=0x04;
                                            else if(*mem1<literal) *FLAGS|=0x01;
                                            else *FLAGS|=0x02;
                                        }

void jmp(byte flag, byte cs_add)        {
                                            byte x=(*FLAGS&flag);
                                            if(x!=0) IP = CS+cs_add;
                                            else IP+=3;
                                        }

void read (byte* mem1)                  {*mem1=(byte)getch(); printf("%c",*mem1);}
void write(byte* mem1)                  {printf("%c",*mem1);}

void push(byte* mem1)                   {
                                            if ( SP==(SS+255) )
                                                printf("Stack Overflow\n");
                                            else
                                                *(++SP) = *mem1;
                                        }

void pop (byte* mem1)                   {
                                            if ( SP==(SS-1) )
                                                printf("Stack Underflow\n");
                                            else
                                                *mem1 = *(SP--);
                                        }