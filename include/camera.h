/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:53:48 by yolee             #+#    #+#             */
/*   Updated: 2022/11/04 16:50:43 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "vector.h"

typedef struct s_camera
{
	t_vec3		view_point;
	t_vec3		orient;
	double		fov;
	t_vec3		h_dir_vp;
	t_vec3		v_dir_vp;
}t_camera;

struct s_camera		camera_gen(t_vec3 view_point, t_vec3 orient, double fov);

#endif