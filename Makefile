all:
	gcc ring.c enqueuer.c -o enqueuer

clean:
	rm -rf *.o enqueuer