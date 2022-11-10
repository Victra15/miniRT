# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 15:50:14 by yolee             #+#    #+#              #
#    Updated: 2022/11/11 05:11:16 by yolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = cc
CFLAGS = -Werror -Wall -Wextra -g
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFTFLAGS = -Llibft -lft
INCLUDE = -I ./include -I ./include/objs
OBJECT_CODE_DIR = objs
OBJECT_CODE = ray_utils.c \
	camera_utils.c \
	ambient_light_utils.c \
	sphere_utils.c \
	plane_utils.c \
	light_utils.c \
	cylinder_utils.c \
	vector_utils1.c \
	vector_utils2.c \
	
SRCS_DIR = srcs
SRCS_FILE = minirt.c \
	raytrace.c \
	ft_atof.c \
	parse.c \
	parse2.c \
	parse_utils.c \
	error_handling.c \
	error_handling2.c \
	get_next_line.c	\
	raytrace_utils.c \
	# raytrace_utils2.c \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE))
SRCS += $(addprefix $(SRCS_DIR)/$(OBJECT_CODE_DIR)/, $(OBJECT_CODE))
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
	$(MAKE) fclean -C ./libft
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re