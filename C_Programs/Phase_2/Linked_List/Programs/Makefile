CC = gcc
CFLAGS = -Wall
INCLUDES = -I/List.h -I../inlcude
SRCS = delete_end.c delete_position.c display.c domain_valid.c insert_begin.c  \
	   insert_position.c option_valid.c delete_id.c delete_start.c DOB_valid.c \
	   input.c insert_end.c integer_valid.c List.c name_valid.c print_reverse.c
TARG = Linked_List
all : $(TARG)
$(TARG) : List.h $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARG) $(SRCS)
exe : all List.h
	./$(TARG)
clean :
	$(RM) $(TARG)
depend : $(SRCS)
	makedepend $(INCLUDES) $^
