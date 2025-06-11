

#ifndef SO_LONG_H
# define SO_LONG_H
# include "Libft/libft.h"
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

#endif