CC = gcc
CFLAGS = -Wall -o
SRCS = add_list.c del_list.c File_handling.c id_valid.c ip_valid.c port_valid.c\
	   read_list.c
TARG = File_handling
all : $(TARG)
$(TARG) : File_handling.h
	$(CC) $(CFLAGS) $(TARG) $(SRCS)
