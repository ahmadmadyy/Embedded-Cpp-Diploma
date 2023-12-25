C = gcc
CC = g++
OBJS = Date.o testDate.o 
SRC = $(OBJS, .o=.c)

testDate: $(OBJS) 
	$(CC) -o testDate Date.o testDate.o 
	
# Define a pattern rule that compiles every .c file into a .o file
%.o: %.c
	$(CC) -c $@ $<

.PHONY: cleanall cleanobj 

cleanall : cleanobj 
	cmd //C del	*.exe

cleanobj :
	cmd //C del	*.o

# make -f makefile2.mk

