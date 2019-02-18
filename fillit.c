/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:25:08 by jochang           #+#    #+#             */
/*   Updated: 2018/05/18 23:56:49 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	find_starting_square(int np)
{
	int		i;

	i = 2;
	while (i * i < np * 4)
		i++;
	return (i);
}

static char	*malloc_board(size_t arr_size)
{
	char	*start;
	char	*ptr;
	size_t	len;
	size_t	i;
	size_t	row;

	i = 0;
	row = 1;
	len = arr_size * arr_size + arr_size;
	NULL_CHECK(!(start = (char*)ft_memalloc(len + 1)));
	ptr = start;
	while (i < len)
	{
		if (i == (arr_size + 1) * row - 1)
		{
			ptr[i] = '\n';
			row++;
		}
		else
			ptr[i] = '.';
		i++;
	}
	ptr[i] = '\0';
	return (start);
}

void	fillit(t_tet *pieces)
{
	int		arr_size;
	int		found;
	char	*board;

	arr_size = find_starting_square(ft_list_size(pieces));
	found = 0;
	while (!found)
	{
		if (!(board = (char*)malloc_board(arr_size)))
			return ;
		found = place_pieces(pieces, board, arr_size, 1);
		if (!found)
		{
			arr_size++;
			free(board);
		}
	}
	display_board(board);
	free(board);
}
