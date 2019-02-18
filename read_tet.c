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

static int	check_count(int *block, char *arr)
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
			ZERO_CHECK(arr[i] != '\n');
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

static int	*trim_out(int *arr)
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
	NULL_CHECK(!(new = (int*)ft_memalloc(sizeof(int) * (l - i + 1))));
	while (i <= l)
	{
		new[k] = arr[i];
		k++;
		i++;
	}
	free(arr);
	return (new);
}

static int 	valid_block(int *b)
{
	if (b[1] == 1)
		return ((b[2] == 2 && b[3] == 3) ||
				(b[2] == 2 && b[4] == 5) ||
				(b[2] == 2 && b[4] == 6) ||
				(b[2] == 2 && b[4] == 7) ||
				(b[3] == 4 && b[4] == 5) ||
				(b[3] == 5 && b[4] == 6) ||
				(b[3] == 5 && b[5] == 10)||
				(b[3] == 6 && b[4] == 7) ||
				(b[3] == 6 && b[5] == 11));
	return ((b[2] == 3 && b[3] == 4 && b[4] == 5) ||
			(b[2] == 4 && b[3] == 5 && b[4] == 6) ||
			(b[2] == 4 && b[3] == 5 && b[5] == 9) ||
			(b[2] == 4 && b[3] == 5 && b[5] == 10)||
			(b[2] == 5 && b[3] == 6 && b[4] == 7) ||
			(b[2] == 5 && b[3] == 6 && b[5] == 10)||
			(b[2] == 5 && b[3] == 6 && b[5] == 11)||
			(b[2] == 5 && b[4] == 9 && b[5] == 10)||
			(b[2] == 5 && b[4] == 10&& b[5] == 11)||
			(b[2] == 5 && b[4] == 10&& b[6] == 15));
}


static int	*get_block(char *arr)
{
	int		*block;

	NULL_CHECK(!(block = (int*)ft_memalloc(sizeof(int) * 8)));
	NULL_CHECK(!(check_count(block, arr)));
	block = trim_out(block);
	return (valid_block(block) ? block : NULL);
}

t_tet	*read_tet(int fd)
{
	t_tet	*begin_tet;
	char	*arr;
	int		*block;
	char	*sep;

	NULL_CHECK(!(arr = (char*)ft_memalloc(21)) ||
				!(sep = (char*)ft_memalloc(1)));
	begin_tet = NULL;
	while (1)
	{
		NULL_CHECK(read(fd, arr, 20) != 20);
		arr[20] = '\0';
		NULL_CHECK(!(block = get_block(arr)));
		ft_list_push_back(&begin_tet, block);
		BREAK_CHECK(!(read(fd, sep, 1)));
		NULL_CHECK(sep[0] != '\n');
	}
	free(arr);
	free(sep);
	return (begin_tet);
}
