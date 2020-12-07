CC=gcc
args=-c -g -std=c11 -Wall

target : main.o linked_list.o
	$(CC) -o a.exe $^

main.o : main.c
	$(CC) $(args) $^

linked_list.o : linked_list.c linked_list.h
	$(CC) $(args) $<

.PHONY : clean
clean:
	@-rm *.o