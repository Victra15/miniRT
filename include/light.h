/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:00:42 by yolee             #+#    #+#             */
/*   Updated: 2022/11/02 19:54:38 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "vector.h"

typedef struct s_light
{
	t_vec3		light_point;
	double		ratio;
	t_color3	color;
}t_light;

struct s_light	light_gen(t_vec3 light_point, double ratio, t_color3 color);

#endif