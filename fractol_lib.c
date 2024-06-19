/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_lib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:38:02 by esellier          #+#    #+#             */
/*   Updated: 2024/06/19 17:28:35 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    put_pixel_image(t_data *data, int x, int y, int color)
{
    color = data->image->pix_add + (y * data->image->length_line + x * (data->image->bit_pix / 8));
    //color= window_resize(i, data->def_iterations, BLACK, WHITE);
	//mlx_pixel_put(data->init, data->window, x, y, PASTEL_BLUE);
}
//mettre ls pixels sur une image et (ailleurs) envoyer l'image sur la fenêtre