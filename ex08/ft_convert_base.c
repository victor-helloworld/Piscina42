/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c       		                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcollazo <vcollazo@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:52:39 by vcollazo          #+#    #+#             */
/*   Updated: 2021/08/21 16:54:32 by vcollazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_encodenbr_base(int nbr, char *base, char *nb_dest);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_len(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

int	ft_base_iserror(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i])
	{
		if (str[i] < 48)
			return (1);
		while (str[i + j])
		{
			if (str[i + j] == str[i])
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}

//int	ft_int_iserror(int nb)
//{
//	if (nb > 2147483647)
//		return (1);
//	else if (nb < -2147483648)
//		return (3);
//	return (0);
//}

char	*is_in_base(char *base, char *to_find)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (*to_find == base[i])
			return (base + i);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	unsigned int	nombre;
	int				signe;
	char			*charptr;

	nombre = 0;
	signe = 1;
	charptr = str;
	while (*charptr == ' ' || (*charptr >= 9 && *charptr <= 13))
		charptr++;
	while (*charptr == '-' || *charptr == '+')
	{
		if (*charptr == '-')
			signe *= -1;
		charptr++;
	}
	while (is_in_base(base, charptr))
	{
		nombre *= ft_len(base);
		nombre += (unsigned int)(is_in_base(base, charptr) - base);
		charptr++;
	}
	return (int)(nombre * signe);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb_int;
	char	*nb_converti;

	//if (ft_int_iserror(nb) || ft_base_iserror(nb))
	if (ft_base_iserror(nbr))
		return (0);
	
	nb_converti = malloc(34);
	nb_int = ft_atoi_base(nbr, base_from);
	ft_encodenbr_base(nb_int, base_to, nb_converti);
	return (nb_converti);
}
