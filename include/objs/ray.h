/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:12:32 by yolee             #+#    #+#             */
/*   Updated: 2022/11/13 22:14:16 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "vector.h"
# include "color.h"

typedef struct s_ray
{
	t_vec3	orig;
	t_vec3	dir;
}t_ray;

struct s_ray	ray_gen(t_vec3 orig, t_vec3 dir);

#endif