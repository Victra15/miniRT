/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:53:48 by yolee             #+#    #+#             */
/*   Updated: 2022/10/26 21:23:08 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "vector.h"

typedef struct s_camera
{
	t_vec3		coor;
	t_vec3		orient;
	double		fov;
}t_camera;

struct s_camera	camera_gen(t_vec3 coor, t_vec3 orient, double fov);
void			parse_camera(t_data *data, char char **data_strs);

#endif