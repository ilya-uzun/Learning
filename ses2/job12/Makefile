CC := g++
JOB = job
PREFIX := obj/
# SRC := main_task1.cpp
# SRC := main_task2.cpp Time.cpp Time.h
SRC := main_task3.cpp Time.cpp Time.h Container.h Container.cpp
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
