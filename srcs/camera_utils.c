/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:55:13 by yolee             #+#    #+#             */
/*   Updated: 2022/11/04 17:24:03 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

struct s_camera	camera_gen(t_vec3 view_point, t_vec3 orient, double fov)
{
	struct s_camera	camera;

	camera.view_point = view_point;
	camera.orient = v_unit(orient);
	camera.fov = (fov / 180.0) * M_PI;
	return (camera);
}
