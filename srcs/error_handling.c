/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:32:56 by yolee             #+#    #+#             */
/*   Updated: 2022/10/31 18:16:46 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_data_len(void **data)
{
	size_t	len;

	len = 0;
	while (data && *data)
	{
		data++;
		len++;
	}
	return (len);
}

void	free_all(void **data)
{
	void	**temp;

	temp = data;
	while (data && *data)
	{
		free(*data);
		data++;
	}
	free(temp);
}

void	exit_with_error(void)
{
	write(2, "Error\n", 6);
	perror("");
	exit(1);
}

void	exit_with_custom_error(char	*custom_msg)
{
	size_t	msg_len;

	msg_len = ft_strlen(custom_msg);
	write(2, "Error\n", 6);
	write(2, custom_msg, msg_len);
	write(2, "\n", 1);
	exit(1);
}

int	is_file_ext_rt(char	*f_name)
{
	size_t	f_len;

	f_len = ft_strlen(f_name);
	if (f_len >= 3
		&& (f_name[f_len - 3] == '.'
			&& f_name[f_len - 2] == 'r'
			&& f_name[f_len - 1] == 't'))
		return (1);
	else
		return (0);
}
