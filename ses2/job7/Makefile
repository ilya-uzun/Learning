CC := g++
JOB = job
PREFIX := obj/
# SRCDIR   = include
# BINDIR   = source
INCLUDES := include/
SOURCES := source/
# SOU := $(SOURCE)*.cpp
# INC := include $(INCLUDES)*.h
SRC := $(SOURCES)*.cpp $(INCLUDES)*.h
OBJ := $(patsubst %.cpp, $(PREFIX)%.o, $(SRC))

$(JOB): $(OBJ)
	$(CC) -o $@ $^

$(PREFIX)%.o: %.cpp
	$(CC) -c -o $@ $^

debug: $(JOB)
	gdb -x gdb.config $(JOB)

cod:  $(SRC)
	mintty emacs $(SRC)

clean:
	rm -rf *.exe $(PREFIX)*.o
