NAME = push_swap

NAME_BONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC_D = ./src

SRC_LIBFT_D = ./libft

OBJ_D = ./obj

SRC =	parsing.c push_swap.c stack_manupl.c\
		operations/push_from_to.c operations/shift_down.c operations/swap_up.c\
		operations/shift_up.c index_stack.c sort_small_num.c sort_big_num.c\

SRC_LIBFT = ft_atoi.c ft_isdigit.c ft_split.c ft_strlen.c ft_strdup.c ft_strcmp.c\
			ft_strchr.c ft_strlcpy.c\

SRC_BONUS = bonus_src/checker.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			src/parsing.c src/operations/push_from_to.c src/operations/shift_down.c\
			src/operations/swap_up.c src/operations/shift_up.c\
			index_stack.c stack_manupl.c\


OBJ = $(addprefix $(OBJ_D)/, $(SRC:.c=.o))

OBJ_LIBFT = $(addprefix $(OBJ_D)/, $(SRC_LIBFT:.c=.o))

OBJ_BONUS = $(addprefix $(OBJ_D)/, $(SRC_BONUS:.c=.o))

all: $(NAME)

$(NAME) : $(OBJ) $(OBJ_LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_LIBFT) -o $@

$(OBJ_D)/%.o : $(SRC_D)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_D)/%.o : $(SRC_LIBFT_D)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_D)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS) $(OBJ_LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(OBJ_LIBFT) -o $@

clean:
	@-rm -rf $(OBJ_D) 
fclean: clean
	@-rm -rf $(NAME) $(NAME_BONUS)
re: fclean all
