CC = g++
CPPFLAGS = -std=c++14 -pedantic -Wall

EXENAME = prog
OUTDIR = bin

MAIN = main.cpp
SOURCES	= foo.cpp bar.cpp

OBJECTS = $(SOURCES:%.cpp=$(OUTDIR)/%.o)
EXE = $(OUTDIR)/$(EXENAME)

all: $(EXE)

$(EXE): $(OBJECTS) $(MAIN)
	$(CC) $(CPPFLAGS) -o $@ $^

$(OUTDIR)/%.o: %.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECTS) $(EXE)
