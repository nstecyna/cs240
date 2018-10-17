#
# Specifiy the target
all:	LLC

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
LLC:	LLC.o
	g++  LLC.o -o LLC

# Specify how the object files should be created from source files
LLC.o:	LLC.cpp LLC.h
	g++ -c LLC.cpp -o LLC.o

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o LLC
