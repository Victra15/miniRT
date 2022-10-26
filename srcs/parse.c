/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:28:30 by yolee             #+#    #+#             */
/*   Updated: 2022/10/26 21:27:23 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parse_line(t_data *data, char *line)
{
	if (line[0] == '\n')
		return ;
	else if (ft_strncmp(line, "A", 1))
		parse_ambient_light(data, ft_split(line + 1, ' '));
	else if (ft_strncmp(line, "C", 1))
		parse_camera(data, ft_split(line + 1, ' '));
	else if (ft_strncmp(line, "L", 1))
		parse_light(data, ft_split(line + 1, ' '));
	else if (ft_strncmp(line, "pl", 2))
		parse_plane(data, ft_split(line + 1, ' '));
	else if (ft_strncmp(line, "sp", 2))
		parse_sphere(data, ft_split(line + 1, ' '));
	else if (ft_strncmp(line, "cy", 2))
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
