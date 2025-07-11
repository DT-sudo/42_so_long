/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtereshc <dtereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:48:24 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/10 15:57:12 by dtereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_game_map
{
    char * map;
    int coin;
    int point;
    
}              t_game_map;

typedef struct s_game_start
{
    char * map;
    int coin;
    int point;
    
}              s_game_start;

int validation_filename(const char *filename);
void	validate_arguments(int argc, char **argv);

#endif