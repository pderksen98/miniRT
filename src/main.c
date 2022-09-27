/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/27 16:04:16 by pderksen      #+#    #+#                 */
/*   Updated: 2022/09/27 17:11:47 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	main(void)
{
	t_screen screen;

	screen.mlx = mlx_init();
	screen.win = mlx_new_window(screen.mlx, S_WIDTH, S_HEIGHT, "test");
	screen.img.img = mlx_new_image(screen.mlx, S_WIDTH, S_HEIGHT);
	screen.img.addr = mlx_get_data_addr(screen.img.img, &screen.img.bits_per_pixel, \
										&screen.img.line_length, &screen.img.endian);
	push_pixels(&screen.img);
	mlx_put_image_to_window(screen.mlx, screen.win, screen.img.img, 0, 0);
	mlx_loop(screen.mlx);
	return (0);
}
