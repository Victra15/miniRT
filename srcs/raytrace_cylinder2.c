/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_cylinder2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:42:00 by yolee             #+#    #+#             */
/*   Updated: 2022/11/19 20:23:56 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec3	get_normal_vec(t_cylinder *cylinder, t_vec3 hit_point)
{
	t_vec3	cen_to_hp;
	t_vec3	hp_v;

	cen_to_hp = v_diff(hit_point, cylinder->cen);
	if (v_inner(cen_to_hp, cylinder->orient)
		< cylinder->sca.height / 2 + EPSILON
		&& v_inner(cen_to_hp, cylinder->orient)
		> cylinder->sca.height / 2 - EPSILON)
		return (cylinder->orient);
	else if (v_inner(cen_to_hp, cylinder->orient)
		< -cylinder->sca.height / 2 + EPSILON
		&& v_inner(cen_to_hp, cylinder->orient)
		> -cylinder->sca.height / 2 - EPSILON)
		return (v_mult(cylinder->orient, -1));
	else
	{
		hp_v = v_mult(cylinder->orient, v_inner(cen_to_hp, cylinder->orient));
		return (v_unit(v_diff(cen_to_hp, hp_v)));
	}
}

t_color3	get_cylinder_ray_color(t_data *data,
	t_cylinder *cylinder,
	t_vec3 hit_point)
{
	t_vec3		norm;
	t_color3	light_color;
	double		light_diffuse;

	norm = get_normal_vec(cylinder, hit_point);
	light_diffuse = v_inner(
			v_unit(v_diff(data->light.light_point, hit_point)), norm);
	light_color = c_sum(c_mult_sca(data->am_light.color, data->am_light.ratio),
			c_mult_sca(data->light.color, light_diffuse));
	return (c_mult(light_color, cylinder->color));
}

/*
functions :	select ray length smaller that not smaller than 0

parameters
ray_len0 :	first length ray origin to hit point
ray_len1 :	second length ray origin to hit point

return value :	if ray_len0 hit, return 0,
				if ray_len1 hit, return 1,
				if any ray not hit, return -1
*/
int	select_cyl_ray_len_return(double ray_len0, double ray_len1)
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
