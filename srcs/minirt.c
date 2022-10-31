/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:58:44 by yolee             #+#    #+#             */
/*   Updated: 2022/10/31 15:52:01 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	mlx_exit(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx, data->img.img);
	mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	exit(0);
	return (0);
}

static int	mlx_key_exit(int keycode, t_data *data)
{
	if (keycode == KEYCODE_ESC)
	{
		mlx_destroy_image(data->mlx.mlx, data->img.img);
		mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
		exit(0);
	}
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

	data->img.img = mlx_new_image(data->mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel,
			&data->img.line_length,
			&data->img.endian);
	pos.y = 0;
	while (pos.y < WINDOW_HEIGHT)
	{
		pos.x = 0;
		while (pos.x < WINDOW_WIDTH)
		{
			// trace_ray(data, pos);
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
		exit_with_custom_error("invalid argument number.");
	else
	{
		if (is_file_ext_rt(argv[1]))
			parse_data(&data, argv[1]);
		else
			exit_with_custom_error("invalid filename.");
		parse_test_print(&data);
		// mlx_window_set(&data.mlx);
		// mlx_image_set(&data);
		// mlx_hook(data.mlx.mlx_win, 17, 0, mlx_exit, &data);
		// mlx_key_hook(data.mlx.mlx_win, mlx_key_exit, &data);
		// mlx_loop(data.mlx.mlx);
	}
	return (0);
}
