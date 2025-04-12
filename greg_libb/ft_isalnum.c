/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:21:36 by zamohame          #+#    #+#             */
/*   Updated: 2024/11/12 11:11:18 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int a)
{
	return (((a >= 48) && (a <= 57))
		|| (((a >= 65) && (a <= 90))
			|| ((a >= 97 && (a <= 122)))));
}
/*
int	main(void)
{
	int	n;

	n = 5;
	printf("%d", ft_isalnum(n));
}
*/
