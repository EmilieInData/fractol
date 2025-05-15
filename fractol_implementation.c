/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_implementation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:58:22 by esellier          #+#    #+#             */
/*   Updated: 2024/06/23 18:19:04 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	win_resize(double imgy, double old_max, double new_min, double new_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min)
		* (imgy - old_min) / (old_max - old_min) + new_min);
}

void	*create_fractal(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (ft_strncmp (data->name, "Julia", 5) == 0)
				jul_manage_pixel(data, x, y);
			if (ft_strncmp (data->name, "Mandelbrot", 10) == 0)
				man_manage_pixel(data, x, y);
			if (ft_strncmp (data->name, "Burningship", 11) == 0)
				bur_manage_pixel(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->init, data->window,
		data->image->img_add, 0, 0);
	return (0);
}

void	*implementation_struct(t_data *data, char *name)
{
	data->init = mlx_init();
	if (!data->init)
		data_free(data);
	data->window = mlx_new_window(data->init, WIDTH, HEIGHT, name);
	if (!data->window)
		data_free(data);
	data->image->img_add = mlx_new_image(data->init, WIDTH, HEIGHT);
	if (!data->image->img_add)
		data_free(data);
	data->image->pix_add = mlx_get_data_addr(data->image->img_add, &data->image
			->bit_pix, &data->image->length_line, &data->image->endian);
	init_events(data);
	return (0);
}

void	put_pixel_image(t_img *image, int x, int y, int color)
{
	int	tmp;

	tmp = (y * image->length_line) + (x * (image->bit_pix / 8));
	*(unsigned int *)(image->pix_add + tmp) = color;
}

void	*data_free(t_data *data)
{
	if (data)
	{
		if (data->image->img_add)
			mlx_destroy_image(data->init, data->image->img_add);
		if (data->window)
			mlx_destroy_window(data->init, data->window);
		if (data->init)
			mlx_destroy_display(data->init);
		if (data->image)
			free (data->image);
		free (data);
	}
	exit (EXIT_FAILURE);
}
