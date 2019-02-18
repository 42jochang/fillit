/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 23:57:29 by jochang           #+#    #+#             */
/*   Updated: 2018/05/18 23:59:02 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	valid_spot(t_tet *pieces, char *board, int row_size, int i)
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

static char	get_piece(int piece_num)
{
	return (64 + (piece_num % 27));
}

static void	add_piece(t_tet *pieces, char *board, int ints[3])
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
			next_place = pieces->data[k] + ints[0]
				+ (start_row * (ints[1] - 4));
			board[next_place] = get_piece(ints[2]);
			count++;
		}
		k++;
	}
}

static void	remove_piece(t_tet *pieces, char *board, int i, int row_size)
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
			if (board[next_place] && board[next_place] != '\n')
				board[next_place] = '.';
			count++;
		}
		k++;
	}
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
