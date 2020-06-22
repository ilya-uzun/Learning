CC := g++
JOB = job
PREFIX := obj/
SRC := main.cpp Event.h structs.h myUtilities.h constants.h Data.h Data.cpp \
DataGenerator.h DataGenerator.cpp Dialog.h Dialog.cpp HashTable.h HashTable.cpp Manager.h Manager.cpp
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
