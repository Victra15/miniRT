/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:31:04 by yolee             #+#    #+#             */
/*   Updated: 2022/11/10 01:45:11 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_obj(t_obj *obj,
		int obj_num,
		void *obj_ptr,
		double distance)
{
	obj->obj_num = obj_num;
	obj->obj_ptr = obj_ptr;
	obj->obj_distance = distance;
}

/*
0보다 작지않은 ray_len 중에서 가장 작은 ray_len를 뽑아서 t_obj초기화 하는 함수
*/
void	min_ray_len(double *ray_len, t_obj *min_obj, void *obj_ptr, int type)
{
	int	size;
	double	min;

	size = sizeof(ray_len) / sizeof(double);
	min = DBL_MAX;
	while (size--)
	{
		if (*ray_len >= 0 && min > *ray_len)
			min = *ray_len;
		if (size > 0)
			ray_len++;
	}
	min_obj->obj_num = type;
	min_obj->obj_ptr = obj_ptr;
	min_obj->obj_destance = min;
	return ;
}

t_obj	get_min_ray_len(t_data *data, t_ray ray)
{
	double	*ray_len_arr;
	double	ray_len;
	t_obj	min_obj;
	t_list	*iter;

	iter = data->sphere_list;
	while (iter)
	{
		ray_len_arr = get_ray_hit_to_sphere((*(t_sphere *)iter->content), ray);
		// obj init
		min_ray_len(ray_len_arr, &min_obj, iter->content, OBJ_SPHERE);
		iter = iter->next;
	}
	iter = data->plane_list;
	while (iter)
	{
		ray_len = get_ray_hit_to_plane(*(t_plane *)iter->content, ray);
		// obj init
		min_ray_len(&ray_len, &min_obj, iter->content, OBJ_PLANE);
		iter = iter->next;
	}
	iter = data->cylinder_list;
	while (iter)
	{
		ray_len_arr = get_ray_hit_to_cylinder(*(t_cylinder *)iter->content, ray);
		// obj init
		min_ray_len(ray_len_arr, &min_obj, iter->content, OBJ_CYLINDER);
		iter = iter->next;
	}
	return (min_obj);
}

/*
get length ray origin to ray's hit point in sphere
vec_o : vector ray origin to sphere center
r : radius of sphere
d : distance between ray and sphere center
*/
double	*get_ray_hit_to_sphere(t_sphere sphere, t_ray ray)
{
	double	ray_len[2];
	t_vec3	vec_o;
	double	r;
	double	d;

	ray_len[0] = -1.0;
	ray_len[1] = -1.0;
	r = sphere.diameter / 2;
	vec_o = v_diff(sphere.cen, ray.orig);
	d = sqrt(v_inner(vec_o, vec_o) - pow(v_inner(vec_o, ray.dir), 2));
	if (r > d)
	{
		ray_len[0] = v_inner(vec_o, ray.dir) - sqrt((r * r) - (d * d));
		ray_len[1] = v_inner(vec_o, ray.dir) + sqrt((r * r) - (d * d));
	}
	return (ray_len);
}

/*
get length ray origin to ray's hit point in plane
d : distance ray origin to plane
cos_n : cosine value of angle
		between plane normal vector and ray direction vector
*/
double	get_ray_hit_to_plane(t_plane plane, t_ray ray)
{
	double	ray_len;
	double	d;
	double	cos_n;

	d = v_inner(v_diff(plane.plane_point, ray.orig), plane.norm);
	cos_n = v_inner(ray.dir, plane.norm);
	ray_len = d / cos_n;
	if (cos_n != 0.0 && ray_len > 0.0)
		return (ray_len);
	else
		return (-1.0);
}
