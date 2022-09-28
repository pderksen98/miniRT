/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/27 16:04:16 by pderksen      #+#    #+#                 */
/*   Updated: 2022/09/28 16:29:36 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)


void	init_input(t_camera *camera, t_sphere *sphere)
{
	camera->cord = (t_vec4){0,0,1};
	camera->norm = (t_vec4){0,0,1};
	camera->fov = 90;

	sphere->center = (t_vec4){2, 4, 9};
	sphere->colors = (t_vec4){0, 255, 255};
	sphere->d = 3;
}


int	main(void)
{
	t_screen	screen;
	t_camera	camera;
	t_sphere	sphere;

	screen.mlx = mlx_init();
	screen.win = mlx_new_window(screen.mlx, S_WIDTH, S_HEIGHT, "test");
	screen.img.img = mlx_new_image(screen.mlx, S_WIDTH, S_HEIGHT);
	screen.img.addr = mlx_get_data_addr(screen.img.img, &screen.img.bits_per_pixel, \
										&screen.img.line_length, &screen.img.endian);
	
	// push_pixels(&screen.img);
	init_input(&camera, &sphere);
	ray_trace(&screen.img, &camera, &sphere);
	mlx_put_image_to_window(screen.mlx, screen.win, screen.img.img, 0, 0);
	mlx_loop(screen.mlx);
	return (0);
}
