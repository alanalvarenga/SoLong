NAME = libftprintf.a
NAME_BONUS = libftprintf_bonus.a
LIBFT_PATH = ../Libft
INCLUDE = ft_printf.h
INCLUDE_BONUS = ft_printf_bonus.h
LIBFT = $(LIBFT_PATH)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
PATH_SRC = ./SRC/
PATH_SRC_BONUS = ./SRC_BONUS/
FILES = $(PATH_SRC)ft_printf.c $(PATH_SRC)ft_printf_utils.c $(PATH_SRC)ft_printf_utils2.c
OBJECTS = $(FILES:.c=.o)
FILES_BONUS = $(PATH_SRC_BONUS)ft_printf_bonus.c $(PATH_SRC_BONUS)ft_printf_utils_bonus.c \
			  $(PATH_SRC_BONUS)ft_flags_bonus.c $(PATH_SRC_BONUS)flag_space_bonus.c \
			  $(PATH_SRC_BONUS)flag_negative_bonus.c $(PATH_SRC_BONUS)flag_zero_bonus.c \
			  $(PATH_SRC_BONUS)flags_count_digits_bonus.c $(PATH_SRC_BONUS)flag_sharp_bonus.c \
			  $(PATH_SRC_BONUS)flag_width_bonus.c $(PATH_SRC_BONUS)ft_print_utils2_bonus.c \
			  $(PATH_SRC_BONUS)flag_dot_bonus.c  $(PATH_SRC_BONUS)ft_print_utils3_bonus.c
OBJECTS_BONUS = $(FILES_BONUS:.c=.o)
RM = rm -f

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJECTS)
		@ make -C $(LIBFT_PATH)
		@ mv $(LIBFT) $(NAME)
		@ ar -rcs $(NAME) $(OBJECTS) $(INCLUDE)

$(PATH_SRC)%.o: $(PATH_SRC)%.c $(INCLUDE)
		@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS): $(OBJECTS_BONUS) 
		@ make -C $(LIBFT_PATH)
		@ mv $(LIBFT) $(NAME_BONUS)
		@ ar -rcs $(NAME_BONUS) $(OBJECTS_BONUS) $(INCLUDE_BONUS)
		@ cp $(NAME_BONUS) $(NAME)

$(PATH_SRC_BONUS)%.o: $(PATH_SRC_BONUS)%.c $(INCLUDE_BONUS)
		@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	make fclean -C $(LIBFT_PATH) 
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

testm: 
	$(CC) main.c $(NAME) && ./a.out

testb:
	gcc main2.c -g $(CFLAGS) $(NAME_BONUS) && ./a.out

.PHONY: all clean fclean re

