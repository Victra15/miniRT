/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:35:19 by yolee             #+#    #+#             */
/*   Updated: 2022/11/13 21:44:47 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

static struct s_color3	v_color_handle(struct s_color3 col)
{
	if (col.r > 1.0)
		col.r = 1.0;
	if (col.g > 1.0)
		col.g = 1.0;
	if (col.b > 1.0)
		col.b = 1.0;
	if (col.r < 0.0)
		col.r = 0.0;
	if (col.g < 0.0)
		col.g = 0.0;
	if (col.b < 0.0)
		col.b = 0.0;
	return (col);
}

struct s_color3	c_gen(double r, double g, double b)
{
	struct s_color3	result;

	result.r = r;
	result.g = g;
	result.b = b;
	return (v_color_handle(result));
}

struct s_color3	c_sum(struct s_color3 col1, struct s_color3 col2)
{
	struct s_color3	result;

	result.r = col1.r + col2.r;
	result.g = col1.g + col2.g;
	result.b = col1.b + col2.b;
	return (v_color_handle(result));
}

struct s_color3	c_mult(struct s_color3 col1, struct s_color3 col2)
{
	struct s_color3	result;

	result.r = col1.r * col2.r;
	result.g = col1.g * col2.g;
	result.b = col1.b * col2.b;
	return (v_color_handle(result));
}

struct s_color3	c_mult_sca(struct s_color3 col1, double sca)
{
	struct s_color3	result;

	result.r = col1.r * sca;
	result.g = col1.g * sca;
	result.b = col1.b * sca;
	return (v_color_handle(result));
}
