/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 19:42:51 by jochang           #+#    #+#             */
/*   Updated: 2018/05/25 13:50:03 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_block(int *block)
{
	if (block[1] == 1)
	{
		if (block[2] == 2)
			return (second_h_block(block));
		else if (block[2] == -1)
			return (third_h_block(block));
	}
	else if (block[1] == -1)
	{
		if (block[2] == 3 && block[3] == 4 && block[4] == 5)
			return (11);
		else if (block[2] == 4 && block[3] == 5)
			return (second_v_block(block));
		else if (block[2] == 5)
			return (third_v_block(block));
	}
	return (0);
}

int		second_h_block(int *block)
{
	if (block[3] == 3)
		return (3);
	else if (block[3] == -1)
	{
		if (block[4] == 5)
			return (9);
		else if (block[4] == 6)
			return (14);
		else if (block[4] == 7)
			return (19);
	}
	return (0);
}

int		third_h_block(int *block)
{
	if (block[3] == 4 && block[4] == 5)
		return (4);
	else if (block[3] == 5)
	{
		if (block[4] == 6)
			return (1);
		else if (block[4] == -1 && block[5] == 10)
			return (18);
	}
	else if (block[3] == 6)
	{
		if (block[4] == 7)
			return (6);
		else if (block[4] == -1 && block[5] == 11)
			return (10);
	}
	return (0);
}

int		second_v_block(int *block)
{
	if (block[4] == 6)
		return (12);
	else if (block[4] == -1)
	{
		if (block[5] == 9)
			return (7);
		else if (block[5] == 10)
			return (15);
	}
	return (0);
}

int		third_v_block(int *block)
{
	if (block[3] == -1)
	{
		if (block[4] == 10)
		{
			if (block[5] == -1 && block[6] == 15)
				return (2);
			else if (block[5] == 11)
				return (8);
		}
		else if (block[4] == 9 && block[5] == 10)
			return (16);
	}
	else if (block[3] == 6)
	{
		if (block[4] == -1)
		{
			if (block[5] == 11)
				return (5);
			else if (block[5] == 10)
				return (13);
		}
		else if (block[4] == 7)
			return (17);
	}
	return (0);
}
