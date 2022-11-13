/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:06:57 by yolee             #+#    #+#             */
/*   Updated: 2022/11/13 23:41:19 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
function :	select ray length smaller that not smaller than 0

parameters
ray_len0 :	first length ray origin to hit point
ray_len1 :	second length ray origin to hit point

return value :	if ray_len0 hit, return 0,
				if ray_len1 hit, return 1,
				if any ray not hit, return -1
*/
static int	select_ray_len_return(double ray_len0, double ray_len1)
{
	if (ray_len1 >= 0 && ray_len0 >= 0)
	{
		if (ray_len0 > ray_len1)
			return (1);
		else
			return (0);
	}
	else if (ray_len1 >= 0)
		return (1);
	else if (ray_len0 >= 0)
		return (0);
	else
		return (-1);
}

/*
function :	get length ray origin to ray's hit point in sphere

parameters
sphere :	cylinder object
ray :	ray emitted to sphere

variables
vec_o :	vector ray origin to sphere center
r :	radius of sphere
d :	distance between ray and sphere center
		
return value :	length of ray origin to ray hit point,
				if ray not hit, return -1.0
*/
double	get_ray_hit_to_sphere(t_sphere sphere, t_ray ray)
{
	double	ray_len[2];
	t_vec3	vec_o;
	double	r;
	double	d;

	ray_len[0] = -1.0;
	ray_len[1] = -1.0;
	r = sphere.diameter / 2.0;
	vec_o = v_diff(sphere.cen, ray.orig);
	d = sqrt(v_inner(vec_o, vec_o) - pow(v_inner(vec_o, ray.dir), 2));
	if (r > d)
	{
		ray_len[0] = v_inner(vec_o, ray.dir) - sqrt((r * r) - (d * d));
		ray_len[1] = v_inner(vec_o, ray.dir) + sqrt((r * r) - (d * d));
		if (select_ray_len_return(ray_len[0], ray_len[1]) == 0)
			return (ray_len[0]);
		else if (select_ray_len_return(ray_len[0], ray_len[1]) == 1)
			return (ray_len[1]);
	}
	return (-1.0);
}

t_color3	get_sphere_ray_color(t_data *data,
	t_sphere *sphere,
	t_vec3 hit_point)
{
	t_color3	light_color;
	double		light_diffuse;

	light_diffuse = v_inner(
			v_unit(v_diff(hit_point, data->light.light_point)),
			v_unit(v_diff(hit_point, sphere->cen)));
	light_color = c_sum(c_mult_sca(data->am_light.color, data->am_light.ratio),
			c_mult_sca(data->light.color, light_diffuse));
	return (c_mult(light_color, sphere->color));
}
