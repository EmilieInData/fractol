/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_implementation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:58:22 by esellier          #+#    #+#             */
/*   Updated: 2024/06/12 20:47:16 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double  window_resize(double imaginary, double old_max, double new_min, double new_max)
{
	double old_min;
	
	old_min = 0;
	/*new_min = -2;
	new_max = 2;
	old_max = WIDTH;*/
	return ((new_max - new_min) * (imaginary - old_min) / (old_max - old_min) + new_min);
}
//si la fenetre fait 800 * 800 elle doit faire dans tous les cas -2 * 2 max

void	*create_fractal(int i)
{
	window_resize(i, HEIGHT, -2, 2);
	return (0);	
}