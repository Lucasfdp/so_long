#include "so_long.h"

int check_rectangle(t_map *map)
{
    int len;
    int i;

    len = ft_int_strlen(map->map[0]);
    i = 1;
    while (i < map->height)
    {
        if ((ft_int_strlen(map->map[i]) != len))
            return (0);
        i++;
    }
    return (1);
}

int check_walls(t_map *map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (j < map->width)
    {
        if (map->map[0][j] != '1' || map->map[map->height - 1][j] != '1')
            return (0);
        j++;
    }
    while (i < map->height)
    {
        if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

int check_valid_chars(t_map *map)
{
    int i;
    int j;
    int len;

    i = 0;
    len = ft_int_strlen(map->map[0]);
    while (i < map->height)
    {
        j = 0;
        while (j < len)
        {
            if (map->map[i][j] != '1' && map->map[i][j] != '0' &&
                 map->map[i][j] != 'P' && map->map[i][j] != 'C' && map->map[i][j] != 'E')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void count_chars(t_map *map)
{
    int i;
    int j;

    i = 0;
    map->p_count = 0;
    map->e_count = 0;
    map->c_count = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->map[i][j] == 'P')
                map->p_count += 1;
            else if (map->map[i][j] == 'C')
                map->c_count += 1;
            else if (map->map[i][j] == 'E')
                map->e_count += 1;
            j++;
        }
        i++;
    }
}

int check_char_count(t_map *map)
{
    count_chars(map);

    if (map->c_count < 1 || map->p_count != 1 || map->e_count != 1)
        return (0);
    return (1);
}