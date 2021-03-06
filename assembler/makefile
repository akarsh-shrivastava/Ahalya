TARGET = lasm

CX        =     g++
LD        =     g++

INCLUDES  =     include
OBJ       =     .obj
SRC       =     src

HEADERS   =     $(INCLUDES)/*.h
SOURCE    =     $(SRC)/*.cpp
OBJECT    =     $(OBJ)/structs.o \
                $(OBJ)/preprocessor.o \
                $(OBJ)/tokenizer.o \
                $(OBJ)/analyzer.o \
                $(OBJ)/translator.o \
                $(OBJ)/dectobin.o \
                $(OBJ)/main.o

CXFLAGS   =     -c -I$(INCLUDES) -fPIC -std=c++17 -O3

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

$(OBJ)/%.o: $(SRC)/%.cpp $(HEADERS)
	$(CX) $(CXFLAGS) -o $@ $< 

install: $(TARGET)
	@$(DIREXISTS) $(HOMEBIN) || $(MKDIR) $(HOMEBIN)
	$(CP) $(TARGET) $(HOMEBIN)/$(TARGET)

uninstall:
	$(RM) $(RMFLAGS) $(HOMEBIN)/$(TARGET)

update:
	$(GIT) $(PULL) $(REMOTE) $(BRANCH)
	$(MAKE) install 
