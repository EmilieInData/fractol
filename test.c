/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:13:47 by esellier          #+#    #+#             */
/*   Updated: 2024/06/13 18:11:46 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "mlx/mlx.h"

/*int main (void)
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
} */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*int main()
{
	int r;
	char * test= "-24j21";

	r = atoi(test);
	printf("%d\n", r);
	return (0);
}*/


/*int main()
{
	double r;
	
	const char *str = "-248+65854565625";
	r = atoi_double(str);
	printf("%f\n", r);
	return(0);
}*/

double  window_resize(double imaginary, double old_max, double new_min, double new_max)
{
	double old_min;
	
	old_min = 0;
	return ((new_max - new_min) * (imaginary - old_min) / (old_max - old_min) + new_min);
}

int main()	
{
	int i = 0;
	
	while (i < 800)
	{
		printf("%d->%f\n", i , window_resize(i, 799, -2 , 2));
		i++;
	}
	return (0);
}
