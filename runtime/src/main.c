#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"
#include "byte.h"
#include "funct.h"
#include "instructions.h"
#include "execute.h"


void main(int n,char** args)
{
    char filename[5][50]={0};
    char options [5][50]={0};

    int file_count=0, option_count=0;
    for (int i=1; i<n; i++)
    {
        if (args[i][0]=='-')
        {
            if (args[i][1]=='-')
                strcpy(options[option_count++], args[i]);
        }
        else
            strcpy(filename[file_count++],args[i]);
    }

    FILE *f;
    f = fopen(args[1],"r");
    if(f)
    {
        byte ch;
        init_memory();

        printf("%p\n", CS);
        printf("%p\n", DS);
        printf("%p\n", IP);
        printf("DS:%d\tDS+1:%d\tDS+2:%d\tDS+3:%d\n", *DS, *(DS+1), *(DS+2), *(DS+3) );
        printf("%x\n", *FLAGS);
        printf("copying\n");

        while(1)
        {
            ch=(byte)fgetc(f);
            if(ch==255)
                break;
            (*IP)=ch;
            IP++;
            if(IP==DS)
            {
                printf("Code too big. Exiting\n");
                exit(0);
            }
            printf("%p  %d  %d\n",IP , *(IP-1), ch );
        }
        *IP=255;
        printf("%p  %d  %d\n",IP , *(IP), ch );
        IP=CS;
        printf("%p\nexecuting\n",IP);
        byte status=execute(options[0]);
        printf("%s","\n");
        if(status==1)
            printf("File format not supported\n");
        fclose(f);
    }
    else
        printf("File not found\n");
}
