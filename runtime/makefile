TARGET = avm

CC        =     gcc
LD        =     gcc

INCLUDES  =     include
OBJ       =     .obj
SRC       =     src

HEADERS   =     $(INCLUDES)/*.h
SOURCE    =     $(SRC)/*.c
OBJECT    =     $(OBJ)/execute.o \
                $(OBJ)/instructions.o \
                $(OBJ)/main.o \
                $(OBJ)/memory.o \
                $(OBJ)/funct.o

CFLAGS    =     -c -I$(INCLUDES) -fPIC -O3

CP        =     cp
RM        =     rm
RMFLAGS   =     -f
MKDIR     =     mkdir
DIREXISTS =     test -d

HOMEBIN   =     ~/bin

GIT       =     git
PULL      =     pull
REMOTE    =     origin
BRANCH    =     master
MAKE      =     make


$(TARGET): $(OBJECT)
	$(LD) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $< 

install: $(TARGET)
	@$(DIREXISTS) $(HOMEBIN) || $(MKDIR) $(HOMEBIN)
	$(CP) $(TARGET) $(HOMEBIN)/$(TARGET)

uninstall:
	$(RM) $(RMFLAGS) $(HOMEBIN)/$(TARGET)

update:
	$(GIT) $(PULL) $(REMOTE) $(BRANCH)
	$(MAKE) install 
