/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:42:52 by yolee             #+#    #+#             */
/*   Updated: 2022/10/24 22:00:52 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

struct s_ray	ray_gen(t_vec3 orig, t_vec3 dir)
{
	struct s_ray	ray;

	ray.orig = orig;
	ray.dir = dir;
	return (ray);
}
