/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_create_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:22:48 by esellier          #+#    #+#             */
/*   Updated: 2024/06/23 18:09:46 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	go_darker(int trgb)
{
	double	dark;
	int		r;
	int		g;
	int		b;

	dark = 0.20;
	r = (trgb >> 16) & 0xFF;
	g = (trgb >> 8) & 0xFF;
	b = trgb & 0xFF;
	r = (int)(r * dark);
	g = (int)(g * dark);
	b = (int)(b * dark);
	return (r << 16 | g << 8 | b);
}

int	get_red(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_green(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_blue(int color)
{
	return (color & 0xFF);
}

int	gradient_color(double d, int main_color, int darker_color)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1 - d) * get_red(main_color) + d * (get_red(darker_color)));
	g = (int)((1 - d) * get_green(main_color) + d * (get_green(darker_color)));
	b = (int)((1 - d) * get_blue(main_color) + d * (get_blue(darker_color)));
	return ((r << 16) | (g << 8) | b);
}
