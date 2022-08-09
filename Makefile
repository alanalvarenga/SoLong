NAME = solong.a 
NAME_BONUS = solong_bonus.a
LIBFT_PATH = ./Libft
LIBFTPRINTF_PATH = ./FT_PRINTF
LIBMLX_PATH = ./LibMLX
INCLUDE = solong.h
INCLUDE_BONUS = solong_bonus.h
LIBFT = $(LIBFT_PATH)/libft.a
LIBFTPRINTF = $(LIBFTPRINTF_PATH)/libftprintf.a
LIBMLX = $(LIBMLX_PATH)/libmlx_Linux.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
PATH_SRC = ./SRC/
PATH_SRC_BONUS = ./SRC_BONUS/
FILES = $(PATH_SRC)solong.c $(PATH_SRC)map_utils.c $(PATH_SRC)map_utils2.c $(PATH_SRC)close.c \
		$(PATH_SRC)render_window.c $(PATH_SRC)sprites.c $(PATH_SRC)movement.c $(PATH_SRC)animation_play.c \
		$(PATH_SRC)sprites_player.c \
		./GNL/get_next_line.c ./GNL/get_next_line_utils.c
OBJECTS = $(FILES:.c=.o)
LINKS = -L. -lXext -L. -lX11 -lmlx
FILES_BONUS = $(PATH_SRC_BONUS)solong_bonus.c $(PATH_SRC_BONUS)map_utils_bonus.c $(PATH_SRC_BONUS)map_utils2_bonus.c \
			  $(PATH_SRC_BONUS)close_bonus.c $(PATH_SRC_BONUS)render_window_bonus.c $(PATH_SRC_BONUS)sprites_bonus.c \
			  $(PATH_SRC_BONUS)movement_bonus.c $(PATH_SRC_BONUS)animation_play_bonus.c \
			  $(PATH_SRC_BONUS)sprites_player_bonus.c $(PATH_SRC_BONUS)movement_enemy_bonus.c \
			  ./GNL/get_next_line.c ./GNL/get_next_line_utils.c
OBJECTS_BONUS = $(FILES_BONUS:.c=.o)
RM = rm -f
VAL = valgrind --leak-check=full --show-leak-kinds=all --log-file=valgrind.txt

all: $(NAME) so_long

bonus: $(NAME_BONUS) so_long_bonus

$(NAME): $(OBJECTS)
		make -C $(LIBFTPRINTF_PATH)
		cp $(LIBFTPRINTF) $(NAME)
		make -C $(LIBMLX_PATH)
		ar -rcs $(NAME) $(LIBMLX) $(OBJECTS) $(INCLUDE)

$(PATH_SRC)%.o: $(PATH_SRC)%.c $(INCLUDE)
		@ $(CC) $(CFLAGS) -c $< -o $@ 

$(NAME_BONUS): $(OBJECTS_BONUS)
		make -C $(LIBFTPRINTF_PATH)
		cp $(LIBFTPRINTF) $(NAME_BONUS)
		make -C $(LIBMLX_PATH)
		ar -rcs $(NAME_BONUS) $(OBJECTS_BONUS) $(INCLUDE_BONUS)
		cp $(NAME_BONUS) $(NAME)

$(PATH_SRC_BONUS)%.o: $(PATH_SRC_BONUS)%.c $(INCLUDE_BONUS)
		@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(LIBFTPRINTF_PATH)
	make clean -C $(LIBMLX_PATH)
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(LIBFTPRINTF_PATH)
	$(RM) $(NAME) $(NAME_BONUS)
	$(RM) ./so_long ./so_long_bonus valgrind.txt

re: fclean all

so_long: $(NAME)
	$(CC) $(CFLAGS) $(LINKS) $(FILES) $(NAME) $(LIBMLX) -o so_long
testprint:
	./so_long ./maps/map.ber

so_long_bonus: $(NAME_BONUS)
	$(CC) $(CFLAGS) $(LINKS) $(FILES_BONUS) $(NAME_BONUS) $(LIBMLX) -o so_long_bonus

testprintb:
	./so_long_bonus ./maps/map_bonus.ber

.PHONY: all clean fclean re bonus

