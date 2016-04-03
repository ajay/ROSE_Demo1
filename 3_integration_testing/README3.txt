ROSE Implementation: Server Testing

README: Rose to Database communication

The database used to allow ROSE to communicate with the web app 
is MongoDB. As such, the MongoDB C++ Legacy driver will need to be installed 
before attempting to execute this code. General instructions for installing
the driver can be found at https://github.com/mongodb/mongo-cxx-driver/wiki/Quickstart-Guide-(New-Driver).
However, before installing this driver, the driver for C and libbson will need to be installed
first, which is also explained within the link above.

Once the driver has been installed, the code for the database communication can be 
compiled using the following command in the terminal:

c++ --std=c++11 *code_to_run*.cpp -o *executable_name* $(pkg-config --cflags --libs libmongocxx)

NOTE: parts encapsulated by astriks "*" are the parts of the command that depend on the particular
script that you want to run.