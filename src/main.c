/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:32:52 by luferna3          #+#    #+#             */
/*   Updated: 2025/06/11 07:12:55 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

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
//     void *img;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 800, 600, "It's my game");
//     img = mlx_xpm_file_to_image(mlx, "textures/SnowTiles.xpm", &map.width, &map.height);
//     if (!img)
//     {
//         ft_printf("lol failed");
//         return (1);
//     }
//     printf("Image loaded: %dx%d\n", map.width, map.height);
//     // Put image at position (x=100, y=50)
//     mlx_put_image_to_window(mlx, win, img, 300, 100);

//     mlx_loop(mlx);
//     return (0);
// }

int	main(int ac, char **av)
{
	t_map	map;
	t_img	imgs;
	void	*mlx;
	void	*win;
    (void)ac;
    
	// load map etc. into `map`
	prep_map(av, &map);

	mlx = mlx_init();
	win = mlx_new_window(mlx, map.width * 256, map.height * 256, "so_long");
	load_images(&imgs, mlx);
	draw_map(&map, mlx, win, &imgs);
	mlx_loop(mlx);
	return (0);
}
