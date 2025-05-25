/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:21:53 by luferna3          #+#    #+#             */
/*   Updated: 2025/02/02 21:23:36 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_subs(const char *s, char c)
{
	size_t	num_subs;

	num_subs = 0;
	while (*s)
	{
		if (*s != c)
		{
			num_subs++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (num_subs);
}

void	ft_free_all(char **result, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (result[i])
			free(result[i]);
		i++;
	}
	free(result);
}

char	**dosplit(const char *s, char c, char **result)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			result[i] = ft_substr(s - len, 0, len);
			if (!result)
			{
				ft_free_all(result, i);
				return (0);
			}
			i++;
		}
		else
			s++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;

	if (!s)
		return (0);
	result = malloc(sizeof(char *) * (ft_count_subs(s, c) + 1));
	if (!result)
		return (0);
	result = dosplit(s, c, result);
	return (result);
}

// int	main(void)
// {
// 	char	str[] = "hello!";
// 	char	c = ' ';
// 	char	**result = ft_split(str, c);
// 	int	i;

// 	i = 0;
// 	if (result)
// 	{
// 		while (result[i])
// 		{
// 			printf("Substring %d is: %s\n", i, result[i]);
// 			free(result[i]);
// 			i++;
// 		}
// 		free(result);
// 	}
// 	return (0);
// }

// int count_substrs(char *str, char c)
// {
//     int num_subs;

//     num_subs = 0;
//     while (*str)
//     {
//         if (*str != c)
//         {
//             num_subs += 1;
//             while (*str && *str != c)
//                 str++;
//         }
//         else
//             str++;
//     }
//     return (num_subs);
// }

// char	*ft_substr(char *s, int start, int len)
// {
// 	char	*dst;
// 	int		i;

// 	if ((!s) || (start > ft_strlen(s)))
// 		return (NULL);
// 	if (len > (ft_strlen(s) - start))
// 		len = ft_strlen(s) - start;
// 	dst = malloc(sizeof(char) * len + 2);
// 	if (!dst)
// 		return (NULL);
// 	i = 0;
// 	while (len >= i)
// 	{
// 		dst[i] = s[start + i];
// 		i++;
// 	}
// 	return (dst);
// }

// void    free_on_error(char **result, int count)
// {
//     int i;

//     i = 0;
//     while (i <= count)
//     {
//         if (!result)
//             free(result[i]);
//         i++;
//     }
//     free(result);
// }

// char	**dosplit(char *s, char c, char **result)
// {
// 	size_t	i;
// 	size_t	len;

// 	i = 0;
// 	while (*s)
// 	{
// 		if (*s != c)
// 		{
// 			len = 0;
// 			while (*s && *s != c && ++len)
// 				s++;
// 			result[i] = ft_substr(s - len, 0, len);
// 			if (!result)
// 			{
// 				free_on_error(result, i);
// 				return (0);
// 			}
// 			i++;
// 		}
// 		else
// 			s++;
// 	}
// 	result[i] = 0;
// 	return (result);
// }

// char	**ft_split(char *s, char c)
// {
// 	char	**result;

// 	if (!s)
// 		return (0);
// 	result = malloc(sizeof(char *) * (count_substrs(s, c) + 1));
// 	if (!result)
// 		return (0);
// 	result = dosplit(s, c, result);
// 	return (result);
// }