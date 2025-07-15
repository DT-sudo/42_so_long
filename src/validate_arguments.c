/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:41:49 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/14 19:35:43 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	validation_map_name(const char *map_name)
{
	const char	*ext;

	if (!map_name)
		drop_error_ext(INVALID_MAP_NAME, "Error: Invalid map name.\n", NULL);
	ext = ft_strrchr(map_name, '.');
	if (!ext || ft_strcmp(ext, ".ber") != 0)
		drop_error_ext(INVALID_MAP,
			"Error: Invalid file type: expected a .ber file.\n", NULL);
	
}

void	validate_arguments(int argc, char **argv)
{
	int	descriptor;

	if (argc < 2)
		drop_error_ext(INVALID_INPUT, "Use: ./so_long <map_file.ber>", NULL);
	else if (argc > 2)
		drop_error_ext(INVALID_INPUT, "Error: Too many arguments provided.\n",
			NULL);
	validation_map_name(argv[1]);
	descriptor = open(argv[1], O_RDONLY);
	if (descriptor < 0)
		drop_error_ext(INVALID_INPUT, "Error: Could not open map file.\n", NULL);
	close(descriptor);
}

