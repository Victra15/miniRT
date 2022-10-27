/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:23:56 by yolee             #+#    #+#             */
/*   Updated: 2022/10/27 20:28:25 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

struct s_light	light_gen(t_vec3 coor, double ratio, t_color3 color)
{
	struct s_light	light;

	light.coor = coor;
	light.ratio = ratio;
	light.color = color;
	return (light);
}
