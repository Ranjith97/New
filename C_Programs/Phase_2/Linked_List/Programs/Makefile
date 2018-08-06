CC = gcc
CFLAGS = -Wall -o
SRCS = delete_end.c delete_position.c display.c domain_valid.c insert_begin.c  \
	   insert_position.c option_valid.c delete_id.c delete_start.c DOB_valid.c \
	   input.c insert_end.c integer_valid.c List.c name_valid.c print_reverse.c
TARG = Linked_List
all : $(TARG)
$(TARG) :
	$(CC) $(CFLAGS) $(TARG) $(SRCS)
exe : $(TARG)
	./$(TARG)
clean :
	$(RM) $(TARG)
