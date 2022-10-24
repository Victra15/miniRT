/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:12:34 by yolee             #+#    #+#             */
/*   Updated: 2022/10/24 22:01:37 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H
# include "vector.h"

typedef struct s_plane
{
	t_vec3			coor;
	t_vec3			orient;
	t_color3		color;
}t_plane;

struct s_plane	plane_gen(t_vec3 coor, t_vec3 orient, t_color3 color);

#endif