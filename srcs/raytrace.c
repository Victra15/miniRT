/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:41:54 by yolee             #+#    #+#             */
/*   Updated: 2022/11/17 19:14:41 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	put_pixel_to_image(t_img *img, int x, int y, t_color3 color)
{
	char			*dst;
	unsigned int	*conv_dst;
	int				conv_color_code[3];
	int				conv_color;

	conv_color_code[0] = color.r * 255.999;
	conv_color_code[1] = color.g * 255.999;
	conv_color_code[2] = color.b * 255.999;
	conv_color = (conv_color_code[0] * 256 * 256)
		+ (conv_color_code[1] * 256)
		+ conv_color_code[2];
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	conv_dst = (unsigned int *)dst;
	*conv_dst = conv_color;
}

static t_vec3	get_ray_dir(t_camera camera, t_pos pixel_pos)
{
	t_vec3	vp_v;
	t_vec3	vp_h;

	vp_v = v_mult(camera.v_dir_vp,
			(1 - 2 * (pixel_pos.y / (double)WINDOW_HEIGHT)));
	vp_h = v_mult (camera.h_dir_vp,
			(1 - 2 * (pixel_pos.x / (double)WINDOW_WIDTH)));
	return (v_sum(v_sum(camera.orient, vp_v), vp_h));
}

static t_color3	get_ray_color(t_data *data, t_ray pixel_ray)
{
	t_color3	ray_color;
	t_obj		min_obj;

	ray_color = c_gen(0.0, 0.0, 0.0);
	min_obj = get_min_ray_len(data, pixel_ray);
	if (min_obj.obj_distance != -1.0)
		ray_color = calc_ray_color(data, pixel_ray, min_obj);
	return (ray_color);
}

void	trace_ray(t_data *data, t_pos pixel_pos)
{
	t_ray		pixel_ray;
	t_color3	ray_color;

	pixel_ray = ray_gen(data->camera.view_point,
			get_ray_dir(data->camera, pixel_pos));
	ray_color = get_ray_color(data, pixel_ray);
	put_pixel_to_image(&data->img, pixel_pos.x, pixel_pos.y, ray_color);
}
