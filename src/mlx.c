/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/27 16:26:26 by pderksen      #+#    #+#                 */
/*   Updated: 2022/09/28 11:16:10 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

//converts rgb values in range [0,1] to int value for mlx
// int	convert_rgb_to_int(float red, float green, float blue)
// {
// 	int		result;
// 	float	r;
// 	float	g;
// 	float	b;

// 	r = (255 * red) * 256 * 256;
// 	g = (255 * green) * 256;
// 	b = blue;
// 	result = (int)(r + g + b);
// 	return (result);
// }

int	convert_3_to_1(float red, float green, float blue)
{
	int	result;
	int	r;
	int	g;
	int	b;

	r = (int)red;
	g = (int)green;
	b = (int)blue;
	result = ((256 * 256 * r) + (256 * g) + b);
	return (result);
}


//Puts pixel in input 'color' to the window on place x, y
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < S_WIDTH) && (y >= 0 && y < S_HEIGHT))
	{
		 dst = data->addr + (y * data->line_length + \
		 	 x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	make_line(t_data *img, int y)
{
	int		x;
	int		color;
	float	red;
	float	green;
	float	blue;
	
	x = 0;
	while (x < S_WIDTH)
	{
		red = ((float)x / S_WIDTH) * 255;
		green = 255 - (((float)x / S_WIDTH) * 255);
		blue = ((float)y / S_HEIGHT) * 255;
		color = convert_3_to_1(red, green, blue);
		my_mlx_pixel_put(img, x, y, color);
		x++;
	}
}

void	push_pixels(t_data *img)
{
	int	y;

	y = 0;
	while (y < S_HEIGHT)
	{
		make_line(img, y);
		y++;
	}
}