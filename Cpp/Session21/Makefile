CC = g++ # Toolchain name
projectname = test
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

# make -f makefile.mk

all: $(projectname)
	@echo "Make Done!"

%.o : %.cpp
	$(CC) -c $<

$(projectname) : $(OBJ)
	$(CC) -o $(projectname) $(OBJ)

cleanall : cleanobj 
	del	*.exe

cleanobj :
	del	*.o