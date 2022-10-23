NAME = checker push_swap
PS_NAME = push_swap
C_NAME = checker

C_SRCS = checker.c stack.c int_array.c instructions.c reader.c utility.c exec_instr.c
PS_SRCS = stack.c int_array.c instructions.c select_sort.c radix_sort.c simple_sort.c extras.c ps_main.c utility.c output.c init.c
SOURCES += $(PS_SRCS) $(C_SRCS)

CC = gcc

OBJECTS = $(subst .c,.o,$(SOURCES))

FLAGS = -Wall -Wextra -Werror
LINKS = -I libft/includes -L libft -lft

$(NAME): $(OBJECTS) 
	make -C libft
	$(CC) $(C_SRCS) -o $(C_NAME) $(FLAGS) $(LINKS)
	$(CC) $(PS_SRCS) -o $(PS_NAME) $(FLAGS) $(LINKS)

all: $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJECTS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
