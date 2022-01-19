NAME = cub3D
CC = gcc
LIB = libmlx.dylib
CFLAGS = -Wall -Wextra -Werror
SRCS =  mandatory/background.c \
        mandatory/bitmap.c \
        mandatory/check.c \
        mandatory/colors.c \
        mandatory/engine.c \
        mandatory/error.c \
        mandatory/gnl.c \
        mandatory/mappa_utils.c \
        mandatory/mappa.c \
        mandatory/math.c \
        mandatory/parsing.c \
        mandatory/rays.c \
        mandatory/sprites.c \
        mandatory/support_engine.c \
        mandatory/texture.c \
        mandatory/utils_sprite.c \
        mandatory/utils.c \
        mandatory/vediamo.c

SRCS_BONUS =    bonus/background_bonus.c \
                bonus/bitmap_bonus.c \
                bonus/check_bonus.c \
                bonus/colors_bonus.c \
                bonus/engine_bonus.c \
                bonus/error_bonus.c \
                bonus/face_bonus.c \
                bonus/gnl_bonus.c \
                bonus/init_monster_bonus.c \
                bonus/macchine_bonus.c \
                bonus/mappa_bonus.c \
                bonus/mappa_utils_bonus.c \
                bonus/math_bonus.c \
                bonus/monster_bonus.c \
                bonus/parsing_bonus.c \
                bonus/rays_bonus.c \
                bonus/snacks_bonus.c \
                bonus/sprites_bonus.c \
                bonus/support_engine_bonus.c \
                bonus/texture_bonus.c \
                bonus/utils_bonus.c \
                bonus/utils_sprite_bonus.c \
                bonus/vediamo_bonus.c

OBJS =  $(SRCS:.c=.o)
BOBJS = $(SRCS_BONUS:.c=.o)
$(%.o):$(%.c)
	@ $(CC) $(CFLAGS) -Imlx -o $@ -c $@
$(NAME): $(OBJS)
	@ make -s -C mlx
	@ mv mlx/${LIB} .
	@ $(CC) -lmlx  ${LIB} -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)	
bonus: $(BOBJS)
	@ make -s -C mlx
	@ mv mlx/${LIB} .
	@ $(CC) -lmlx  ${LIB} -framework OpenGL -framework AppKit $(BOBJS) -o $(NAME)
all: $(NAME) 
clean:
	@ rm -f ${OBJS} 
	@ rm -f ${BOBJS}
	@ make clean -C mlx 
fclean: clean
	@ rm -f ${LIB}
	@ rm -f $(NAME) 
	@ rm -f $(NAME_BONUS)
re:	fclean all bonus
.PHONY: all bonus clean fclean re
