/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/27 16:04:16 by pderksen      #+#    #+#                 */
/*   Updated: 2022/09/30 15:36:59 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

void	init_input(t_camera *camera, t_sphere *sphere, t_plane *plane)
{
	camera->cord = (t_vec4){0,0.9,0};
	camera->norm = (t_vec4){0,0,-1};
	camera->fov = 70;

	sphere->center = (t_vec4){0, 0, -30};
	sphere->color = (t_vec4){255, 165, 0};
	sphere->d = 5;

	plane->cord = (t_vec4){0, 2, 0};
	plane->norm = (t_vec4){0, 1, 0};
	plane->color = (t_vec4){0, 100, 255};
}


int	main(void)
{
	t_screen	screen;
	t_camera	camera;
	t_sphere	sphere;
	t_plane		plane;

	screen.mlx = mlx_init();
	screen.win = mlx_new_window(screen.mlx, S_WIDTH, S_HEIGHT, "test");
	screen.img.img = mlx_new_image(screen.mlx, S_WIDTH, S_HEIGHT);
	screen.img.addr = mlx_get_data_addr(screen.img.img, &screen.img.bits_per_pixel, \
										&screen.img.line_length, &screen.img.endian);
	init_input(&camera, &sphere, &plane);
	ray_trace(&screen.img, &camera, &sphere, &plane);
	mlx_put_image_to_window(screen.mlx, screen.win, screen.img.img, 0, 0);
	mlx_loop(screen.mlx);
	return (0);
}
