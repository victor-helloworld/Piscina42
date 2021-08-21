/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                 		                :+:      :+:    :+:   */
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

void	ft_str_join(char *ptr_str, int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	k;
	int	counter;

	i = -1;
	counter = -1;
	while (++i < 3)
	{
		j = -1;
		k = -1;
		while (strs[i][++j])
			ptr_str[++counter] = strs[i][j];
		while (sep[++k] && i < size - 1)
			ptr_str[++counter] = sep[k];
	}
	ptr_str[++counter] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int	nb_char;
	char	*ptr_str;

	i = -1;
	nb_char = 0;
	if (strs == NULL)
		return (0);
	while (++i < size)
		nb_char += ft_len(strs[i]) + ft_len(sep);
	nb_char += (size - 1) * ft_len(sep) + 1;
	ptr_str = (char *) malloc (nb_char * sizeof(char));
	ft_str_join(ptr_str, size, strs, sep);
	ft_putstr(ptr_str);
	return (ptr_str);
}
