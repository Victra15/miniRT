/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:53:43 by yolee             #+#    #+#             */
/*   Updated: 2022/10/26 21:23:09 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_LIGHT_H
# define AMBIENT_LIGHT_H
# include "vector.h"

typedef struct s_ambient_light
{
	double		ratio;
	t_color3	color;
}t_ambient_light;

struct s_ambient_light	ambient_light_gen(double ratio, t_color3 color);
void					parse_ambient_light(t_data data, char **data_strs);

#endif