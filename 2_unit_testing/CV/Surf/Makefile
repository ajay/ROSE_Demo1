CXX = g++
CFLAGS = -std=c++11 -O3 `pkg-config --cflags opencv`
VISUAL = $(shell pwd)/..
INCLUDE = -I/usr/local/include -I$(VISUAL)
LIBS = -L/usr/local/lib \
       -lopencv_core \
			 -lopencv_highgui \
			 -lopencv_imgproc \
			 -lopencv_features2d \
			 -lopencv_xfeatures2d \
			 -lopencv_flann \
			 -lopencv_imgcodecs \
			 -lopencv_videoio
OBJS =

all: matchingtest $(OBJS) 

matchingtest: $(OBJS) matchingtest.o
	$(CXX) $(CFLAGS) -o $@ $^ $(INCLUDE) $(LIBS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -o $@ -c $< $(INCLUDE)

clean:
	rm -f *.o matchingtest
