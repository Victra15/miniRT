/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:41:54 by yolee             #+#    #+#             */
/*   Updated: 2022/11/10 01:44:05 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	put_pixel_to_image(t_img *img, int x, int y, t_color3 color)
{
	char			*dst;
	unsigned int	*conv_dst;
	int				conv_color;

	conv_color = (int)color.x * 256 * 256 + (int)color.y * 256 + (int)color.z;
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
					(1 - 2 * (pixel_pos.x / WINDOW_WIDTH))
				)
			),
			v_mult (
				camera.h_dir_vp,
				(1 - 2 * (pixel_pos.x / WINDOW_WIDTH))
			)
		)
	);
}

static t_color3	get_ray_color(t_data *data, t_ray pixel_ray)
{
	t_color3	ray_color;
	t_obj		min_obj;

	min_obj = get_min_ray_len(data, pixel_ray);
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
	int			conv_color;

	pixel_ray = ray_gen(data->camera.view_point,
			get_ray_dir(data->camera, pixel_pos));
	(void)pixel_ray;
	ray_color = get_ray_color(data, pixel_ray);
	put_pixel_to_image(&data->img, pixel_pos.x, pixel_pos.y, ray_color);
}
