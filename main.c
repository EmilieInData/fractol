/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:53:39 by esellier          #+#    #+#             */
/*   Updated: 2024/06/19 15:15:20 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (int argc, char **argv)
{
	t_data	*data;
	
	check_args(argc, argv);
	create_structs(&data, argc, argv);
	implementation_struct(data, argv[1]);
	create_fractal(data);
	mlx_loop(data->init);
		
	return (0);
} 
