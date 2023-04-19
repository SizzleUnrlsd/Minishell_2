##
## EPITECH PROJECT, 2023
## B-PSU-100-RUN-1-1-bsnavy-hugo.payet
## File description:
## Makefile
##

SRC	=	$(wildcard lib/*.c)

SRC_BASIC_FUNCTION =  $(wildcard lib/basic_function/*.c)

SRC_BUILTIN = $(wildcard lib/builtin/*.c)

SRC_BUILTIN_SETENV = $(wildcard lib/builtin/builtin_set_unset_env/*.c)

SRC_BUILTIN_CD = $(wildcard lib/builtin/cd/*.c)

SRC_BUILTIN_EXIT = $(wildcard lib/builtin/exit/*.c)

SRC_PROMPT_FUNCTION = $(wildcard lib/prompt_function/*.c)

SRC_STRUCT_FUNCTION = $(wildcard lib/struct_function/*.c)

SRC_REDIRECTION = $(wildcard lib/redirection/*.c)

SRC_AST = $(wildcard lib/ast/*.c)

BONUS = $(wildcard bonus/*.c)

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

FLAGS 	=	-W -Wall -Wextra -Werror -g3 -Wpadded -pedantic

MEMORY_FLAG	=	-Wpadded

TEST_BIN =	unit_tests

TEST_SRC =	$(wildcard tests/*.c)

all	:	$(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(SRC) $(SRC_BASIC_FUNCTION) $(SRC_BUILTIN) \
	$(SRC_BUILTIN_SETENV) $(SRC_PROMPT_FUNCTION) $(SRC_STRUCT_FUNCTION) \
	$(SRC_BUILTIN_CD) $(SRC_BUILTIN_EXIT) $(SRC_REDIRECTION) $(SRC_AST) \
	$(BONUS)

bonus	:	$(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(SRC) $(SRC_BASIC_FUNCTION) $(SRC_BUILTIN) \
	$(SRC_BUILTIN_SETENV) $(SRC_PROMPT_FUNCTION) $(SRC_STRUCT_FUNCTION) \
	$(SRC_BUILTIN_CD) $(SRC_BUILTIN_EXIT) $(SRC_REDIRECTION) $(SRC_AST) \
	$(BONUS)

opt	:	$(OBJ)
	make all  $(MEMORY_FLAG)

clean	:
	rm -f $(OBJ)
	rm -f a.out
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.c~

fclean	: clean
	rm -f $(NAME)
	rm -f $(TEST_BIN)

re	: fclean all

$(TEST_BIN): all
	gcc -o $(TEST_BIN) $(FLAGS) $(SRC_00) $(TEST_SRC) --coverage -lcriterion

tests_run:	$(TEST_BIN)
	./$(TEST_BIN)

ban_function:
	nm ./$(NAME) | grep -e GLIBC

valgrind:
	valgrind ./$(NAME)
