/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:08:12 by yolee             #+#    #+#             */
/*   Updated: 2022/11/14 22:01:52 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
function :	get length ray origin to ray's hit point in plane

parameters
plane :	plane object
ray :	ray emitted to plane

variables
d : distance ray origin to plane
cos_n : cosine value of angle
		between plane normal vector and ray direction vector
		
return value :	length of ray origin to ray hit point,
				if ray not hit, return -1.0
*/
double	get_ray_hit_to_plane(t_plane plane, t_ray ray)
{
	double	ray_len;
	double	d;
	double	cos_n;

	d = v_inner(v_diff(plane.plane_point, ray.orig), plane.norm);
	cos_n = v_inner(ray.dir, plane.norm);
	ray_len = d / cos_n;
	if (cos_n != 0.0 && ray_len > 0.0)
		return (ray_len);
	else
		return (-1.0);
}

t_color3	get_plane_ray_color(t_data *data,
	t_plane *plane,
	t_vec3 hit_point)
{
	t_color3	light_color;
	double		light_diffuse;

	light_diffuse = v_inner(
			v_unit(v_diff(data->light.light_point, hit_point)), plane->norm);
	light_color = c_sum(c_mult_sca(data->am_light.color, data->am_light.ratio),
			c_mult_sca(data->light.color, light_diffuse));
	return (c_mult(light_color, plane->color));
}
