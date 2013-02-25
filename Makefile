CFLAGS=-g -Wall -pthread

clean:
	find  -type f -executable -exec rm -f {} +
	find  -type f -name '*.o' -exec rm -f {} +
