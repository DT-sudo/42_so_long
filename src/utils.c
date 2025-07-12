/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:30:05 by dt                #+#    #+#             */
/*   Updated: 2025/07/12 15:21:15 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(char **map)
{
    char **tmp;
    
    tmp = map;
    while(*tmp)
        free(*tmp++);
    free(map);
}

void	drop_error_ext(int error_num, char *error_message, char **map)
{
	if (map)
		free_map(map);
	perror(error_message);
	exit(error_num);
}

