/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_manage_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:22:48 by esellier          #+#    #+#             */
/*   Updated: 2024/06/23 20:09:44 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ground_color(t_data *data)
{
	int	array[5];

	array[0] = PASTEL_BLUE;
	array[1] = BLACK;
	array[2] = WHITE;
	array[3] = PASTEL_GRAY;
	array[4] = PASTEL_RED;
	return (array[data->range]);
}

int	outline_color(t_data *data)
{
	int	array[5];

	array[0] = PASTEL_PINK;
	array[1] = PASTEL_GREEN;
	array[2] = PASTEL_PURPLE;
	array[3] = go_darker(PASTEL_GRAY);
	array[4] = PASTEL_YELLOW;
	return (array[data->range]);
}

int	fractal_color(t_data *data)
{
	int	array[5];

	array[0] = PASTEL_YELLOW;
	array[1] = WHITE;
	array[2] = BLACK;
	array[3] = PASTEL_PURPLE;
	array[4] = PASTEL_ORANGE;
	return (array[data->range]);
}
