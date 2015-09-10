CC = cc

main.a:
	$(CC) -o main.a -Iinclude/ main.c src/*.c

.PHONY: test
test: 
	$(CC) -o test_runner.a -Iinclude/ src/*.c test/main_test.c -lcheck
	./test_runner.a

.PHONY: clean
clean: 
	rm -f *.a *.o
