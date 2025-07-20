/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:48:24 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/19 17:47:36 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFFER_SIZE 100
# define FD_FAIL 3
# define INVALID_MAP 4
# define INVALID_INPUT 5
# define MAP_ALLOC_FAIL 6
# define INVALID_POINTER 7
# define INVALID_MAP_NAME 8
# define TILE_SIZE 64

typedef struct s_game_map
{
	char		**map;
	const char	*map_name;
	size_t		map_height;
	size_t		map_width;
	int			p;
	int			e;
	int			c;
	int			e_cordinates[2];
	int			p_cordinates[2];
	int			step;
}				t_game_map;

typedef struct s_game_mlx
{
	void		*mlx;
	void		*win;
	void		*tile[5];
}				t_game_mlx;

// so_long funcs
// collectibles_exit.c
void			reach_every_E_C(t_game_map *game, size_t x, size_t y);
void			find_E_C_P_restore(t_game_map *game);
void			collectibles_exit(t_game_map *game);
void			set_P_cordinates(t_game_map *game);

// start_game_validation.c
void			validation_map_name(const char *map_name);
void			validate_arguments(int argc, char **argv);

// creat_map.c
bool			add_rows(t_game_map *game, int rows_qnt);
int				count_map_rows(const char *map_name);
char			*get_row(int fd, char **map);
char			**creat_map(t_game_map *game);
char			**malloc_map(int lines);

// validate_map.c
void			count_tiles(t_game_map *game, char tile_sign, size_t x,
					size_t y);
void			validate_map_walls(t_game_map *game);
void			validate_e_p_c_qnt(t_game_map *game);
void			validate_map(t_game_map *game);
void			check_tiles(t_game_map *game);

// utils.c
void			drop_error_ext(int error_num, char *error_message, char **map);
int				catch_nl(char *buf, size_t size);
void			free_map(char **map);

// move.c
int				move_kyes(int k_num, t_game_map *game, t_game_mlx *data);
void			make_map_logic(t_game_map *game, t_game_mlx *data, size_t x,
					size_t y);
void			make_map(t_game_map *game, t_game_mlx *data);
void			move(t_game_map *game, t_game_mlx *data, size_t next_x,
					size_t next_y);
void			update_p_cordinates(t_game_map *game, size_t new_p_x,
					size_t new_p_y);

// creat_win.c
void			clean_mlx(t_game_mlx *data, t_game_map *map);
void			clean_imgs(t_game_mlx *data);
void			set_imgs(t_game_map *game, t_game_mlx *data);
void			esc(t_game_mlx *data, t_game_map map);
void			init_func(t_game_map *game, t_game_mlx *data);

// UTILS //
int				ft_print_hex(unsigned int num, const char format);
int				ft_print_ptr(unsigned long long ptr);
int				ft_print_unsigned(unsigned int n);
char			*ft_strdup(const char *s);
char			*ft_itoa(int n);

// ft_printf utils
int				ft_printstr(char *str);
int				ft_printpercent(void);
void			ft_putstr(char *str);
int				ft_printnbr(int n);

// LIBFT
char			*ft_strrchr(const char *s, int c);
void			ft_putchar_fd(char c, int fd);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s);
int				ft_strcmp(const char *s1, const char *s2);

// ft_itoa.c
// static void		ft_isneg(int *n, int *neg, int *tmp);
// static void		ft_itoa_write(char *str, int len, int n, int tmp);
// static int		ft_itoa_len(int n);
char			*ft_itoa(int n);

// ft_print_hex.c
int				ft_hex_len(unsigned int num);
void			ft_put_hex(unsigned int num, const char format);
int				ft_print_hex(unsigned int num, const char format);

// ft_print_ptr.c
int				ft_ptr_len(uintptr_t num);
void			ft_put_ptr(uintptr_t num);
int				ft_print_ptr(unsigned long long ptr);

// ft_print_unsigned.c
int				ft_num_len(unsigned int num);
char			*ft_uitoa(unsigned int n);
int				ft_print_unsigned(unsigned int n);

// ft_printf_utils.c
void			ft_putstr(char *str);
int				ft_printstr(char *str);
int				ft_printnbr(int n);
int				ft_printpercent(void);

// get_next_line utils
void			*ft_calloc(size_t elementCount, size_t elementSize);
char			*ft_strchr(const char *string, int searchedChar);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_bzero(void *s, size_t n);

//  get_next_line
char			*ft_free(char *buffer, char *buf);
char			*read_file(int fd, char *res);
char			*ft_next(char *buffer);
char			*ft_line(char *buffer);
char			*get_next_line(int fd);

#endif