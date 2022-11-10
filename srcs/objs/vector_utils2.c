/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:42:54 by yolee             #+#    #+#             */
/*   Updated: 2022/11/11 07:20:08 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

struct s_dvec3	v_cross(struct s_dvec3 vec1, struct s_dvec3 vec2)
{
	struct s_dvec3	result;

	result.x = (vec1.y * vec2.z) - (vec1.z * vec2.y);
	result.y = (vec1.z * vec2.x) - (vec1.x * vec2.z);
	result.z = (vec1.x * vec2.y) - (vec1.y * vec2.x);
	return (result);
}

struct s_dvec3	v_unit(struct s_dvec3 vec)
{
	double			len;
	struct s_dvec3	result;

	len = v_abs(vec);
	result.x = vec.x / len;
	result.y = vec.y / len;
	result.z = vec.z / len;
	return (result);
}

struct s_dvec3	v_gen(double x, double y, double z)
{
	struct s_dvec3	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

static struct s_dvec3	v_color_handle(struct s_dvec3 vec)
{
	if (vec.x > 1.0)
		vec.x = 1.0;
	if (vec.y > 1.0)
		vec.y = 1.0;
	if (vec.z > 1.0)
		vec.z = 1.0;
	if (vec.x < 0.0)
		vec.x = 0.0;
	if (vec.y < 0.0)
		vec.y = 0.0;
	if (vec.z < 0.0)
		vec.z = 0.0;
	return (vec);
}

struct s_dvec3	v_sum_color(struct s_dvec3 vec1, struct s_dvec3 vec2)
{
	return (v_color_handle(v_sum(vec1, vec2)));
}

struct s_dvec3	v_mult_color(struct s_dvec3 vec1, double sca)
{
	return (v_color_handle(v_mult(vec1, sca)));
}
