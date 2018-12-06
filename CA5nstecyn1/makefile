#
# Specifiy the target
all:	FDS

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
FDS:	Flight.o City.o Main.o
	g++ -g -Wall -Wextra -pedantic Flight.o City.o Main.o -o FDS

# Specify how the object files should be created from source files

City.o:		City.cpp City.h
	g++ -g -c City.cpp -o City.o

Flight.o:	Flight.cpp Flight.h
	g++ -g -c Flight.cpp -o Flight.o

Main.o:	Main.cpp City.h
	g++ -g -c Main.cpp -o Main.o

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o FDS
