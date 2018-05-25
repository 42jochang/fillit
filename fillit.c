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
	ft_putstr(board);
	free(board);
}

int		find_starting_square(int np)
{
	int		i;

	i = 2;
	while (i * i < np * 4)
		i++;
	return (i);
}

char	*malloc_board(size_t arr_size)
{
	char	*start;
	char	*ptr;
	size_t	len;
	size_t	i;
	size_t	row;

	i = 0;
	row = 1;
	len = arr_size * arr_size + arr_size;
	if (!(start = (char*)malloc(len + 1)))
		return (NULL);
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

int		valid_spot(t_tet *pieces, char *board, int row_size, int i)
{
	int		k;
	int		start_row;
	int		next_place;
	int		count;

	k = 0;
	start_row = 0;
	count = 0;
	while (count < 4)
	{
		if (pieces->data[k] == -1)
			start_row++;
		else
		{
			next_place = pieces->data[k] + i + (start_row * (row_size - 4));
			if (board[next_place] != '.')
				return (0);
			count++;
		}
		k++;
	}
	return (1);
}

int		place_pieces(t_tet *pieces, char *board, int row_size, int piece_num)
{
	int		found;
	int		ints[3];

	ints[0] = 0;
	found = 0;
	ints[1] = row_size;
	ints[2] = piece_num;
	if (!pieces)
		return (1);
	while (board[ints[0]] && !found)
	{
		if (valid_spot(pieces, board, row_size, ints[0]))
		{
			add_piece(pieces, board, ints);
			if ((found = place_pieces(pieces->next, board,
				row_size, piece_num + 1)))
				return (1);
			remove_piece(pieces, board, ints[0], row_size);
		}
		ints[0]++;
	}
	return (0);
}
