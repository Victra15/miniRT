/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:47:02 by yolee             #+#    #+#             */
/*   Updated: 2022/11/10 01:29:23 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
get projected ray to plane
d : distance ray origin to plane
cos_n : cosine value of angle
		between plane normal vector and ray direction vector
*/
static t_ray	get_proj_ray(t_plane plane, t_ray ray)
{
	double	cos_n;
	double	d;

	cos_n = v_inner(ray.dir, plane.norm);
	d = v_inner(v_diff(plane.plane_point, ray.orig), plane.norm);
	if (cos_n != 0.0)
	{
		return (ray_gen(v_sum(v_mult(plane.norm, d), ray.orig),
				v_diff(ray.dir, v_mult(plane.norm, cos_n))));
	}
	else
	{
		return (ray_gen(v_sum(v_mult(plane.norm, d), ray.orig),
				ray.dir));
	}
}

static double	*get_ray_len_for_cylinder(double ray_len_p[2],
		double h[2],
		t_cylinder cyl
		t_ray ray)
{
	double	ray_len[2];
	double	d[2];
	double	d_n;

	d_n = v_inner(v_diff(cyl.cen, ray.orig), cyl.orient);
	ray_len[0] = sqrt(pow(ray_len_p[0], 2) + pow(h[0], 2));
	ray_len[1] = sqrt(pow(ray_len_p[1], 2) + pow(h[1], 2));
	d[0] = h[0] - d_n;
	d[1] = h[1] - d_n;
	if (fabs(d[0]) > c_height / 2 && fabs(d[1]) < c_height / 2)
	{
		if (d[0] > 0.0)
		{
			ray_len[0] = get_ray_hit_to_plane(plane_gen(v_diff(cyl.cen,
							v_mult(cyl.orient, cyl.sca.height / 2)),
						cyl.orient, v_gen(0.0, 0.0, 0.0)), ray);
		}
		else
		{
			ray_len[0] = get_ray_hit_to_plane(plane_gen(v_sum(cyl.cen,
							v_mult(cyl.orient, cyl.sca.height / 2)),
						cyl.orient, v_gen(0.0, 0.0, 0.0)), ray);
		}
	}
	return (ray_len);
}

/*
get length ray origin to ray's hit point in cylinder
h : height
*/
double	*get_ray_hit_to_cylinder(t_cylinder cyl, t_ray ray)
{
	double	*ray_len_p;
	double	h[2];
	t_ray	ray_proj;
	double	d_n;

	ray_proj = get_proj_ray(
			plane_gen(cyl.cen, cyl.orient, v_gen(0.0, 0.0, 0.0)), ray);
	ray_len_p = get_ray_hit_to_sphere(sphere_gen(
				cyl.cen, cyl.sca.diameter, v_gen(0.0, 0.0, 0.0)), ray_proj);
	h[0] = ray_len_p[0] * v_inner(ray.dir, cyl.orient)
		/ v_inner(ray.dir, ray_proj.dir);
	h[1] = ray_len_p[1] * v_inner(ray.dir, cyl.orient)
		/ v_inner(ray.dir, ray_proj.dir);
	return (get_ray_len_for_cylinder(ray_len_p, h, cyl));
}
