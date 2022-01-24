# ===============================
#		Configurations
# ===============================
# Name of the project
PROJ_NAME=main

# Top project Name
MAIN_SOURCE_NAME=main

# C++ source extension
CPP_SOURCE=cpp
CPP_HEADER=h

# ===============================
#		MakeFile structure
# ===============================

# .c files
C_SOURCE=$(wildcard *.$(CPP_SOURCE))

# .h files
H_SOURCE=$(wildcard *.$(CPP_HEADER))

# Object files
OBJ=$(C_SOURCE:.$(CPP_SOURCE)=.o)

# Compiler
CC=g++

# Flags for compiler
# Some notes:
# -c: instructs GCC not to link the final executable
# -Wall: enable all warnings
# -std=c++14: informs that the compiler should use this c++ standard
CC_FLAGS=-c -Wall -std=c++14 \

#
# Compilation and linking
#
all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^

%.o: %.$(CPP_SOURCE) %.$(CPP_HEADER)
	$(CC) -o $@ $< $(CC_FLAGS)

$(MAIN_SOURCE_NAME).o: $(MAIN_SOURCE_NAME).$(CPP_SOURCE) $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	rm -rf *.o $(PROJ_NAME) *~

