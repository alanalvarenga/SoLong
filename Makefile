NAME = solong.a 
NAME_BONUS = solong_bonus.a
LIBFT_PATH = ./Libft
LIBFTPRINTF_PATH = ./FT_PRINTF
LIBMLX_PATH = ./LibMLX
INCLUDE = solong.h
#INCLUDE_BONUS = ft_printf_bonus.h
LIBFT = $(LIBFT_PATH)/libft.a
LIBFTPRINTF = $(LIBFTPRINTF_PATH)/libftprintf.a
LIBMLX = $(LIBMLX_PATH)/libmlx_Linux.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
PATH_SRC = ./
FILES = $(PATH_SRC)solong.c $(PATH_SRC)map_utils.c $(PATH_SRC)map_utils2.c \
		$(PATH_SRC)render_window.c $(PATH_SRC)sprites.c $(PATH_SRC)movement.c \
		$(PATH_SRC)GNL/get_next_line.c $(PATH_SRC)GNL/get_next_line_utils.c
OBJECTS = $(FILES:.c=.o)
LINKS = -L. -lXext -L. -lX11
VAL = valgrind --leak-check=full --show-leak-kinds=all
#FILES_BONUS = 
#OBJECTS_BONUS = $(FILES_BONUS:.c=.o)
RM = rm -f

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJECTS)
		 make -C $(LIBFTPRINTF_PATH)
		 cp $(LIBFTPRINTF) $(NAME)
#		 mv $(LIBFTPRINTF) $(NAME)
		 make -C $(LIBMLX_PATH)
#		 cp $(LIBMLX) $(NAME)
#		 mv $(LIBMLX) $(NAME)
		 ar -rcs $(NAME) $(LIBMLX) $(OBJECTS) $(INCLUDE)

$(PATH_SRC)%.o: $(PATH_SRC)%.c $(INCLUDE)
		@ $(CC) $(CFLAGS) -c $< -o $@

#$(NAME_BONUS): $(OBJECTS_BONUS) 
#		@ make -C $(LIBFT_PATH)
#		@ cp $(LIBFT) $(NAME_BONUS)
#		@ mv $(LIBFT) $(NAME_BONUS)
#		@ ar -rcs $(NAME_BONUS) $(OBJECTS_BONUS) $(INCLUDE_BONUS)
#		@ cp $(NAME_BONUS) $(NAME)

#$(PATH_SRC_BONUS)%.o: $(PATH_SRC_BONUS)%.c $(INCLUDE_BONUS)
#		@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_PATH)	
	make clean -C $(LIBFTPRINTF_PATH)
	make clean -C $(LIBMLX_PATH)
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(LIBFTPRINTF_PATH) 
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

test: 
	$(CC) $(CFLAGS) $(LINKS) $(FILES) $(NAME) $(LIBMLX)
testeprint:
	./a.out map.ber

testb:
	gcc main2.c -g $(CFLAGS) $(NAME_BONUS) && ./a.out

.PHONY: all clean fclean re

