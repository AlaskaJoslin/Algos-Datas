CXX     = g++
STD     = c++14

OPTS    = -g -O3 -DBALT
CFLAGS  = $(OPTS)
LIBS    = -lm

HEADERS = sort_methods.h \
          utils.h

SRCS    = sort_methods.cpp \
          args_utils.cpp

OBJS    = $(SRCS:.cpp=.o)

TARGET  = sort

default: $(TARGET)

.C.o:
	$(CXX) $(CFLAGS) -c $<

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

sort_methods.o: sort_methods.cpp $(HEADERS)

clean:
	rm *.o
