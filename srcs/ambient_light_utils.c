/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:58:08 by yolee             #+#    #+#             */
/*   Updated: 2022/10/26 22:09:22 by yolee            ###   ########.fr       */
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

void	parse_ambient_light(t_data *data, char **data_strs)
{
	data->am_light.ratio = data
}