CC := g++
JOB = job
PREFIX := obj/
SRC := main.cpp overload.cpp
OBJ := $(patsubst %.cpp, $(PREFIX)%.o, $(SRC))

$(JOB): $(OBJ)
	$(CC) -o $@ $^

$(PREFIX)%.o: %.cpp
	$(CC) -c -o $@ $^

debug: $(JOB)
	gdb -x gdb.config $(JOB)

clean:
	rm -rf *.exe $(PREFIX)*.o
