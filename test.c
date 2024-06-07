/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:13:47 by esellier          #+#    #+#             */
/*   Updated: 2024/06/07 16:16:01 by esellier         ###   ########.fr       */
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
}*/
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

/*double	ft_atoi(const char *str)
{
	int	i;
	double	r;
	double	m;

	i = 0;
	m = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == 45)
	{
		m = -1;
		i++;
	}
	if (str[i] == 43 && m != -1)
	{
		i++;
	}
	r = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (m * r);
}*/

int main()
{
	double r;
	
	const char *str = "-248+65854565625";
	r = atoi_double(str);
	printf("%f\n", r);
	return(0);
}

