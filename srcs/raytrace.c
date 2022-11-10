/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:41:54 by yolee             #+#    #+#             */
/*   Updated: 2022/11/11 07:30:49 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	put_pixel_to_image(t_img *img, int x, int y, t_color3 color)
{
	char			*dst;
	unsigned int	*conv_dst;
	int				conv_color;

	conv_color = ((int)(color.x * 255.999) * 256 * 256)
		+ ((int)(color.y * 255.999) * 256)
		+ ((int)(color.z * 255.999));
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	conv_dst = (unsigned int *)dst;
	*conv_dst = conv_color;
}

static t_vec3	get_ray_dir(t_camera camera, t_pos pixel_pos)
{
	return (
		v_sum (
			v_sum (
				camera.orient,
				v_mult (
					camera.v_dir_vp,
					(1 - 2 * (pixel_pos.y / (double)WINDOW_HEIGHT))
				)
			),
			v_mult (
				camera.h_dir_vp,
				(1 - 2 * (pixel_pos.x / (double)WINDOW_WIDTH))
			)
		)
	);
}

static t_color3	calc_ray_color(t_data *data, t_ray ray, t_obj min_obj)
{
	t_vec3		hit_point;
	t_color3	result;

	result = v_gen(0.0, 0.0, 0.0);
	hit_point = v_sum(v_mult(ray.dir, min_obj.obj_distance), ray.orig);
	if (min_obj.obj_num == OBJ_SPHERE)
	{
		result = v_sum_color(v_mult(((t_sphere *)min_obj.obj_ptr)->color, data->am_light.ratio),
						v_mult_color(((t_sphere *)min_obj.obj_ptr)->color, v_inner(v_unit(v_diff(data->light.light_point, hit_point)),
																			v_unit(v_diff(hit_point, ((t_sphere *)min_obj.obj_ptr)->cen)))));
		// result = v_mult_color(((t_sphere *)min_obj.obj_ptr)->color, v_inner(v_unit(v_diff(data->light.light_point, hit_point)),
																			// v_unit(v_diff(hit_point, ((t_sphere *)min_obj.obj_ptr)->cen))));
	}
	else if (min_obj.obj_num == OBJ_PLANE)
	{
		result = v_sum_color(v_mult(((t_plane *)min_obj.obj_ptr)->color, data->am_light.ratio),
						v_mult_color(((t_plane *)min_obj.obj_ptr)->color, v_inner(v_unit(v_diff(data->light.light_point, hit_point)),
																			((t_plane *)min_obj.obj_ptr)->norm)));
	}
	return (result);
}

static t_color3	get_ray_color(t_data *data, t_ray pixel_ray)
{
	t_color3	ray_color;
	t_obj		min_obj;

	ray_color = v_gen(0.0, 0.0, 0.0);
	min_obj = get_min_ray_len(data, pixel_ray);
	if (min_obj.obj_distance != -1.0)
		ray_color = calc_ray_color(data, pixel_ray, min_obj);

	/*
		calc ray_color;
		내용 : min_obj을 이용해서 ray_color 계산하는 부분
		phong lighting = ambient light(am_light) + diffusion(light, obj);
	*/
	return (ray_color);
}

void	trace_ray(t_data *data, t_pos pixel_pos)
{
	t_ray		pixel_ray;
	t_color3	ray_color;

	pixel_ray = ray_gen(data->camera.view_point,
			get_ray_dir(data->camera, pixel_pos));
	(void)pixel_ray;
	ray_color = get_ray_color(data, pixel_ray);
	put_pixel_to_image(&data->img, pixel_pos.x, pixel_pos.y, ray_color);
}
