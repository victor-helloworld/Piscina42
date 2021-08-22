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

int		ft_strlen(char *str)
{
	char	*charptr;
	int		iterator;

	charptr = str;
	iterator = 0;
	while (*charptr != 0)
	{
		iterator++;
		charptr++;
	}
	return (iterator);
}

void	strev(char *str, int offset_of_center)
{
	int		len;
	int		i;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i + offset_of_center];
		str[i + offset_of_center] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

void	ft_encodenbr_base(int nbr, char *base, char *nb_dest)
{
	unsigned int	lenbase;
	unsigned int	nbr_unsigned;
	int				i;

	i = 0;
	if (nbr < 0)
	{
		nb_dest[i++] = '-';
		nbr_unsigned = (unsigned int)(-1 * nbr);
	}
	else
		nbr_unsigned = (unsigned int)nbr;
	lenbase = ft_strlen(base);
	if (nbr_unsigned == 0)
		nb_dest[i++] = *(base);
	while (nbr_unsigned > 0)
	{
		nb_dest[i++] = *(base + (nbr_unsigned % lenbase));
		nbr_unsigned /= lenbase;
	}
	nb_dest[i] = 0;
	(nbr < 0) ? strev(nb_dest, 1) : strev(nb_dest, 0);
}
