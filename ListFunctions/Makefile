
CC = gcc
CFLAGS = -Wvla --std=c99
LDFLAGS =
RM = /bin/rm


run : start
	./start

start : start.o act8.o
	$(CC) $(CFLAGS) start.o act8.o -o start

start.o : start.c act8.h
	$(CC) $(CFLAGS) -c start.c

act8.o : act8.c act8.h
	$(CC) $(CFLAGS) -c act8.c

.PHONY : clean cleanall

clean :
	-$(RM) *.o

cleanall : clean
	-$(RM) start
