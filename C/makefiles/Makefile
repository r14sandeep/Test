PROJECT := exe
OBJ:=main.o hello.o fact.o
all: $(PROJECT)
$(PROJECT): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $@
#%.o: %.cpp Makefile $(DEPS)
#	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm *.o $(PROJECT)
