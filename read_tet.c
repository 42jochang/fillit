/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 11:01:31 by jochang           #+#    #+#             */
/*   Updated: 2018/05/09 19:53:26 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*read_tet(int fd)
{
	t_tet	*begin_tet;
	char	*arr;
	int		*block;
	char	*sep;

	if (!(arr = (char*)malloc(sizeof(char) * 21)) ||
		!(sep = (char*)malloc(sizeof(char) * 1)))
		return (NULL);
	begin_tet = NULL;
	while (1)
	{
		if (read(fd, arr, 20) != 20)
			return (NULL);
		arr[20] = '\0';
		if (!(block = get_block(arr)))
			return (NULL);
		ft_list_push_back(&begin_tet, block);
		if (!(read(fd, sep, 1)))
			break ;
		if (sep[0] != '\n')
			return (NULL);
	}
	free(arr);
	free(sep);
	return (begin_tet);
}

int		*get_block(char *arr)
{
	int		*block;

	if (!(block = (int*)malloc(sizeof(int) * 8)))
		return (NULL);
	if (!(check_count(block, arr)))
		return (NULL);
	block = trim_out(block);
	if (valid_block(block))
		return (block);
	return (NULL);
}

int		check_count(int *block, char *arr)
{
	int		i;
	int		b;
	t_count c;

	i = -1;
	b = -1;
	c.pc = 0;
	c.nc = 0;
	while (++i < 20)
	{
		if (!((i + 1) % 5))
		{
			if (arr[i] != '\n')
				return (0);
			block[c.pc + c.nc++] = -1;
		}
		else if (arr[i] == '#')
		{
			b = (b == -1 ? i : b);
			block[c.pc++ + c.nc] = i - b;
		}
		else if (arr[i] != '.')
			return (0);
	}
	return ((c.pc != 4 || c.nc != 4) ? 0 : 1);
}

int		*trim_out(int *arr)
{
	int i;
	int l;
	int k;
	int	*new;

	i = 0;
	l = 7;
	k = 0;
	while (arr[i] == -1)
		i++;
	while (arr[l] == -1)
		l--;
	if (!(new = (int*)malloc(sizeof(int) * (l - i + 1))))
		return (NULL);
	while (i <= l)
	{
		new[k] = arr[i];
		k++;
		i++;
	}
	free(arr);
	return (new);
}
