/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:32:22 by esellier          #+#    #+#             */
/*   Updated: 2024/06/23 18:13:50 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	atoi_errors(char c)
{
	if (c == ',')
	{
		write(STDERR_FILENO, "Error, please use \".\" instead of \",\"\n", 37);
		exit(EXIT_FAILURE);
	}
	if (c && (c < '0' || c > '9'))
	{
		write(STDERR_FILENO, "Use numbers or floating-numbers only\n", 37);
		exit (EXIT_FAILURE);
	}
	return ;
}

double	atoi_calcul(const char *str, double r, int *i, int j)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		r = (r * 10) + str[*i] - '0';
		(*i)++;
	}
	if ((j == 1 && r > 2) || (j == 3 && r != 0))
	{
		write(STDERR_FILENO, "Julia's position limits are -2.00 +2.00\n", 40);
		exit(EXIT_FAILURE);
	}
	return (r);
}

double	atoi_double(const char *str, int i)
{
	double	r;
	double	r2;
	double	sign;

	r = 0;
	r2 = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == 45)
		sign = -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	r = atoi_calcul(str, r, &i, 1);
	if (str[i] == '.')
		i++;
	if (r == 2)
		r2 = atoi_calcul(str, r2, &i, 3);
	else
		r2 = atoi_calcul(str, r2, &i, 2);
	atoi_errors(str[i]);
	while (r2 > 1)
		r2 = r2 / 10;
	return ((r + r2) * sign);
}
