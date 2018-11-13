#
# Specifiy the target
all:	FDS

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
FDS:	Flight.o Main.o
	g++ -g -Wall -Wextra -pedantic Flight.o Main.o -o FDS

# Specify how the object files should be created from source files

Flight.o:	Flight.cpp Flight.h
	g++ -c Flight.cpp -o Flight.o

Main.o:	Main.cpp Flight.h
	g++ -c Main.cpp -o Main.o

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o FDS
