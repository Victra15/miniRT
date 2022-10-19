/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:42:52 by yolee             #+#    #+#             */
/*   Updated: 2022/10/19 23:48:46 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	gen_ray(t_pos pixel_pos)
{
	t_ray	ray;
	double	camera_distance;

	camera_distance = 5.0;
	ray.orig = v_gen(0.0, 0.0, 0.0);
	ray.dir = v_gen((double)(pixel_pos.x - WINDOW_WIDTH / 2),
			(double)(pixel_pos.y + WINDOW_HEIGHT / 2),
			camera_distance);
	return (ray);
}

t_color3	get_ray_color(t_ray *ray)
{
	double	t;

	t = (ray->dir.y / WINDOW_HEIGHT - 0.5);
	return (v_sum(v_mult(v_gen(1, 1, 1), 1.0 - t),
			v_mult(v_gen(0.5, 0.7, 1.0), t)));
}
