/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:47:02 by yolee             #+#    #+#             */
/*   Updated: 2022/11/19 20:23:44 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
function : get projected ray to plane that slices cylinder in half

parameters
cyl : cylinder object
ray : the ray before projection

variables
d : distance ray origin to plane
cos_n : cosine value of angle
		between plane normal vector and ray direction vector
		
return value : the ray projected in cylinder center plane
*/
static t_ray	get_proj_ray(t_cylinder cyl, t_ray ray)
{
	t_plane	p_plane;
	double	cos_n;
	double	d;

	p_plane = plane_gen(cyl.cen, cyl.orient, c_gen(0.0, 0.0, 0.0));
	cos_n = v_inner(ray.dir, p_plane.norm);
	d = v_inner(v_diff(p_plane.plane_point, ray.orig), p_plane.norm);
	if (cos_n == 1.0)
		cos_n -= EPSILON;
	if (cos_n == -1.0)
		cos_n += EPSILON;
	if (cos_n != 0.0)
	{
		return (ray_gen(v_sum(v_mult(p_plane.norm, d), ray.orig),
				v_diff(ray.dir, v_mult(p_plane.norm, cos_n))));
	}
	else
	{
		return (ray_gen(v_sum(v_mult(p_plane.norm, d), ray.orig),
				ray.dir));
	}
}

/*
function : get length projected ray origin to hit point
			in cylinder in projection plane

parameters
ray_len_p : length projected ray origin to hit point (array with length 2)
cyl : cylinder object
ray_proj : projected ray

variables
vec_o : the vector projected ray origin to projectd cylinder center
r : projected cylinder radius 
d :	distance between projected ray and projected cylinder center
		
return value :	if projected ray hit, returns 0
				and not hit, returns 1
*/
static int	get_proj_ray_hit(double *ray_len_p,
		t_cylinder cyl,
		t_ray ray_proj)
{
	t_sphere	p_sphere;
	t_vec3		vec_o;
	double		r;
	double		d;
	double		d_e;

	p_sphere = sphere_gen(cyl.cen, cyl.sca.diameter, c_gen(0.0, 0.0, 0.0));
	ray_len_p[0] = -1.0;
	ray_len_p[1] = -1.0;
	r = p_sphere.diameter / 2;
	vec_o = v_diff(p_sphere.cen, ray_proj.orig);
	d_e = v_inner(vec_o, vec_o) - pow(v_inner(vec_o, ray_proj.dir), 2);
	if (d_e < 0.0)
		d = 0.0;
	else
		d = sqrt(d_e);
	if (r > d)
	{
		ray_len_p[0] = v_inner(vec_o, ray_proj.dir) - sqrt((r * r) - (d * d));
		ray_len_p[1] = v_inner(vec_o, ray_proj.dir) + sqrt((r * r) - (d * d));
		return (0);
	}
	else
		return (1);
}

/*
function : get ray hit in cylinder top or bottom plain

parameters
d1 : distance cylinder center plain to first hit point
d2 : distance cylinder center plain to second hit point
h : cylinder height

variables
none
		
return value :	if ray hit to top plain, returns 0
				and hit to bottom plain, returns 1
				and not hit, returns -1
				and hit to cylinder side, returns 2
*/
static int	get_ray_hit_cyl_plane(double d1,
		double d2,
		double h)
{
	if (d1 > h / 2)
	{
		if (d2 <= h / 2)
			return (0);
		else
			return (-1);
	}
	else if (d1 < -h / 2)
	{
		if (d2 >= -h / 2)
			return (1);
		else
			return (-1);
	}
	else
		return (2);
}

/*
function : get length ray origin to hit point in cylinder

parameters
ray_len : length ray origin to hit point (array with length 2)
cyl : cylinder object
ray : ray emitted to cylinder

variables
cyl_top : the plane in cylinder top
cyl_bottom : the plane in cylinder bottom
h : height of hit point against plain 
	that matches ray origin and parallel with projection plain
d :	distance hit point to projection plain
d_n : distance ray origin to projection plain
		
return value :	if projected ray hit, returns 0
				and not hit, returns 1
*/
static void	get_ray_hit(double *ray_len,
		t_cylinder cyl,
		t_ray ray)
{
	t_plane	cyl_top;
	t_plane	cyl_bottom;
	double	d[2];
	double	d_n;

	cyl_top = plane_gen(v_sum(cyl.cen, v_mult(cyl.orient, cyl.sca.height / 2)),
			cyl.orient, c_gen(0.0, 0.0, 0.0));
	cyl_bottom = plane_gen(v_diff(cyl.cen,
				v_mult(cyl.orient, cyl.sca.height / 2)),
			cyl.orient, c_gen(0.0, 0.0, 0.0));
	d_n = v_inner(v_diff(cyl.cen, ray.orig), cyl.orient);
	d[0] = ray_len[0] * v_inner(ray.dir, cyl.orient) - d_n;
	d[1] = ray_len[1] * v_inner(ray.dir, cyl.orient) - d_n;
	if (get_ray_hit_cyl_plane(d[0], d[1], cyl.sca.height) == 0)
		ray_len[0] = get_ray_hit_to_plane(cyl_top, ray);
	else if (get_ray_hit_cyl_plane(d[0], d[1], cyl.sca.height) == 1)
		ray_len[0] = get_ray_hit_to_plane(cyl_bottom, ray);
	else if (get_ray_hit_cyl_plane(d[0], d[1], cyl.sca.height) == -1)
		ray_len[0] = -1.0;
	if (get_ray_hit_cyl_plane(d[1], d[0], cyl.sca.height) == 0)
		ray_len[1] = get_ray_hit_to_plane(cyl_top, ray);
	else if (get_ray_hit_cyl_plane(d[1], d[0], cyl.sca.height) == 1)
		ray_len[1] = get_ray_hit_to_plane(cyl_bottom, ray);
	else if (get_ray_hit_cyl_plane(d[1], d[0], cyl.sca.height) == -1)
		ray_len[1] = -1.0;
}

/*
function :	get length ray origin to ray's hit point in cylinder

parameters
cyl :	cylinder object
ray :	ray emitted to cylinder

variables
ray_proj :	projected ray in plain that slices cylinder in half
ray_len : length ray origin to hit point (array with length 2)
ray_len_p : length projected ray origin to hit point (array with length 2)
		
return value :	length of ray origin to ray hit point,
				if ray not hit, return -1.0
*/
double	get_ray_hit_to_cylinder(t_cylinder cyl, t_ray ray)
{
	t_ray	ray_proj;
	double	ray_len_p[2];
	double	ray_len[2];

	ray_proj = get_proj_ray(cyl, ray);
	if (get_proj_ray_hit(ray_len_p, cyl, ray_proj))
		return (-1.0);
	ray_len[0] = ray_len_p[0] / (v_inner(ray_proj.dir, ray.dir));
	ray_len[1] = ray_len_p[1] / (v_inner(ray_proj.dir, ray.dir));
	get_ray_hit(ray_len, cyl, ray);
	if (select_cyl_ray_len_return(ray_len[0], ray_len[1]) == 0)
		return (ray_len[0]);
	else if (select_cyl_ray_len_return(ray_len[0], ray_len[1]) == 1)
		return (ray_len[1]);
	else
		return (-1.0);
}
