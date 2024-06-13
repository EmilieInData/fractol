/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_implementation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:58:22 by esellier          #+#    #+#             */
/*   Updated: 2024/06/13 20:10:50 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double  window_resize(double imaginary, double old_max, double new_min, double new_max)
{
	double old_min;
	
	old_min = 0;
	return ((new_max - new_min) * (imaginary - old_min) / (old_max - old_min) + new_min);
} //si la fenetre fait 800 * 800 elle doit faire dans tous les cas -2 * 2 max

void	manage_pixel(t_data *data, int x, int y)
{
	int		i;
	int	color;
	t_num	z;
	t_num	c;

	z.x = 0.00;
	z.y = 0.00;
	
	c.x = window_resize(x, WIDTH, -2, 2);
	c.y = window_resize(y, HEIGHT, 2, -2);

	while (i < data->def_iterations)
	{
		z = calcul(z, c);
		if ((z.x * z.x) + (z.y * z.y) > data->outside_fractal)
		{
			color= window_resize(i, data->def_iterations, BLACK, WHITE);
			mlx_pixel_put(data->init, data->window, x, y, color);
			return;
		}
		i++;
	}
	//dans la fractal
	mlx_pixel_put(data->init, data->window, x, y, PASTEL_YELLOW);
}

void	*create_fractal(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			manage_pixel(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->init, data->window, data->image->img_add, 0, 0);
	return (0);	
}

void	*implementation_struct(t_data *data, char *name)
{	
	data->init = mlx_init();
	if (!data->init)
		data_free(data);
	/*{
		free (data->image);
		free (data);
		exit(EXIT_FAILURE);
	}*/
	data->window = mlx_new_window(data->init, WIDTH, HEIGHT, name);	
	if (!data->window)
		data_free(data);
	/*{
		mlx_destroy_display(data->init);
		free (data->image);
		free (data);
		exit(EXIT_FAILURE);		
	}*/
	data->image->img_add = mlx_new_image(data->init, WIDTH, HEIGHT);
	if (!data->image->img_add)
		data_free(data);
	/*{
		mlx_destroy_window(data->init, data->window);	
		mlx_destroy_display(data->init);
		free (data->image);	
		free (data);
		exit(EXIT_FAILURE);
	}*/
	data->image->pix_add = mlx_get_data_addr(data->image, &data->image->bit_pix, &data->image->length_line, &data->image->endian);
	//rempli les ints de la struc IMG et renvoie l'adresse memoire du pixel en cours
	mlx_loop(data->init);
	return (0);
}

t_num	calcul(t_num n1, t_num n2)
{
	t_num	r1;
	t_num	r2;

	r1.x = (n1.x * n1.x) - (n1.y * n1.y);
	r1.y = 2 * n1.x * n1.y;
	
	r2.x = r1.x + n2.x;
	r2.y = r1.y + n2.y;
	return (r2);
}
// n1 = z2 (ou (x2 - y2) + (2xyi) ) = r1
// n2 = c
