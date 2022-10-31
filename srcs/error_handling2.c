/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:16:29 by yolee             #+#    #+#             */
/*   Updated: 2022/10/31 20:19:33 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	input_checker(void **strs, int data_len, char *err_str)
{
	if (ft_data_len(strs) != data_len)
		exit_with_custom_error(err_str);
}

void	data_ptr_init(t_data *data)
{
	data->sphere_list = NULL;
	data->plane_list = NULL;
	data->cylinder_list = NULL;
}
