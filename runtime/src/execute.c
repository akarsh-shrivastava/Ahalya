#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "instructions.h"
#include "execute.h"
#include "memory.h"
#include "byte.h"
#include "funct.h"


byte execute(char* options)
{
    IP=CS;

    if(*IP++!=253)
        return 1;
    if(*IP++!=254)
        return 1;
    while(*IP!=255)
    {
        if (!strcmp(options,"--de") || !strcmp(options,"--d") )
            printf("IP-%p:%d\n",IP,*IP);
        
        switch(*IP)
        {
            case 1 :mov_m ( (DS+*(IP+1)), (DS+*(IP+2)) ); IP+=3; break;
            case 2 :mov_l ( (DS+*(IP+1)), (   *(IP+2)) ); IP+=3; break;
            
            case 3 :add_m ( (DS+*(IP+1)), (DS+*(IP+2)) ); IP+=3; break;
            case 4 :add_l ( (DS+*(IP+1)), (   *(IP+2)) ); IP+=3; break;
            case 5 :sub_m ( (DS+*(IP+1)), (DS+*(IP+2)) ); IP+=3; break;
            case 6 :sub_l ( (DS+*(IP+1)), (   *(IP+2)) ); IP+=3; break;
            case 7 :mul_m ( (DS+*(IP+1)), (DS+*(IP+2)) ); IP+=3; break;
            case 8 :mul_l ( (DS+*(IP+1)), (   *(IP+2)) ); IP+=3; break;
            case 9 :div_m ( (DS+*(IP+1)), (DS+*(IP+2)) ); IP+=3; break;
            case 10:div_l ( (DS+*(IP+1)), (   *(IP+2)) ); IP+=3; break;
            case 11:mod_m ( (DS+*(IP+1)), (DS+*(IP+2)) ); IP+=3; break;
            case 12:mod_l ( (DS+*(IP+1)), (   *(IP+2)) ); IP+=3; break;
            
            case 13:and_m ( (DS+*(IP+1)), (DS+*(IP+2)) ); IP+=3; break;
            case 14:and_l ( (DS+*(IP+1)), (   *(IP+2)) ); IP+=3; break;
            case 15:or_m  ( (DS+*(IP+1)), (DS+*(IP+2)) ); IP+=3; break;
            case 16:or_l  ( (DS+*(IP+1)), (   *(IP+2)) ); IP+=3; break;
            case 17:not_m ( (DS+*(IP+1)) );               IP+=3; break;
            case 18:neg_m ( (DS+*(IP+1)) );               IP+=3; break;
            case 19:xor_m ( (DS+*(IP+1)), (DS+*(IP+2)) ); IP+=3; break;
            case 20:xor_l ( (DS+*(IP+1)), (   *(IP+2)) ); IP+=3; break;
            
            case 21:cmp_m ( (DS+*(IP+1)), (DS+*(IP+2)) ); IP+=3; break;
            case 22:cmp_l ( (DS+*(IP+1)), (   *(IP+2)) ); IP+=3; break;
            case 23:jmp   (     *(IP+1) , (   *(IP+2)) );        break;

            case 24:read  ( (DS+*(IP+1)) );               IP+=3; break;
            case 25:write ( (DS+*(IP+1)) );               IP+=3; break;

            case 26:push  ( (DS+*(IP+1)) );               IP+=3; break;
            case 27:pop   ( (DS+*(IP+1)) );               IP+=3; break;
            
            case 255:break;
        }

        if (!strcmp(options,"--de") || !strcmp(options,"--d") )
        {
            for (int i=0;i<36;i++)
            {
                printf("  DS+%2d:%3d  ", i,*(DS+i) );
                if (i%6==5)
                    printf("\n");
            }

            printf("%x\n\n", *FLAGS);
        }
        if (!strcmp(options,"--de"))
            getch();
    }

    return 0;
}
