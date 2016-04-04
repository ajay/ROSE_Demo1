ROSE

The ROSE project requires the following to run:

Linux --> Ubuntu 15.10
Python 2.7 (apt-get -- should already have with ubuntu)
Festival (apt-get)
SDL & SDL2 (apt-get)
SDL_TTF (apt-get)
Armadillo (apt-get)
MongoDB (apt-get)

OpenCV 3.0 (from SOURCE - NOT from apt-get) get it from itseez on github
OpenCV_contrib (from SOURCE - install with opencv) again from itseez
Chilitags (from SOURCE)
Arduino (1.6.7 or later) (from SOURCE - NOT from apt-get)
Adafruit motorshieldv2 libraries for arduino
MongoDB C / C++ Driver

Specifically for Computer Vision:
Numpy
Matplotlib
Scipy
Webcam
Python3
urllib.request

After all dependencies are satisfied, the robot application can be run by running the makefile in the robot folder, and then running the executable:

make
./rose