/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:13:47 by esellier          #+#    #+#             */
/*   Updated: 2024/06/04 18:20:31 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

int main (void)
{
	void	*ptr;
	void	*window;

	ptr = mlx_init();
	if (!ptr)
		return (1);
	window = mlx_new_window(ptr, 300, 300, "Hello World!");
	if (!window)
		return (2);
	mlx_loop(ptr);
	return(0);
}

