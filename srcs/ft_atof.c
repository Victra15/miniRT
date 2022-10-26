/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:47:19 by yolee             #+#    #+#             */
/*   Updated: 2022/10/26 22:00:05 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ft_isspace(const char chr)
{
	if ((chr >= '\t' && chr <= '\r')
		|| chr == ' ')
		return (1);
	else
		return (0);
}

static int	ft_issign(const char chr)
{
	if (chr == '+' || chr == '-')
		return (1);
	else
		return (0);
}

static int	ft_isoverflowed(long long *conv_num, const int sign)
{
	if (((*conv_num) * sign) < 0)
	{
		if (sign < 0)
			(*conv_num) = 0;
		else
			(*conv_num) = -1;
		return (1);
	}
	else
		return (0);
}

static double	getnum(char **iter_ptr, int sign, int *cnt)
{
	double	conv_num;

	(*cnt) = 0;
	conv_num = 0.0;
	while (ft_isdigit(**iter_ptr))
	{
		conv_num = (conv_num * 10.0) + (double)((sign) * ((**iter_ptr) - '0'));
		if (ft_isoverflowed(&conv_num, sign))
			break ;
		(*iter_ptr)++;
		(*cnt)++;
	}
}

double	ft_atof(const char *str)
{
	double		conv_num;
	int			sign;
	const char	*iter_ptr;
	int			cnt;

	sign = 1;
	conv_num = 0;
	iter_ptr = str;
	while (ft_isspace(*iter_ptr))
		iter_ptr++;
	if (ft_issign(*iter_ptr))
	{
		if ((*iter_ptr) == '-')
			sign = -1;
		iter_ptr++;
	}
	conv_num = getnum(&iter_ptr, sign, &cnt);
	if (*iter_ptr == '.')
		conv_num += getnum(&iter_ptr, sign, &cnt) / pow(10.0, (double)cnt);
	else if (*iter_ptr != '\0')
		exit_with_custom_error("invalid file.");
	if (*iter_ptr != '\0')
		exit_with_custom_error("invaild file.");
	return ((conv_num));
}
