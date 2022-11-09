/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:12:38 by yolee             #+#    #+#             */
/*   Updated: 2022/11/09 17:16:42 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H
# include "ray.h"

typedef struct s_cyl_sca
{
	double	diameter;
	double	height;
}t_cyl_sca;

typedef struct s_cylinder
{
	t_vec3		cen;
	t_vec3		orient;
	t_cyl_sca	sca;
	t_color3	color;
}t_cylinder;

struct s_cylinder	cylinder_gen(t_vec3 cen,
						t_vec3 orient,
						t_cyl_sca sca,
						t_color3 color);
struct s_cyl_sca	cylinder_sca_gen(double diameter, double height);

#endif