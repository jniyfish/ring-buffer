all:
	gcc ring.c enqueuer.c  -lrt -o enqueuer
	gcc ring.c dequeuer.c  -lrt -o dequeuer

clean:
	rm -rf *.o enqueuer dequeuer