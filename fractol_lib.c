/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_lib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:38:02 by esellier          #+#    #+#             */
/*   Updated: 2024/06/18 14:00:29 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    put_pixel_image(t_data *data, int x, int y, int color)
{
    data->image->img_add = mlx_new_image(data->init, WIDTH, HEIGHT);
    data->image->pix_add = mlx_get_data_addr(data->image, &data->image->bit_pix, &data->image->length_line, &data->image->endian);
    //resize l'image?
    //color= window_resize(i, data->def_iterations, BLACK, WHITE);
	mlx_pixel_put(data->init, data->window, x, y, PASTEL_BLUE);
    color = (y * line_length + x * (bits_per_pixel / 8));


    return ;
}
//mettre ls pixels sur une image et (ailleurs) envoyer l'image sur la fenêtre