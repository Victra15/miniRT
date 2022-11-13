/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:25:08 by yolee             #+#    #+#             */
/*   Updated: 2022/11/13 21:45:39 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include <math.h>

typedef struct s_color3
{
	double	r;
	double	g;
	double	b;
}t_color3;

struct s_color3	c_gen(double r, double g, double b);
struct s_color3	c_sum(struct s_color3 col1, struct s_color3 col2);
struct s_color3	c_mult(struct s_color3 col1, struct s_color3 col2);
struct s_color3	c_mult_sca(struct s_color3 col1, double sca);
#endif