/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:32:52 by luferna3          #+#    #+#             */
/*   Updated: 2025/06/07 05:00:37 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx_mac/mlx.h"

int count_lines(int fd)
{
    int count = 0;
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        count++;
        free(line);
    }
    return count;
}
void    print_map(char **map)
{
    int i = 0;
    while (map[i])
    {
        ft_printf("%s\n", 
        map[i]);
        i++;
    }
}
// int main(int ac, char *av[])
// {
//     (void)ac;
//     t_map   map;
    
//     if (handle_ber(av[1]))
//     {
//         if (!prep_map(av, &map))
//         {
//             ft_printf("Error\nFailed prep");
//             return (0);
//         }    
//         if (parse_map(&map))
//             print_map(map.map);
//         free_array(map.map, map.height);
//     }
//     else
//         ft_printf("Error\nTry using a .ber file");
//     void *mlx;
//     void *win;
//     //void *img;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 800, 600, "It's my game");
//     mlx_pixel_put(mlx, win, 10, 10, 0x00FF0000); // Red pixel at (10,10)
//     // // Load image (adjust the path to your .xpm file)
//     // img = mlx_xpm_file_to_image(mlx, "textures/simple.xpm", &map.width, &map.height);
//     // if (!img)
//     // {
//     //     ft_printf("lol failed");
//     //     return (1);
//     // }
//     // printf("Image loaded: %dx%d\n", map.width, map.height);
//     // // Put image at position (x=100, y=50)
//     // mlx_put_image_to_window(mlx, win, img, 0, 0);

//     mlx_loop(mlx);
//     return (0);
// }

int main(int ac, char *av[])
{
    (void)ac;
    t_map map;
    void *mlx;
    void *win;

    if (handle_ber(av[1]))
    {
        if (!prep_map(av, &map))
        {
            ft_printf("Error\nFailed prep");
            return (1);
        }
        if (parse_map(&map))
            print_map(map.map);
        else
        {
            ft_printf("Error parsing map\n");
            free_array(map.map, map.height);
            return (1);
        }

        // Init mlx after map is ready
        mlx = mlx_init();
        if (!mlx)
            return (1);

        win = mlx_new_window(mlx, 800, 600, "It's my game");
        if (!win)
            return (1);

        // Draw pixel after window creation
        mlx_pixel_put(mlx, win, 10, 10, 0x00FF0000);

        mlx_loop(mlx);

        free_array(map.map, map.height);
    }
    else
    {
        ft_printf("Error\nTry using a .ber file\n");
        return (1);
    }

    return (0);
}
