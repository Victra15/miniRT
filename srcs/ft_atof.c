/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:47:19 by yolee             #+#    #+#             */
/*   Updated: 2022/10/31 20:53:52 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ft_issign(const char chr)
{
	if (chr == '+' || chr == '-')
		return (1);
	else if (!ft_isdigit(chr))
	{
		exit_with_custom_error("string is not number.");
		return (0);
	}
	else
		return (0);
}

static int	ft_isoverflowed(double *conv_num, const int sign)
{
	if (((*conv_num) * (double)sign) < 0)
	{
		if (sign < 0)
			(*conv_num) = 0.0;
		else
			(*conv_num) = -1.0;
		return (1);
	}
	else
		return (0);
}

static double	getnum(const char **iter_ptr, int sign, int *cnt)
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
	return (conv_num);
}

double	ft_atof(const char *str)
{
	double		conv_num;
	int			sign;
	const char	*iter_ptr;
	int			cnt;

	sign = 1;
	conv_num = 0;
	if (!str)
		exit_with_custom_error("string is null.");
	iter_ptr = str;
	if (ft_issign(*iter_ptr))
	{
		if ((*iter_ptr) == '-')
			sign = -1;
		iter_ptr++;
	}
	conv_num = getnum(&iter_ptr, sign, &cnt);
	if (*iter_ptr == '.' && ft_isdigit(*(iter_ptr + 1)) && iter_ptr++)
		conv_num += getnum(&iter_ptr, sign, &cnt) / pow(10.0, (double)cnt);
	else if (*iter_ptr != '\0' && *iter_ptr != '\n')
		exit_with_custom_error("string is not number.");
	if (*iter_ptr != '\0' && *iter_ptr != '\n')
		exit_with_custom_error("string is not number.");
	return ((conv_num));
}
