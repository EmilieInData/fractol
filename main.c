/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:53:39 by esellier          #+#    #+#             */
/*   Updated: 2024/06/12 20:48:55 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (int argc, char **argv)
{
	//t_num	*num;
	t_fractal	*fractal;
	t_img		*image;
	
	fractal = NULL;
	image = NULL;
	check_args(argc, argv);
	create_struct(fractal, image, argv[1]);
	//creation fractal;
	// mlx loop;
	
	return (0);
} 

// voir pour creer des fonctions pour les erreurs et fermeture d'image?
