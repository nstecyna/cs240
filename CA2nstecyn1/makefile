#
# Specifiy the target
all:	Voter

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Voter:	Voter.o VoterDB.o CA2nstecyn1.o
	g++  Voter.o VoterDB.o CA2nstecyn1.o -o Voter.exe

# Specify how the object files should be created from source files
Voter.o:	Voter.cpp Voter.h
	g++ -c Voter.cpp -o Voter.o

VoterDB.o: VoterDB.cpp VoterDB.h Voter.h
	g++ -c VoterDB.cpp -o VoterDB.o

CA2nstecyn1.o: CA2nstecyn1.cpp VoterDB.h Voter.h
	g++ -c CA2nstecyn1.cpp -o CA2nstecyn1.o

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Voter.exe
