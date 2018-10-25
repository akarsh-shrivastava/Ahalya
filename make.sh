cd /home/akarsh/zzz/JCVM
gcc ./src/instructions.c -c -o ./lib/instructions.o -Iinclude
gcc ./src/print_bin.c -c -o ./lib/print_bin.o -Iinclude
gcc ./src/memory.c -c -o ./lib/memory.o -Iinclude
gcc ./src/execute.c -c -o ./lib/execute.o -Iinclude
gcc ./src/main.c -c -o ./lib/main.o -Iinclude


gcc ./lib/instructions.o ./lib/print_bin.o ./lib/memory.o ./lib/main.o ./lib/execute.o -o vm