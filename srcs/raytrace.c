/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:41:54 by yolee             #+#    #+#             */
/*   Updated: 2022/10/27 20:20:56 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	trace_ray(t_data *data, t_pos pixel_pos)
{
	(void)data;
	(void)pixel_pos;
	// t_ray		pixel_ray;
	t_color3	ray_color;
	int			conv_color;

	// pixel_ray = gen_ray(pixel_pos);
	// ray_color = get_ray_color(&pixel_ray);
	ray_color.x = 1.0;
	ray_color.y = 1.0;
	ray_color.z = 1.0;
	conv_color = (int)(ray_color.x * 255.999) * 256 * 256
		+ (int)(ray_color.y * 255.999) * 256
		+ (int)(ray_color.z * 255.999);
	put_pixel_to_image(&data->img, pixel_pos.x, pixel_pos.y, conv_color);
}
