/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:12:06 by yolee             #+#    #+#             */
/*   Updated: 2022/10/26 21:23:30 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

struct s_cylinder	cylinder_gen(t_vec3 coor,
						t_vec3 orient,
						t_cyl_sca sca,
						t_color3 color)
{
	struct s_cylinder	cylinder;

	cylinder.coor = coor;
	cylinder.orient = orient;
	cylinder.sca = sca;
	cylinder.color = color;
	return (cylinder);
}

struct s_cyl_sca	cylinder_sca_gen(double diameter, double height)
{
	struct s_cyl_sca	cylinder_sca;

	cylinder_sca.diameter = diameter;
	cylinder_sca.height = height;
	return (cylinder_sca);
}

void	parse_cylinder(t_data *data, char **data_strs)
{
	
}