/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:28:50 by esellier          #+#    #+#             */
/*   Updated: 2024/06/23 20:28:20 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	do_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_escape(data);
	if (keysym == XK_Up)
		data->move_y = data->move_y + 0.3 * data->zoom;
	if (keysym == XK_Down)
		data->move_y = data->move_y - 0.3 * data->zoom;
	if (keysym == XK_Left)
		data->move_x = data->move_x - 0.3 * data->zoom;
	if (keysym == XK_Right)
		data->move_x = data->move_x + 0.3 * data->zoom;
	if (keysym == XK_Tab)
	{
		if (data->range == 4)
			data->range = 0;
		else
			data->range = data->range + 1;
	}
	create_fractal(data);
	return (0);
}

int	do_mouse(int button, int x, int y, t_data *data)
{
	double	d_x;
	double	d_y;
	double	zoom;

	d_x = ((double)x * 4 / WIDTH - 2) * data->zoom + data->move_x;
	d_y = ((double)y * 4 / HEIGHT - 2) * data->zoom + data->move_y;
	if (button == Button5)
		zoom = 1.10;
	if (button == Button4)
		zoom = 0.90;
	data->move_x = data->move_x + (d_x - data->move_x) * (1 - zoom);
	data->move_y = data->move_y + (d_y - data->move_y) * (1 - zoom);
	data->zoom = data->zoom * zoom;
	create_fractal(data);
	return (0);
}

void	init_events(t_data *data)
{
	mlx_key_hook(data->window, do_key, data);
	mlx_hook(data->window, 17, (1L << 5), close_escape, data);
	mlx_mouse_hook(data->window, do_mouse, data);
}

int	close_escape(t_data *data)
{
	mlx_destroy_image(data->init, data->image->img_add);
	mlx_destroy_window(data->init, data->window);
	mlx_destroy_display(data->init);
	free (data->image);
	free (data);
	exit (EXIT_SUCCESS);
}
