# RPI-RGB-LED-Matrix

## Setup

### Hardware
* Make sure you have pins 4 and 18 on the Adafruit LED Matrix Hat soldered together. Otherwise, the LED refresh has a lot of blinking.
* In Pi3 ModelB: If you have the sound module snd_bcm2835 loaded, unload it using `sudo rmmod snd_bcm2835`. That module and the LED library are not compatible.
* If you have more questions, please also refer to [hzeller/rpi-rgb-led-matrix](https://github.com/hzeller/rpi-rgb-led-matrix).

### Software
* Add the [rpi-rgb-led-matrix](https://github.com/hzeller/rpi-rgb-led-matrix) library from Github as a folder in the root directory of this project.
* Add a games folder with games in the root directory of this project.   
`touch games/test1`  
`touch games/test2`

## Compile and Run
* Compile the project using make in the root directory of this project.
* Run the ./build/gameSystem file, which starts the controllers and menu by running: 
`sudo ./build/gameSystem --led-gpio-mapping=adafruit-hat-pwm`.

## Others

To Run the `gamepad_example.c`

`gcc gamepad_example.c ./gamepadHandler.c ./gamepadEventHandler.c -o gamepad_example -I../headers/ -lpthread -lrt`