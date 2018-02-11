SOURCEDIR=./src
INCLUDEDIR=./headers
BUILDDIR=./build

CC=gcc
CFLAGS=-std=11 -0s

CXX==g++
CXXFLAGS=-std=14 -0s

LIBS=-I$(INCLUDEDIR) -lpthread -lrt

OBJ=$(BUILDDIR)/print.o $(BUILDDIR)/gamepadHandler.o $(BUILDDIR)/gamepadEventHandler.o

all: dir gamepad

gamepad: $(OBJ)
	$(CC) -o $(BUILDDIR)/$@ $^ $(LIBS)

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	$(CC) -c -o $@ $<

dir:
	mkdir -p $(BUILDDIR)

clean:
	rm -rfv $(BUILDDIR) 
