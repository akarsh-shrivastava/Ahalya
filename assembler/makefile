TARGET = mas

#CC = gcc
#LD = gcc

CX  = g++

#INCLUDES = include
#LIBS     = lib
#SOURCE   = src


#HEADERS = $(INCLUDES)/*.h
#OBJ     = $(LIBS)/*.o

#CFLAGS = -c -I$(INCLUDES)

CP        = cp
RM        = rm
RMFLAGS   = -f
MKDIR     = mkdir
DIREXISTS = test -d

HOMEBIN   = ~/bin




$(TARGET): *.cpp
	$(CX) $^ -o $@ 

install: $(TARGET)
	@$(DIREXISTS) $(HOMEBIN) || $(MKDIR) $(HOMEBIN)
	$(CP) $(TARGET) $(HOMEBIN)/$(TARGET)

uninstall:
	$(RM) $(RMFLAGS) $(HOMEBIN)/$(TARGET)
