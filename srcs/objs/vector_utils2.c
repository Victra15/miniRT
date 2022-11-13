/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:42:54 by yolee             #+#    #+#             */
/*   Updated: 2022/11/13 21:35:48 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

struct s_vec3	v_cross(struct s_vec3 vec1, struct s_vec3 vec2)
{
	struct s_vec3	result;

	result.x = (vec1.y * vec2.z) - (vec1.z * vec2.y);
	result.y = (vec1.z * vec2.x) - (vec1.x * vec2.z);
	result.z = (vec1.x * vec2.y) - (vec1.y * vec2.x);
	return (result);
}

struct s_vec3	v_unit(struct s_vec3 vec)
{
	double			len;
	struct s_vec3	result;

	len = v_abs(vec);
	result.x = vec.x / len;
	result.y = vec.y / len;
	result.z = vec.z / len;
	return (result);
}

struct s_vec3	v_gen(double x, double y, double z)
{
	struct s_vec3	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}
