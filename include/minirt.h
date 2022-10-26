/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:03:13 by yolee             #+#    #+#             */
/*   Updated: 2022/10/26 20:39:09 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "get_next_line.h"
# include "mlx.h"
# include "camera.h"
# include "ambient_light.h"
# include "light.h"
# include "cylinder.h"
# include "plane.h"
# include "ray.h"
# include "sphere.h"

# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920
# define KEYCODE_ESC 53
# define KEYCODE_EXIT 17

typedef struct s_pos
{
	int	x;
	int	y;
}t_pos;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}t_mlx;

typedef struct s_data
{
	t_mlx				mlx;
	t_img				img;
	t_camera			camera;
	t_light				light;
	t_ambient_light		am_light;
	t_list				sphere_list;
	t_list				plane_list;
	t_list				cylinder_list;
}t_data;

void	exit_with_error(void);
void	exit_with_custom_error(char	*custom_msg);
int		is_file_ext_rt(char	*f_name);
void	parse_data(t_data *data, char *filename);
#endif