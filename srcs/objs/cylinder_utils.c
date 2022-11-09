/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:12:06 by yolee             #+#    #+#             */
/*   Updated: 2022/11/09 17:17:43 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

struct s_cyl_sca	cylinder_sca_gen(double diameter, double height)
{
	struct s_cyl_sca	cylinder_sca;

	cylinder_sca.diameter = diameter;
	cylinder_sca.height = height;
	return (cylinder_sca);
}

struct s_cylinder	cylinder_gen(t_vec3 cen,
						t_vec3 orient,
						t_cyl_sca sca,
						t_color3 color)
{
	struct s_cylinder	cylinder;

	cylinder.cen = cen;
	cylinder.orient = orient;
	cylinder.sca = sca;
	cylinder.color = color;
	return (cylinder);
}
