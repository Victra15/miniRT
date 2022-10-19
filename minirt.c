/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:58:44 by yolee             #+#    #+#             */
/*   Updated: 2022/10/19 23:40:08 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	mlx_exit(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	exit(0);
	return (0);
}

static void	mlx_window_set(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "miniRT");
}

static void	mlx_image_set(t_data *data)
{
	t_pos	pos;

	data->img.img = mlx_new_image(data->mlx.mlx, 1920, 1080);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel,
			&data->img.line_length,
			&data->img.endian);
	pos.y = 0;
	while (pos.y < WINDOW_HEIGHT)
	{
		pos.x = 0;
		if(pos.y == 960)
			printf("aaa");
		while (pos.x < WINDOW_WIDTH)
		{
			trace_ray(data, pos);
			pos.x++;
		}
		pos.y++;
	}
	mlx_put_image_to_window(data->mlx.mlx,
		data->mlx.mlx_win,
		data->img.img,
		0, 0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	if (argc != 2)
		write(2, "Error\n", 6);
	else
	{
		// parse_data(&data, argv[1]);
		mlx_window_set(&data.mlx);
		mlx_image_set(&data);
		mlx_hook(data.mlx.mlx_win, 17, 0, mlx_exit, NULL);
		mlx_loop(data.mlx.mlx);
	}
	return (0);
}
