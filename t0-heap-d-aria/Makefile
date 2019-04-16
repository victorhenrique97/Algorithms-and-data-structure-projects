all:
	gcc -o heap src/*.c -I include/ -g -Wall

example:
	./heap 3 1000 0 1000000

run:
	./heap

debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./heap 3 1000 0 1000000
