# Ahalya

### Installing
```bash
git clone https://github.com/akarsh-shrivastava/Ahalya.git
cd Ahalya/assembler
make install
cd ../runtime
make install
```

### Syntax
* all the data is one byte typeless and unsigned
* addresses are enclosed in brackets <br>
eg [231]
* Instructions with 2 arguments <br>
 mov, add, sub, mul, div, mod, and, or, xor, cmp <br>
syntax:
    ```assembly
    <instruction> <address1> <address2/constant>
    ```
* Instructions with 1 argument <br>
not, neg, read, write, push, pop <br>
syntax:
    ```assembly
    <instruction> <address>
    ```
* arithmetic and bitwise operations store the result in the first address <br>
hence the original value is lost
* cmp instruction compares 2 arguments and sets last 3 bits of flag accordingly <br>
1 if second argument is greater <br>
2 if both are equal <br>
4 if first argument is greater <br>

* read reads one byte to the address <br>
write prints one byte from the address as character

* push pushes value from address to stack <br>
  pop pops the top of stack to the address

* labels can be any non-reserve words <br>
syntax:
    ```assembly
    <label_name>:
    ...
    ```

* jmp instruction jumps to the lable depending on the condition <br>
syntax:
    ```assembly
    jmp <condition> <label_name>
    ```
    conditions are: <br>
    eq, neq, less, lesseq, grt, grteq, always
 <br>

### Running
Save the assembly code with .lsm extention <br>
To assemble:
```bash
lasm filename.lsm
```
filename.ahl will be created <br>
To run:
```bash
ahalya filename.ahl
```
To see status of memory after each instruction run with --debug-e option
