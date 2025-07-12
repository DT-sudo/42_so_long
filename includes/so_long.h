/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:48:24 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/12 19:09:16 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t		BUFFER_SIZE = 100;

int			FD_FAIL = 3;
int			INVALID_MAP = 4;
int			MAP_ALLOC_FAIL = 5;
int			INVALID_POINTER = 6;
int			INVALID_MAP_NAME = 7;

typedef struct s_game_map
{
	char	**map;
	size_t	x;
	size_t	y;
	int		p;
	int		e;
	int		c;
	// int 	step;
	// int point;
	// int	start[2];
	// int	exit[2];
}			t_game_map;

typedef struct s_game_mlx
{
	void	*mlx;
	void 	*mlx_win;
	void	*img[6]; //?
	int		point; //?
}				t_game_mlx;

// so_long funcs
// start_game_validation.c
void		validation_map_name(const char *map_name);
void		validate_arguments(int argc, char **argv);
int			catch_nl(char *buf, size_t size);
int			count_map_rows(const char *map_name);

// creat_map.c
char		**malloc_map(int rows_qnt);
char		*get_map_row(int fd, char **map);
bool		add_rows(const char *map_name, char **map, int rows_qnt);
char		**creat_map(const char *map_name);

// validate_map.c
void	validate_map_walls(char **map, const char *map_name); // extend parapetrs on 1 (rows_qnt)

// utils.c
void		free_map(char **map);
void		drop_error_ext(int error_num, char *error_message, char **map);

// UTILS //
char		*ft_itoa(int n);
char		*ft_strdup(const char *s);
int			ft_print_hex(unsigned int num, const char format);
int			ft_print_ptr(unsigned long long ptr);
int			ft_print_unsigned(unsigned int n);

// ft_printf utils
void		ft_putstr(char *str);
int			ft_printstr(char *str);
int			ft_printnbr(int n);
int			ft_printpercent(void);

// libft
void		ft_putchar_fd(char c, int fd);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *str);
char		*ft_strrchr(const char *s, int c);

// get_next_line utils
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *string, int searchedChar);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t elementCount, size_t elementSize);

//  get_next_line
char		*ft_free(char *buffer, char *buf);
char		*ft_next(char *buffer);
char		*ft_line(char *buffer);
char		*read_file(int fd, char *res);
char		*get_next_line(int fd);

#endif