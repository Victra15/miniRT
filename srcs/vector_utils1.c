/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:32:59 by yolee             #+#    #+#             */
/*   Updated: 2022/10/27 20:21:22 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	v_inner(struct s_dvec3 vec1, struct s_dvec3 vec2)
{
	double	result;

	result = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	return (result);
}

struct s_dvec3	v_sum(struct s_dvec3 vec1, struct s_dvec3 vec2)
{
	struct s_dvec3	result;

	result.x = vec1.x + vec2.x;
	result.y = vec1.y + vec2.y;
	result.z = vec1.z + vec2.z;
	return (result);
}

struct s_dvec3	v_diff(struct s_dvec3 vec1, struct s_dvec3 vec2)
{
	struct s_dvec3	result;

	result.x = vec1.x - vec2.x;
	result.y = vec1.y - vec2.y;
	result.z = vec1.z - vec2.z;
	return (result);
}

struct s_dvec3	v_mult(struct s_dvec3 vec, double sca)
{
	struct s_dvec3	result;

	result.x = vec.x * sca;
	result.y = vec.y * sca;
	result.z = vec.z * sca;
	return (result);
}

double	v_abs(struct s_dvec3 vec)
{
	double	result;

	result = pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2);
	result = sqrt(result);
	return (result);
}
