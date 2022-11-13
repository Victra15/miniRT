/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_cylinder2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:42:00 by yolee             #+#    #+#             */
/*   Updated: 2022/11/14 00:01:51 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color3	get_cylinder_ray_color(t_data *data,
	t_cylinder *cylinder,
	t_vec3 hit_point)
{
	t_color3	light_color;
	double		light_diffuse;

	light_diffuse = v_inner(
			v_unit(v_diff(hit_point, data->light.light_point)),
			cylinder->orient);
	light_color = c_sum(c_mult_sca(data->am_light.color, data->am_light.ratio),
			c_mult_sca(data->light.color, light_diffuse));
	return (c_mult(light_color, cylinder->color));
}
