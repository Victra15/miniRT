/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:03:13 by yolee             #+#    #+#             */
/*   Updated: 2022/10/24 22:17:02 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
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

t_ray		gen_ray(t_pos pixel_pos);
t_color3	get_ray_color(t_ray *ray);
void		trace_ray(t_data *data, t_pos pixel_pos);

#endif