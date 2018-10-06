#
# Specifiy the target
all:	StecynaNicholas-nstecyn1-Hello

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
StecynaNicholas-nstecyn1-Hello:	StecynaNicholas-nstecyn1-Hello.o Hello_Class.o
	g++  StecynaNicholas-nstecyn1-Hello.o  Hello_Class.o  -o StecynaNicholas-nstecyn1-Hello.exe

# Specify how the object files should be created from source files
StecynaNicholas-nstecyn1-Hello.o:	StecynaNicholas-nstecyn1-Hello.cpp Hello_Class.h
	g++ -c StecynaNicholas-nstecyn1-Hello.cpp -o StecynaNicholas-nstecyn1-Hello.o

Hello_Class.o:	Hello_Class.cpp Hello_Class.h
	g++ -c Hello_Class.cpp -o Hello_Class.o

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o StecynaNicholas-nstecyn1-Hello.exe
