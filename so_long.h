/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 03:08:57 by luferna3          #+#    #+#             */
/*   Updated: 2025/06/11 02:28:45 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <string.h>

# define TILE_SIZE 64


typedef struct s_map
{
    char    **map;
    int     height;
    int     width;
    int     p_count;
    int     e_count;
    int     c_count;
} t_map;

typedef struct s_img
{
    void    *wall;
    void    *floor;
    void    *player;
    void    *exit;
    void    *collect;
} t_img;

//parsing
int handle_ber(char *str);
int check_rectangle(t_map *map);
void    nwl_for_null(t_map *map);
int check_walls(t_map *map);
int check_valid_chars(t_map *map);
int count_lines(int fd);
int prep_map(char **av, t_map *map);
void count_chars(t_map *map);
int check_char_count(t_map *map);
int parse_map(t_map *map);
char **copy_map(t_map *map);
int find_px(char **map, int height, int width);
int find_py(char **map, int height, int width);
void    flood_fill(char **map, int y, int x);
int check_ff(char **map, int height, int width);
int validate_pathing(t_map *map);

//loading_map
void    load_images(t_img *imgs, void *mlx);
void	put_tile(void *mlx, void *win, t_img *imgs, char tile, int x, int y);
void	draw_map(t_map *map, void *mlx, void *win, t_img *imgs);

#endif