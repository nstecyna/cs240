#
# Specifiy the target
all:	LLC

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
LLC:	LLC.h PlayingCard.o Player.o Game.o Main.o
	g++ -g -Wall -Wextra -pedantic PlayingCard.o Player.o Game.o Main.o -o war.exe

# Specify how the object files should be created from source files
#LLC.o:	LLC.cpp LLC.h
#	g++ -c LLC.cpp -o LLC.o

PlayingCard.o:	PlayingCard.cpp PlayingCard.h
	g++ -g -c PlayingCard.cpp -o PlayingCard.o

Player.o:	Player.cpp Player.h
	g++ -g -c Player.cpp -o Player.o

Game.o:	Game.cpp Game.h
	g++ -g -c Game.cpp -o Game.o

Main.o:	Main.cpp LLC.h
	g++ -g -c Main.cpp -o Main.o

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o war.exe
