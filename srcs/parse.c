/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:28:30 by yolee             #+#    #+#             */
/*   Updated: 2022/10/31 15:43:01 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambient_light(t_data *data, char **data_strs)
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
}

static void	parse_line(t_data *data, char *line)
{
	if (line[0] == '\n')
		return ;
	else if (ft_strncmp(line, "A", 1) == 0)
		parse_ambient_light(data, ft_split(line + 1, ' '));
	else if (ft_strncmp(line, "C", 1) == 0)
		parse_camera(data, ft_split(line + 1, ' '));
	else if (ft_strncmp(line, "L", 1) == 0)
		parse_light(data, ft_split(line + 1, ' '));
	else if (ft_strncmp(line, "pl", 2) == 0)
		parse_plane(data, ft_split(line + 1, ' '));
	else if (ft_strncmp(line, "sp", 2) == 0)
		parse_sphere(data, ft_split(line + 1, ' '));
	else if (ft_strncmp(line, "cy", 2) == 0)
		parse_cylinder(data, ft_split(line + 1, ' '));
	else
		exit_with_custom_error("invalid file.");
}

void	parse_data(t_data *data, char *filename)
{
	int		fd;
	char	*line;

	(void)data;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_with_error();
	else
	{
		line = get_next_line(fd);
		while (line)
		{
			parse_line(data, line);
			line = get_next_line(fd);
		}
	}
	return ;
}
