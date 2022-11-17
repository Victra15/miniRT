/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:27:02 by yolee             #+#    #+#             */
/*   Updated: 2022/11/14 21:36:59 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_ray_shadowed(t_data *data, t_vec3 hit_point, t_obj min_obj)
{
	t_ray	light_ray;
	t_vec3	light_ray_dir;
	t_obj	light_min_obj;

	light_ray_dir = v_diff(hit_point, data->light.light_point);
	light_ray = ray_gen(data->light.light_point, light_ray_dir);
	light_min_obj = get_min_ray_len(data, light_ray);
	if (light_min_obj.obj_ptr != min_obj.obj_ptr)
		return (1);
	else
		return (0);
}
