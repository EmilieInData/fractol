/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:32:22 by esellier          #+#    #+#             */
/*   Updated: 2024/06/07 16:56:14 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	atoi_errors(char c)
{
	if (c == ',')
	{
		write(2,"Error, please use \".\" instead of \",\"\n", 37);
		exit(1);
	}
	if (c && (c < '0' || c > '9'))
	{
		write(2,"Error, please use floating-point numbers only\n", 46);
		exit (1);
	}
	return;
}

double    atoi_calcul(const char *str, double r, int *i)
{
    while (str[*i] >= '0' && str[*i] <= '9')
	{
		r = (r * 10) + str[*i] -'0'; 
		(*i)++;
	}
    return (r);
}

double  atoi_double(const char *str)
{
	int	i;
	double sign;
	double	r;
	double	r2;
	
	r = 0;
    r2 = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
    r = atoi_calcul(str, r, &i);
	if (str[i] == '.')
		i++;
    r2 = atoi_calcul(str, r2, &i);
 	atoi_errors(str[i]);
	while (r2 > 1)
		r2 = r2 / 10;
	return ((r + r2) * sign);
}

/*int main()
{
	double r;
	
	const char *str = "-25.4865858565625";
	r = atoi_double(str);
	printf("%f\n", r);
	return(0);
}*/