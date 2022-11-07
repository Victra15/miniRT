/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:41:54 by yolee             #+#    #+#             */
/*   Updated: 2022/11/04 17:47:35 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char			*dst;
	unsigned int	*conv_dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	conv_dst = (unsigned int *)dst;
	*conv_dst = color;
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

// static void	get_ray_color(t_data *data, t_ray pixel_ray)
// {
	
// }

void	trace_ray(t_data *data, t_pos pixel_pos)
{
	t_ray		pixel_ray;
	// t_color3	ray_color;
	// int			conv_color;

	pixel_ray = ray_gen(data->camera.view_point,
			get_ray_dir(data->camera, pixel_pos));
	(void)pixel_ray;
	// get_ray_color(data, pixel_ray);
	put_pixel_to_image(&data->img, pixel_pos.x, pixel_pos.y, 0x00FFFFFF);
}
