TARGET = vm

CC = gcc
LD = gcc

INCLUDES = include
LIBS     = lib
SOURCE   = src


HEADERS = $(INCLUDES)/*.h
OBJ     = $(LIBS)/*.o

CFLAGS = -c -I$(INCLUDES)

CP        = cp
RM        = rm
RMFLAGS   = -f
MKDIR     = mkdir
DIREXISTS = test -d

HOMEBIN   = ~/bin

$(TARGET): $(OBJ)
	$(LD) $^ -o $@

$(LIBS)/%.o: $(SOURCE)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $< 

install: $(TARGET)
	@$(DIREXISTS) $(HOMEBIN) || $(MKDIR) $(HOMEBIN)
	$(CP) $(TARGET) $(HOMEBIN)/$(TARGET)

uninstall:
	$(RM) $(RMFLAGS) $(HOMEBIN)/$(TARGET)
