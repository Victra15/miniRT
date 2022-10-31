/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:29:05 by yolee             #+#    #+#             */
/*   Updated: 2022/10/31 16:06:30 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_camera(t_data *data, char **data_strs)
{
	char		**view_point;
	char		**orient;

	if (ft_data_len((void **)data_strs) != 3)
		exit_with_custom_error("invalid file.");
	view_point = ft_split(data_strs[0], ',');
	if (ft_data_len((void **)view_point) != 3)
		exit_with_custom_error("invalid file.");
	orient = ft_split(data_strs[1], ',');
	if (ft_data_len((void **)orient) != 3)
		exit_with_custom_error("invalid file.");
	data->camera = camera_gen(v_gen(ft_atof(view_point[0]),
				ft_atof(view_point[1]),
				ft_atof(view_point[2])),
			v_unit(v_gen(ft_atof(orient[0]),
					ft_atof(orient[1]),
					ft_atof(orient[2]))),
			ft_atof(data_strs[2]));
	free_all((void **)orient);
	free_all((void **)view_point);
	free_all((void **)data_strs);
	return ;
}

void	parse_light(t_data *data, char **data_strs)
{
	char	**light_point;

	if (ft_data_len((void **)data_strs) != 2)
		exit_with_custom_error("invalid file.");
	light_point = ft_split(data_strs[1], ',');
	if (ft_data_len((void **)light_point) != 3)
		exit_with_custom_error("invalid file.");
	data->light = light_gen(v_gen(ft_atof(light_point[0]),
				ft_atof(light_point[1]),
				ft_atof(light_point[2])),
			ft_atof(data_strs[0]));
	free_all((void **)light_point);
	free_all((void **)data_strs);
	return ;

}

void	parse_sphere(t_data *data, char **data_strs)
{
	char		**color;

	if (ft_data_len((void **)data_strs) != 2)
		exit_with_custom_error("invalid file.");
	color = ft_split(data_strs[1], ',');
	if (ft_data_len((void **)color) != 3)
		exit_with_custom_error("invalid file.");
	data->am_light.ratio = ft_atof(data_strs[0]);
	data->am_light.color = v_gen(ft_atof(color[0]) / 255.0,
			ft_atof(color[1]) / 255.0,
			ft_atof(color[2]) / 255.0);
	printf("\n%lf \n", ft_atof(data_strs[0]));
	free_all((void **)color);
	free_all((void **)data_strs);
	return ;
}

void	parse_plane(t_data *data, char **data_strs)
{
	char		**color;

	if (ft_data_len((void **)data_strs) != 2)
		exit_with_custom_error("invalid file.");
	color = ft_split(data_strs[1], ',');
	if (ft_data_len((void **)color) != 3)
		exit_with_custom_error("invalid file.");
	data->am_light.ratio = ft_atof(data_strs[0]);
	data->am_light.color = v_gen(ft_atof(color[0]) / 255.0,
			ft_atof(color[1]) / 255.0,
			ft_atof(color[2]) / 255.0);
	printf("\n%lf \n", ft_atof(data_strs[0]));
	free_all((void **)color);
	free_all((void **)data_strs);
	return ;
}


void	parse_cylinder(t_data *data, char **data_strs)
{
	char		**color;

	if (ft_data_len((void **)data_strs) != 2)
		exit_with_custom_error("invalid file.");
	color = ft_split(data_strs[1], ',');
	if (ft_data_len((void **)color) != 3)
		exit_with_custom_error("invalid file.");
	data->am_light.ratio = ft_atof(data_strs[0]);
	data->am_light.color = v_gen(ft_atof(color[0]) / 255.0,
			ft_atof(color[1]) / 255.0,
			ft_atof(color[2]) / 255.0);
	printf("\n%lf \n", ft_atof(data_strs[0]));
	free_all((void **)color);
	free_all((void **)data_strs);
	return ;
}
