/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_dif_fractals.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:58:22 by esellier          #+#    #+#             */
/*   Updated: 2024/06/19 20:16:49 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	man_manage_pixel(t_data *data, int x, int y)
{
	int		i;
	//int	color;
	
	t_num	z;
	t_num	c;

	i = 0;
	z.x = 0.00;
	z.y = 0.00;
	c.x = window_resize(x, WIDTH, -2, 2) * data->zoom + data->move_x;
	c.y = window_resize(y, HEIGHT, 2, -2) * data->zoom + data->move_y;
	while (i < data->def_iterations)
	{
		z = calcul_m(z, c);
		if ((z.x * z.x) + (z.y * z.y) > data->outside_fractal)
		{
			//color= window_resize(i, data->def_iterations, BLACK, WHITE);
			mlx_pixel_put(data->init, data->window, x, y, PASTEL_BLUE);
			return;
		}
		i++;
	}
	mlx_pixel_put(data->init, data->window, x, y, PASTEL_YELLOW);
	//dans la fractal
}

void	jul_manage_pixel(t_data *data, int x, int y)
{
	int		i;
	int	color;
	
	t_num	z;
	t_num	c;

	i = 0;
	c.x = data->julia_x;
	c.y = data->julia_y;
	z.x = window_resize(x, WIDTH, -2, 2) * data->zoom + data->move_x;
	z.y = window_resize(y, HEIGHT, 2, -2) * data->zoom + data->move_y;
	while (i < data->def_iterations)
	{
		z = calcul_m(z, c);
		if ((z.x * z.x) + (z.y * z.y) > data->outside_fractal)
		{
			color= window_resize(i, data->def_iterations, PASTEL_BLUE, PASTEL_GRAY);
			put_pixel_image(data->image, x, y, color);
			//mlx_pixel_put(data->init, data->window, x, y, PASTEL_BLUE);
			return;
		}
		i++;
	}
	put_pixel_image(data->image, x, y, PASTEL_YELLOW);
	//mlx_pixel_put(data->init, data->window, x, y, PASTEL_YELLOW);
	//dans la fractal
}


