---------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------
ROSE Unit testing: Server testing

README: MongoDB installation

The database used to allow ROSE to communicate with the web app
is MongoDB. Installation for MongoDB on Ubuntu can be found at
https://docs.mongodb.org/manual/tutorial/install-mongodb-on-ubuntu/

README: Rose to Database communication

The MongoDB C++ Legacy driver will need to be installed
before attempting to execute this code. General instructions for installing
the driver can be found at https://github.com/mongodb/mongo-cxx-driver/wiki/Quickstart-Guide-(New-Driver).
However, before installing this driver, the driver for C and libbson will need to be installed
first, which is also explained within the link above.

Once the driver has been installed, the code for the database communication can be
compiled using the following command in the terminal:

c++ --std=c++11 *code_to_run*.cpp -o *executable_name* $(pkg-config --cflags --libs libmongocxx)

README: Web app to database communication

the webapp runs using Python 2.7, and as such, you will need to install both Python 2.7
and PyMongo. PyMongo can be installed from https://docs.mongodb.org/getting-started/python/client/.
once Python and PyMongo has been installed, the Python code can be ran using the following in the terminal:

python *code_to_run*.py

NOTE: parts encapsulated by astriks "*" are the parts of the command that depend on the particular
script that you want to run.

---------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------
Computer Vision Tests: Please refer to read me in CV folder.

Text to Speech:
Install Python3
Install pyttsx
Run the following command in terminal: python3 tts.py

---------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------
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

After all dependencies are satisfied, the robot application can be run by running the makefile in the robot folder, and then running the executable:

make
./rose

The particle filter, although not completely integrated yet, can be run by running the makfile in the particle/particle_current folder, and then running the executable:

make
./sim

The arm test application can be run by going into the robot/arm directory and running the makefile, and then running the executable:
make
./arm
