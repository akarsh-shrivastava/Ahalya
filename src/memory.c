#include <stdlib.h>
#include "memory.h"
#include "byte.h"

byte* MEM=NULL;

byte* CS=NULL;
byte* DS=NULL;
byte* SS=NULL;
byte* ES=NULL;

byte* FLAGS=NULL;

byte* IP=NULL;

byte* PORT1=NULL;
byte* PORT2=NULL;
byte* PORT3=NULL;

void init_memory()
{
	MEM=calloc(1024,1);
	
	CS=MEM;
	DS=MEM+256;
	SS=MEM+512;
	ES=MEM+768;
	
	FLAGS=calloc(1,1);
	
	IP=CS;
	
	PORT1=calloc(1,1);
	PORT2=calloc(1,1);
	PORT3=calloc(1,1);
}
