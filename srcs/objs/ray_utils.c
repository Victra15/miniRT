/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:42:52 by yolee             #+#    #+#             */
/*   Updated: 2022/11/04 17:26:09 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

struct s_ray	ray_gen(t_vec3 orig, t_vec3 dir)
{
	struct s_ray	ray;

	ray.orig = orig;
	ray.dir = v_unit(dir);
	return (ray);
}
