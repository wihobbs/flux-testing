make:
	gcc -Wall -Wextra -pedantic --std=c17 -g -o memory_lock memory_lock.c

.PHONY: clean

clean:
	rm -rf *.dSYM
	rm -f memory_lock
