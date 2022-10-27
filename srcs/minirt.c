/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:58:44 by yolee             #+#    #+#             */
/*   Updated: 2022/10/27 21:12:33 by yolee            ###   ########.fr       */
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

static void	parse_test_print(t_data *data)
{	
// 	t_camera			camera;
	printf("camera > ");
	printf("coor : (%lf, %lf, %lf), fov : (%lf), orient : (%lf, %lf, %lf)\n",
		data->camera.coor.x,
		data->camera.coor.y,
		data->camera.coor.z,
		data->camera.fov,
		data->camera.orient.x,
		data->camera.orient.y,
		data->camera.orient.z
		);
// 	t_light				light;
	printf("light > ");
	printf("coor : (%lf, %lf, %lf), ratio : (%lf), color : (%lf, %lf, %lf)\n",
		data->light.coor.x,
		data->light.coor.y,
		data->light.coor.z,
		data->light.ratio,
		data->light.color.x,
		data->light.color.y,
		data->light.color.z
		);
// 	t_ambient_light		am_light;
	printf("am_light > ");
	printf("ratio : (%lf),  color : (%lf %lf %lf)\n", 
		data->am_light.ratio,
		data->am_light.color.x,
		data->am_light.color.y,
		data->am_light.color.z
		);
// 	t_list				sphere_list;
// 	t_list				plane_list;
// 	t_list				cylinder_list;
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
