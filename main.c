/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:53:39 by esellier          #+#    #+#             */
/*   Updated: 2024/06/13 20:01:35 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (int argc, char **argv)
{
	t_data	*data;
	
	//data = NULL;
	check_args(argc, argv);
	create_structs(&data);
	implementation_struct(data, argv[1]);
	create_fractal(data);
	// mlx loop;
	//les hooks pour fermer les fenetres et bonus
	
	return (0);
} 

// voir pour creer des fonctions pour les erreurs et fermeture d'image?
