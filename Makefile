# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 15:50:14 by yolee             #+#    #+#              #
#    Updated: 2022/10/26 20:36:46 by yolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFTFLAGS = -Llibft -lft
INCLUDE = -I ./include
SRCS_DIR = srcs
SRCS_FILE = minirt.c \
	ray_utils.c \
	camera_utils.c \
	ambient_light_utils.c \
	sphere_utils.c \
	plane_utils.c \
	light_utils.c \
	cylinder_utils.c \
	raytrace.c \
	vector_utils1.c \
	vector_utils2.c \
	parse.c \
	error_handling.c \
	get_next_line.c	\

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE))
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./mlx
	$(MAKE) bonus -C ./libft
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(MLXFLAGS) $(LIBFTFLAGS) -o $(NAME)

.c.o :
	$(CC) $(CFLAGS) $(INCLUDE) -Ilibft -Imlx -c $< -o $@

clean :
	$(MAKE) clean -C ./mlx
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re