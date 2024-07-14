CFLAGS = cc -Wall -Wextra -Werror -g3 -o
NAME = push_swap

SRC = 	./srcs/instruction/push_instrucion.c \
		./srcs/instruction/rev_rot_instruction.c \
		./srcs/instruction/rot_instruction.c \
		./srcs/instruction/swap_instruction.c \
		./srcs/parcing_args.c\
		./srcs/exec.c\
		./srcs/setting.c\
		./srcs/sorting_utils.c\
		./srcs/main.c\
		./srcs/push_swap_utils.c\
		./srcs/utils.c\
		./srcs/sorting.c\


all: $(NAME)
$(NAME): $(SRC)
	@$(MAKE) -sC Libft
	$(CFLAGS) $(NAME) $(SRC) -L Libft/ -lft

clean:
	@$(MAKE) clean -C Libft

fclean: fclean
	rm -f ./srcs/instruction/*.o
	rm -f ./srcs/*.o
	rm -f $(NAME)
	@$(MAKE) fclean -C Libft

re: fclean all