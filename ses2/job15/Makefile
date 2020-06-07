CC := g++
JOB = job
PREFIX := obj/
SRC := main.cpp Person.cpp Person.h Hash.h Hash.cpp GeneratorPerson.h GeneratorPerson.cpp Manager.h Manager.cpp
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
