/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx2.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/27 16:11:15 by pderksen      #+#    #+#                 */
/*   Updated: 2022/09/30 13:49:42 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX2_H
# define MLX2_H
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "rays.h"

// # define S_WIDTH 1920
// # define S_HEIGHT 1080

//MLX
typedef struct s_color
{
	float	red;
	float	green;
	float	blue;	
}	t_color;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x0;
}	t_data;

typedef struct s_screen
{
	void		*mlx;
	void		*win;
	t_data		img;
}	t_screen;

#endif