/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:31:04 by yolee             #+#    #+#             */
/*   Updated: 2022/11/17 19:09:20 by yolee            ###   ########.fr       */
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

static void	min_ray_len(double ray_len, t_obj *min_obj, void *obj_ptr, int type)
{
	if (min_obj->obj_distance == -1.0 || (min_obj->obj_distance > ray_len
			&& ray_len != -1.0))
		init_obj(min_obj, type, obj_ptr, ray_len);
	return ;
}

static void	iter_obj_list(t_list *obj_list,
		int obj_code,
		t_obj *min_obj,
		t_ray ray)
{
	double		ray_len;
	t_list		*iter;

	iter = obj_list;
	while (iter)
	{
		if (obj_code == OBJ_SPHERE)
			ray_len = get_ray_hit_to_sphere(*(t_sphere *)iter->content, ray);
		else if (obj_code == OBJ_PLANE)
			ray_len = get_ray_hit_to_plane(*(t_plane *)iter->content, ray);
		else if (obj_code == OBJ_CYLINDER)
		{
			ray_len = get_ray_hit_to_cylinder(*(t_cylinder *)iter->content,
					ray);
		}
		min_ray_len(ray_len, min_obj, iter->content, obj_code);
		iter = iter->next;
	}
}

t_obj	get_min_ray_len(t_data *data, t_ray ray)
{
	t_obj	min_obj;

	min_obj.obj_distance = -1.0;
	min_obj.obj_ptr = NULL;
	min_obj.obj_num = -1;
	iter_obj_list(data->sphere_list, OBJ_SPHERE, &min_obj, ray);
	iter_obj_list(data->plane_list, OBJ_PLANE, &min_obj, ray);
	iter_obj_list(data->cylinder_list, OBJ_CYLINDER, &min_obj, ray);
	return (min_obj);
}

t_color3	calc_ray_color(t_data *data, t_ray ray, t_obj min_obj)
{
	t_vec3		hit_point;

	hit_point = v_sum(v_mult(ray.dir, min_obj.obj_distance), ray.orig);
	if (is_ray_shadowed(data, hit_point, min_obj))
		return (c_gen(0.0, 0.0, 0.0));
	else if (min_obj.obj_num == OBJ_SPHERE)
		return (get_sphere_ray_color(data, min_obj.obj_ptr, hit_point));
	else if (min_obj.obj_num == OBJ_PLANE)
		return (get_plane_ray_color(data, min_obj.obj_ptr, hit_point));
	else if (min_obj.obj_num == OBJ_CYLINDER)
		return (get_cylinder_ray_color(data, min_obj.obj_ptr, hit_point));
	else
		return (c_gen(0.0, 0.1, 0.2));
}
