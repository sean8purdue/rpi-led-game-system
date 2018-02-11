# Game Pad Test

## compile

`gcc gamepad_example.c ./gamepadHandler.c ./gamepadEventHandler.c -o gamepad -I../headers/ -lpthread -lrt`

or  

`gcc print.c ./gamepadHandler.c ./gamepadEventHandler.c -o gamepad -I../headers/ -lpthread -lrt`

or 

`make`

## Run

`sudo ./build/gamepad`