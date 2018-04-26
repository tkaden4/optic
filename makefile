all: test.out

test.out: test/main.c
	gcc -o $@ $^ -Iinclude/

run:
	./test.out

clean:
	rm test.out
