#Target_name : Dependencies
#<TAB>Command

# Name of the Project
PROJT_NAME = NumberConversion
TEST_PROJT_NAME = Test_$(PROJT_NAME)

# Output directory
BUILD = build

CC = gcc

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
	MOVE = move
	RM = del /q
	FixPath = $(subst /,\,$1)
	EXEC = exe
else
	ifeq ($(shell uname), Linux)
		MOVE = mv
		RM = rm -rf
		FixPath = $1
		EXEC = out
	endif
endif

# Main file name
MAIN_NAME = main.c


# All source code files
SRC =inc/header.h\
src/convert.c\
src/hexatodecimal.c

# All test source files
TEST_SRC = test/test_main.c\
unity/unity.c\

#TEST_OUTPUT = $(BULID)/Test_$(PROJECT_NAME).$(EXEC)

# All include folders with header files
INC = -Iinc\
-Iunity\

$(PROJT_NAME): all

CFLAGS = -I$(INC)

# Project Output name
#PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).$(EXEC)
# Default target build
#$(PROJECT_NAME):all

# Run the target even if the matching name exists
.PHONY: all test coverage run clean doc

all: $(SRC) $(BUILD)
	gcc $(MAIN_NAME) $(SRC) $(INC) -o $(call FixPath,$(BUILD)/$(PROJT_NAME).$(EXEC)) -lm


run: $(PROJECT_NAME)
	$(call FixPath,$(BUILD)/$(PROJT_NAME).$(EXEC))
	
test: $(SRC) $(TEST_SRC) $(BUILD)
	gcc $(SRC) $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD)/$(TEST_PROJT_NAME).$(EXEC)) -lm
	$(call FixPath,$(BUILD)/$(TEST_PROJT_NAME).$(EXEC))

coverage:${PROJECT_NAME} $(BUILD)
	gcc -fprofile-arcs -ftest-coverage $(SRC) $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD)/$(TEST_PROJT_NAME).$(EXEC))
	$(call FixPath,$(BUILD)/$(TEST_PROJT_NAME).$(EXEC))
	$(MOVE) *.gcno src
	$(MOVE) *.gcda src
	gcov -a $(SRC)
	$(RM) $(call FixPath,*.gcda)
	$(RM) $(call FixPath,*.gcno)

doc:
	make -C documentation

cppcheck:
	cppcheck --enable=all $(CPPCHECK_INC) *.c

clean:
	$(RM) $(call FixPath,$(BUILD)/*)
	make clean -C doc
	rmdir $(BUILD) doc/html

$(BUILD):
	mkdir build

valgrind_main: all
	valgrind $(call FixPath,$(BUILD)/$(PROJT_NAME).$(EXEC))

valgrind_test: $(SRC) $(TEST_SRC) $(BUILD)
	gcc $(SRC) $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD)/$(TEST_PROJT_NAME).$(EXEC))
	valgrind $(call FixPath,$(BUILD)/$(TEST_PROJT_NAME).$(EXEC))


