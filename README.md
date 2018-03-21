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

### gamepad functions integrated
To Run the `gamepad_example.c`

`gcc gamepad_example.c ./gamepadHandler.c ./gamepadEventHandler.c -o gamepad_example -I../headers/ -lpthread -lrt`

### run hzeller’s LED sample on Pi

* Disable sounds  
`sudo rmmod snd_bcm2835`

If this doesn’t work, please try:  
`sudo vim boot/config.txt`

Change from  `dtparam=audio=on` to  `dtparam=audio=off`.

* run demo on adafruit 32*32 led matrix  
`sudo ./demo --led-gpio-mapping=adafruit-hat -D 1 runtext.ppm`

* Image Viewer in ‘Utilities’  
To compile, you need  install the GraphicsMagick dependencies first:

```bash
sudo apt-get update
sudo apt-get install libgraphicsmagick++-dev libwebp-dev -y
make led-image-viewer
```

Then, you can run it with any common image format, including animated gifs:  

```bash
sudo ./led-image-viewer --led-gpio-mapping=adafruit-hat some-image.jpg       # Display an image.
sudo ./led-image-viewer --led-gpio-mapping=adafruit-hat animated.gif         # Show an animated gif
sudo ./led-image-viewer --led-gpio-mapping=adafruit-hat -t5 animated.gif     # Show an animated gif for 5 seconds
sudo ./led-image-viewer --led-gpio-mapping=adafruit-hat -l2 animated.gif     # Show an animated gif for 2 loops
sudo ./led-image-viewer --led-gpio-mapping=adafruit-hat -D16 animated.gif    # Play animated gif, use 16ms frame delay
```

test2
