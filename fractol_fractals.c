/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_fractals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:58:22 by esellier          #+#    #+#             */
/*   Updated: 2024/06/23 20:28:36 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	man_manage_pixel(t_data *data, int x, int y)
{
	int		i;
	int		color;
	double	d;
	t_num	z;
	t_num	c;

	i = 0;
	z.x = 0.00;
	z.y = 0.00;
	c.x = win_resize(x, WIDTH, -2, 2) * data->zoom + data->move_x;
	c.y = win_resize(y, HEIGHT, 2, -2) * data->zoom + data->move_y;
	while (i < ITERATIONS)
	{
		z = calcul(z, c);
		if ((z.x * z.x) + (z.y * z.y) > 4.00)
		{
			d = (double)i / ITERATIONS;
			color = gradient_color(d, ground_color(data), outline_color(data));
			put_pixel_image(data->image, x, y, color);
			return ;
		}
		i++;
	}
	put_pixel_image(data->image, x, y, fractal_color(data));
}

void	jul_manage_pixel(t_data *data, int x, int y)
{
	int		i;
	int		color;
	double	d;
	t_num	z;
	t_num	c;

	i = 0;
	c.x = data->julia_x;
	c.y = data->julia_y;
	z.x = win_resize(x, WIDTH, -2, 2) * data->zoom + data->move_x;
	z.y = win_resize(y, HEIGHT, 2, -2) * data->zoom + data->move_y;
	while (i < ITERATIONS)
	{
		z = calcul(z, c);
		if ((z.x * z.x) + (z.y * z.y) > 4.00)
		{
			d = (double)i / ITERATIONS;
			color = gradient_color(d, ground_color(data), outline_color(data));
			put_pixel_image(data->image, x, y, color);
			return ;
		}
		i++;
	}
	put_pixel_image(data->image, x, y, fractal_color(data));
}

t_num	calcul(t_num z, t_num c)
{
	t_num	r;

	r.x = (z.x * z.x) - (z.y * z.y) + c.x;
	r.y = 2 * z.x * z.y + c.y;
	return (r);
}

void	bur_manage_pixel(t_data *data, int x, int y)
{
	int		i;
	int		color;
	double	d;
	t_num	z;
	t_num	c;

	i = 0;
	z.x = 0.00;
	z.y = 0.00;
	c.x = win_resize(x, WIDTH, -2, 2) * data->zoom + data->move_x;
	c.y = win_resize(y, HEIGHT, 2, -2) * data->zoom + data->move_y;
	while (i < ITERATIONS)
	{
		z = calcul_b(z, c);
		if ((z.x * z.x) + (z.y * z.y) > 4.00)
		{
			d = (double)i / ITERATIONS;
			color = gradient_color(d, ground_color(data), outline_color(data));
			put_pixel_image(data->image, x, y, color);
			return ;
		}
		i++;
	}
	put_pixel_image(data->image, x, y, fractal_color(data));
}

t_num	calcul_b(t_num z, t_num c)
{
	t_num	r;

	r.x = z.x * z.x - z.y * z.y + c.x;
	r.y = fabs(2 * z.x * z.y) + c.y;
	return (r);
}
