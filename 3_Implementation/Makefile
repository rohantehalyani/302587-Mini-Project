#Target_name : Dependencies
#<TAB>Command

# Name of the Project
PROJECT_NAME = NumberConversion

# Output directory
BUILD = build

CC = gcc

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
	RM = rm -rf
	FixPath = $(subst /,\,$1)
	EXEC = exe
else
	ifeq ($(shell uname), Linux)
		RM = del /q
		FixPath = $1
		EXEC = out
	endif
endif

# All source code files
SRC = main.c\
src/convert.c\
src/hexatodecimal.c\

# All test source files
TEST_SRC = src/convert.c\
src/hexatodecimal.c\
test/test_main.c\
unity/unity.c

TEST_OUTPUT = $(BULID)/Test_$(PROJECT_NAME).$(EXEC)

# All include folders with header files
INC = inc\
-Iunity\

INCLUDE_LIBS = -lcunit

CFLAGS = -I$(INC)

# Project Output name
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).$(EXEC)

# Default target build
$(PROJECT_NAME):all

# Run the target even if the matching name exists
.PHONY: run clean test all

all: $(SRC) $(BUILD)
	gcc $(SRC) -I$(INC) -o $(PROJECT_OUTPUT)

run: $(PROJECT_NAME)
	./$(PROJECT_OUTPUT)

test: $(TEST_SRC)
	gcc $(TEST_SRC) -I$(INC) -o $(call FixPath,$(BUILD)/Test_$(PROJECT_NAME).$(EXEC))
	./$(call FixPath,$(BUILD)/Test_$(PROJECT_NAME).$(EXEC))

clean:
	rm -rf $(BUILD)

$(BUILD):
	mkdir build



