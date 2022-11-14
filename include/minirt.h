/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:03:13 by yolee             #+#    #+#             */
/*   Updated: 2022/11/14 17:19:48 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "camera.h"
# include "ambient_light.h"
# include "light.h"
# include "cylinder.h"
# include "plane.h"
# include "ray.h"
# include "sphere.h"
# include "vector.h"
# include "color.h"

# define WINDOW_HEIGHT 720
# define WINDOW_WIDTH 1024
# define KEYCODE_ESC 53
# define KEYCODE_EXIT 17
# define OBJ_SPHERE 0
# define OBJ_PLANE 1
# define OBJ_CYLINDER 2

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

typedef struct s_obj
{
	int		obj_num;
	void	*obj_ptr;
	double	obj_distance;
}t_obj;

typedef struct s_data
{
	t_mlx				mlx;
	t_img				img;
	t_camera			camera;
	t_light				light;
	t_ambient_light		am_light;
	t_list				*sphere_list;
	t_list				*plane_list;
	t_list				*cylinder_list;
}t_data;

/* error_handling */
int			ft_data_len(void **data);
void		input_checker(void **data, int data_len, char *str);
void		free_all(void **data);
void		exit_with_error(void);
void		exit_with_custom_error(char	*custom_msg);
int			is_file_ext_rt(char	*f_name);
void		data_ptr_init(t_data *data);

/* parse */
void		parse_data(t_data *data, char *filename);
void		parse_ambient_light(t_data *data, char **data_strs);
void		parse_cylinder(t_data *data, char **data_strs);
void		parse_camera(t_data *data, char **data_strs);
void		parse_light(t_data *data, char **data_strs);
void		parse_plane(t_data *data, char **data_strs);
void		parse_sphere(t_data *data, char **data_strs);

/* parse_utils */
double		ft_atof(const char *str);
t_vec3		input_vector(char **strs);
t_color3	input_color(char **strs);
double		input_ratio(char *str);

/* ray tracing */
void		trace_ray(t_data *data, t_pos pixel_pos);
double		get_ray_hit_to_sphere(t_sphere sphere, t_ray ray);
double		get_ray_hit_to_plane(t_plane plane, t_ray ray);
double		get_ray_hit_to_cylinder(t_cylinder cylinder, t_ray ray);
t_color3	get_plane_ray_color(t_data *data,
				t_plane *plane,
				t_vec3 hit_point);
t_color3	get_sphere_ray_color(t_data *data,
				t_sphere *sphere,
				t_vec3 hit_point);
t_color3	get_cylinder_ray_color(t_data *data,
				t_cylinder *cylinder,
				t_vec3 hit_point);	

/* ray tracing_utils */
t_obj		get_min_ray_len(t_data *data, t_ray ray);
t_color3	calc_ray_color(t_data *data, t_ray ray, t_obj min_obj);
int			is_ray_shadowed(t_data *data, t_vec3 hit_point, t_obj min_obj);

#endif
