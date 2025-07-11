/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtereshc <dtereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:41:45 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/10 19:37:34 by dtereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Validates all tiles of the map
// wether it's only 0, 1, C, E, P
// counts if there is only one P rights down it coordinates
// counts if there is only one E rights down it coordinates
// counts if there is at least one C
// if the map fully sorounded by walles
// if smth wrang passes coresponding error

// passes the error and clears the memory
void	drop_error(int error_num)
{
}

// goes throgh the whole map and cheks every tile
void	validate_map(void)
{
}

// tile checker if not drop_error
void	check_tile(void)
{
}

// checks if E/P == 1 and C > 0 if not drop_error
void	validate_e_p_c(void)
{
}

// checks if map is closed if not drop_error
void	validate_walls(void)
{
}
