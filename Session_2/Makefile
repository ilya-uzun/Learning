PREFIX := obj/
SRC := main.cpp fraction.cpp
OBJ := $(patsubst %.cpp, $(PREFIX)%.o, $(SRC))

work: $(OBJ)
	g++ -o $@ $^

$(PREFIX)%.o: %.cpp
	cc -c -o $@ $^

instal:
	./work.exe
