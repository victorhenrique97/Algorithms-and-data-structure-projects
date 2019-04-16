all:
	gcc -o t2 src/*.c -I include/ -g -Wall
run:
	./t2
debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./t2
