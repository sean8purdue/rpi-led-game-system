LIBS=-I../headers/ -lpthread -lrt

all: gamepad

gamepad: print.o gamepadHandler.o gamepadEventHandler.o
	gcc -o gamepad print.o gamepadHandler.o gamepadEventHandler.o $(LIBS)

print.o: print.c
	gcc -c print.c

gamepadHandler.o: gamepadHandler.c ../headers/gamepadHandler.h
	gcc -c gamepadHandler.c ../headers/gamepadHandler.h

gamepadEventHandler.o: gamepadEventHandler.c ../headers/gamepadEventHandler.h
	gcc -c gamepadEventHandler.c ../headers/gamepadEventHandler.h

clean:
	rm -rf gamepad *.o
