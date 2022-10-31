/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:36:07 by yolee             #+#    #+#             */
/*   Updated: 2022/10/31 20:36:46 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	input_vector(char **strs)
{
	t_vec3	vec;

	vec = v_gen(ft_atof(strs[0]),
			ft_atof(strs[1]),
			ft_atof(strs[2]));
	return (vec);
}

t_color3	input_color(char **strs)
{
	t_color3	col;

	col = v_gen(ft_atof(strs[0]) / 255.0,
			ft_atof(strs[1]) / 255.0,
			ft_atof(strs[2]) / 255.0);
	if (col.x > 1.0 || col.y > 1.0 || col.z > 1.0
		|| col.x < 0.0 || col.y < 0.0 || col.z < 0.0)
		exit_with_custom_error("invalid color input.");
	return (col);
}

double	input_ratio(char *str)
{
	double	ratio;

	ratio = ft_atof(str);
	if (ratio > 1 || ratio < 0)
		exit_with_custom_error("invalid ratio input.");
	return (ratio);
}
