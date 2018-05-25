/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 23:57:29 by jochang           #+#    #+#             */
/*   Updated: 2018/05/18 23:59:02 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	get_piece(int piece_num)
{
	return (64 + piece_num);
}

void	add_piece(t_tet *pieces, char *board, int ints[3])
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

void	remove_piece(t_tet *pieces, char *board, int i, int row_size)
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
