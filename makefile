as5: list.o
	gcc list.o -o as5
list.o: list.c
	gcc -c list.c 
clean: 
	rm -rf *.o *.out *.exe