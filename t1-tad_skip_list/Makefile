all:
	gcc -o trab src/* -I./include -g -Wall

run:
	./trab <filename >Outputs/filename

debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./trab <filename >Outputs/filename
