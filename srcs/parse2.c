/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:29:05 by yolee             #+#    #+#             */
/*   Updated: 2022/10/31 20:41:54 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_camera(t_data *data, char **data_strs)
{
	char		**view_point;
	char		**orient;

	input_checker((void **)data_strs, 3, "invalid camera input.");
	view_point = ft_split(data_strs[0], ',');
	input_checker((void **)view_point, 3, "invalid camera view point.");
	orient = ft_split(data_strs[1], ',');
	input_checker((void **)orient, 3, "invalid camera orient.");
	data->camera = camera_gen(input_vector(view_point),
			v_unit(input_vector(orient)),
			ft_atof(data_strs[2]));
	free_all((void **)view_point);
	free_all((void **)orient);
	return ;
}

void	parse_light(t_data *data, char **data_strs)
{
	char	**light_point;
	char	**color;

	input_checker((void **)data_strs, 3, "invalid light input.");
	light_point = ft_split(data_strs[0], ',');
	input_checker((void **)light_point, 3, "invalid light point.");
	color = ft_split(data_strs[2], ',');
	input_checker((void **)color, 3, "invalid light color.");
	data->light = light_gen(input_vector(light_point),
			ft_atof(data_strs[1]),
			input_color(color));
	free_all((void **)light_point);
	free_all((void **)color);
	return ;
}

void	parse_sphere(t_data *data, char **data_strs)
{
	char		**cen;
	char		**color;
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	input_checker((void **)data_strs, 3, "invalid sphere input.");
	cen = ft_split(data_strs[0], ',');
	input_checker((void **)cen, 3, "invalid sphere center.");
	color = ft_split(data_strs[2], ',');
	input_checker((void **)color, 3, "invalid sphere color.");
	(*sphere) = sphere_gen(input_vector(cen),
			ft_atof(data_strs[1]),
			input_color(color));
	ft_lstadd_back(&data->sphere_list, ft_lstnew(sphere));
	free_all((void **)cen);
	free_all((void **)color);
}

void	parse_plane(t_data *data, char **data_strs)
{
	char	**plane_point;
	char	**orient;
	char	**color;
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	input_checker((void **)data_strs, 3, "invalid plane input.");
	plane_point = ft_split(data_strs[0], ',');
	input_checker((void **)plane_point, 3, "invalid plane point.");
	orient = ft_split(data_strs[1], ',');
	input_checker((void **)orient, 3, "invalid plane orient.");
	color = ft_split(data_strs[2], ',');
	input_checker((void **)color, 3, "invalid plane color.");
	(*plane) = plane_gen(input_vector(plane_point),
			v_unit(input_vector(orient)),
			input_color(color));
	ft_lstadd_back(&data->plane_list, ft_lstnew(plane));
	free_all((void **)plane_point);
	free_all((void **)orient);
	free_all((void **)color);
	return ;
}

void	parse_cylinder(t_data *data, char **data_strs)
{
	char		**cylinder_cen;
	char		**orient;
	char		**color;
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	input_checker((void **)data_strs, 5, "invalid cylinder input.");
	cylinder_cen = ft_split(data_strs[0], ',');
	input_checker((void **)cylinder_cen, 3, "invalid cylinder center.");
	orient = ft_split(data_strs[1], ',');
	input_checker((void **)orient, 3, "invalid cylinder orient.");
	color = ft_split(data_strs[4], ',');
	input_checker((void **)color, 3, "invalid cylinder color.");
	(*cylinder) = cylinder_gen(input_vector(cylinder_cen),
			v_unit(input_vector(orient)),
			cylinder_sca_gen(ft_atof(data_strs[2]),
				ft_atof(data_strs[3])),
			input_color(color));
	ft_lstadd_back(&data->cylinder_list, ft_lstnew(cylinder));
	free_all((void **)cylinder_cen);
	free_all((void **)orient);
	free_all((void **)color);
}
