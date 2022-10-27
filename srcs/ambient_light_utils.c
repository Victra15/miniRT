/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:58:08 by yolee             #+#    #+#             */
/*   Updated: 2022/10/27 20:28:07 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient_light.h"

struct s_ambient_light	ambient_light_gen(double ratio, t_color3 color)
{
	struct s_ambient_light	ambient_light;

	ambient_light.ratio = ratio;
	ambient_light.color = color;
	return (ambient_light);
}
