#include <stdlib.h>
#include "memory.h"
#include "byte.h"


byte* CS=NULL;
byte* DS=NULL;
byte* SS=NULL;

byte* FLAGS=NULL;

byte* IP=NULL;
byte* SP=NULL;


void init_memory()
{    
    CS=calloc(256,1);
    DS=calloc(256,1);
    SS=calloc(256,1);
    
    FLAGS=calloc(1,1);
    *FLAGS=255;
    
    IP=CS;
    SP=SS-1;
}
