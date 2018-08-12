CC = gcc
SRCS = del.c display.c Hash.c insert.c search.c
CFLAGS = -Wall -o
TARG = Hash
all : Hash.h
	$(CC) $(CFLAGS) $(TARG) $(SRCS)
exe : Hash.h
	./$(TARG)
clean :
	$(RM) *.o .*.swp .*.swo .*.swn .*.swm
