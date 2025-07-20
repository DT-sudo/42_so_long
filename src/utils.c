/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:30:05 by dt                #+#    #+#             */
/*   Updated: 2025/07/19 17:51:30 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	drop_error_ext(int error_num, char *error_message, char **map)
{
	if (map)
		free_map(map);
	perror(error_message);
	exit(error_num);
}

int	catch_nl(char *buf, size_t size)
{
	size_t	n;
	int	c;

	if(!buf)
		drop_error_ext(INVALID_POINTER, "Error: invalid pinter.\n", NULL);
	n = 0;
	c = 0;
	while (n < size)
	{
		if (buf[n] == '\n')
			c++;
		n++;
	}
	return (c);
}

void	free_map(char **map)
{
	char	**tmp;

	if (!map)
		return;
	tmp = map;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(map);
}

