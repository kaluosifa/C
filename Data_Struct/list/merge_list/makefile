CC=gcc
args=-c -g -std=c11 -Wall
src=main.c Sequence_list.c

target : main.o Sequence_list.o
	$(CC) -o a.exe $^

main.o : main.c
	$(CC) $(args) $^

Sequence_list.o : Sequence_list.c Sequence_list.h
	$(CC) $(args) $<

.PHONY : clean
clean:
	@-rm *.o