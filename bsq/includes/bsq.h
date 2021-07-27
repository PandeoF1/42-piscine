/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 10:36:23 by tnard             #+#    #+#             */
/*   Updated: 2021/07/27 07:10:52 by molatrec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_bsq
{
	int	x;
	int	y;
	int	size;
}				t_bsq;

char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strlen(const char *str);
void	ft_putstr(char *str);
void	ft_putchar(const char letter);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(char *src);
char	**ft_parse(char *filename, int a, int fd, int len);
char	**ft_split(char *str, char b);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_check_first_line(char **content, char **value);
int		ft_check_file(char **content, char *value);
int		ft_map_length(char **map);
int		ft_map_depth(char **map);
void	ft_fill_map_obstacles(int **fill, char **map);
void	ft_free(int **to_free, char **map);
int		**ft_create_map_obstacle(int x, int y);
int		**ft_obstacle_map(char **map);
t_bsq	ft_best_possible_fill(t_bsq best_possible, int i, int j, int size);
int		ft_square_fits(int **obstacles_map, int i, int j, int size);
t_bsq	ft_solve(char **map, int i, int j);
void	ft_printing(char **map);

#endif