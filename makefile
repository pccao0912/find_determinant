find_determinant.out: main.o matrix.o
	gcc -g -Wall -Werror -o find_determinant.out main.o matrix.o -lm

main.o: main.c matrix.h
	gcc -g -Wall -Werror -c main.c

matrix.o: matrix.c matrix.h
	gcc -g -Wall -Werror -c matrix.c

clean:
	rm -f *.o *.out