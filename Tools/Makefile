CPPFLAGS = -std=c++98 -pedantic -Wall

TOOLS_SOURCES = String.cpp Array.cpp Console.cpp Point.cpp Timer.cpp Debug.cpp Ptr.cpp
TOOLS_OBJECTS = $(TOOLS_SOURCES:%.cpp=%.o)

all: tools

tools: $(TOOLS_OBJECTS)

%.o: %.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

clean:
	rm -rf *.o
