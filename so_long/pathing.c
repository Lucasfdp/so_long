#include "so_long.h"

char **copy_map(t_map *map)
{
    char    **map_cpy;
    int     i;

    map_cpy = malloc(sizeof(char *) * (map->height + 1));
    if (!map_cpy)
        return (NULL);
    i = 0;
    while (i < map->height)
    {
        map_cpy[i] = malloc(sizeof(char) * (map->width + 1));
        if (!map_cpy[i])
        {
            free_array(map_cpy, i);
            return (NULL);
        }
        ft_strncpy(map_cpy[i], map->map[i], map->width + 1);
        i++;
    }
    map_cpy[i] = NULL;
    return (map_cpy);
}

int find_px(char **map, int height, int width)
{
    int i;
    int j;

    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            if (map[i][j] == 'P')
                return (j);
            j++;
        }
        i++;
    }
    return (-1);
}

int find_py(char **map, int height, int width)
{
    int i;
    int j;

    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            if (map[i][j] == 'P')
                return (i);
            j++;
        }
        i++;
    }
    return (-1);
}

void    flood_fill(char **map, int y, int x)
{
    if (x < 0 || y < 0)
        return ;
    if (map[y] == NULL || map[y][x] == '\0')
        return ;
    if (map[y][x] == '1' || map[y][x] == 'F')
        return ;
    map[y][x] = 'F';
    flood_fill(map, y, x + 1);
    flood_fill(map, y + 1, x);
    flood_fill(map, y, x - 1);
    flood_fill(map, y - 1, x);
}

int check_ff(char **map, int height, int width)
{
    int i;
    int j;

    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            if (map[i][j] == 'E' || map[i][j] == 'C')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

