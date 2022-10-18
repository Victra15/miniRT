/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:03:13 by yolee             #+#    #+#             */
/*   Updated: 2022/10/19 00:36:39 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "vector.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920

typedef struct s_ray
{
	t_vec3	orig;
	t_vec3	dir;
}t_ray;


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
	t_mlx	mlx;
	t_img	img;
}t_data;


t_ray		gen_ray(t_pos pixel_pos);
t_color3	get_ray_color(t_ray *ray);
void		trace_ray(t_data *data, t_pos pixel_pos);

#endif