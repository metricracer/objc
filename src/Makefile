#http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
EXECUTABLE=Vector
SOURCES=BseObjct.c VecObjct.c PntObjct.c Vector.c
OBJECTS=$(SOURCES:.c=.o)

HEADERS=BseObjct.h VecObjct.h PntObjct.h ObjctDef.h
HEADERPATH=../include
INCPATH=-I$(HEADERPATH)
#LIBPATH=-L../lib
LIBPATH=
#LIBS=-lm -lsmrdate
LIBS=
CC=gcc
CFLAGS=-c -Wall
DEPS = $(patsubst %,$(HEADERPATH)/%,$(HEADERS))
OBJS = $(patsubst %, %,$(OBJECTS))
LDFLAGS=

.PHONY: default all clean apply

default: $(EXECUTABLE)
all: default

%.o: %.c $(DEPS)
	$(CC) $(INCPATH) $(CFLAGS) -c $< -o $@
	#$(OBJECTS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LIBPATH) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@
	#$(EXECUTABLE)

clean:
	-rm -f *.o
	-rm -f $(EXECUTABLE)

apply:
	cp $(EXECUTABLE) ../..
