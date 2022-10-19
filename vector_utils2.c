/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:42:54 by yolee             #+#    #+#             */
/*   Updated: 2022/10/19 23:24:20 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

struct s_dvec3	v_unit(struct s_dvec3 vec)
{
	double			len;
	struct s_dvec3	result;

	len = v_len(vec);
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
