/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:28:30 by yolee             #+#    #+#             */
/*   Updated: 2022/10/31 20:50:30 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambient_light(t_data *data, char **data_strs)
{
	char		**color;

	input_checker((void **)data_strs, 2, "invalid ambient light input.");
	color = ft_split(data_strs[1], ',');
	input_checker((void **)color, 3, "invalid ambient light color input.");
	data->am_light = ambient_light_gen(input_ratio(data_strs[0]),
			input_color(color));
	free_all((void **)color);
	free_all((void **)data_strs);
}

static void	parse_line(t_data *data, char *line)
{
	if (line[0] == '\n')
		return ;
	else if (ft_strncmp(line, "A ", 2) == 0)
		parse_ambient_light(data, ft_split(line + 1, ' '));
	else if (ft_strncmp(line, "C ", 2) == 0)
		parse_camera(data, ft_split(line + 1, ' '));
	else if (ft_strncmp(line, "L ", 2) == 0)
		parse_light(data, ft_split(line + 1, ' '));
	else if (ft_strncmp(line, "pl ", 3) == 0)
		parse_plane(data, ft_split(line + 2, ' '));
	else if (ft_strncmp(line, "sp ", 3) == 0)
		parse_sphere(data, ft_split(line + 2, ' '));
	else if (ft_strncmp(line, "cy ", 3) == 0)
		parse_cylinder(data, ft_split(line + 2, ' '));
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
