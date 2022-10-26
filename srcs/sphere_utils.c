/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:11:32 by yolee             #+#    #+#             */
/*   Updated: 2022/10/26 21:22:44 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

struct s_sphere	sphere_gen(t_vec3 cen, double diameter, t_color3 color)
{
	struct s_sphere	sphere;

	sphere.cen = cen;
	sphere.diameter = diameter;
	sphere.color = color;
	return (sphere);
}

void	parse_sphere(t_data *data, char **data_strs)
{
	
}