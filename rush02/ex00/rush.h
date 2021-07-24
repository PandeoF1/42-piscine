/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 10:36:23 by tnard             #+#    #+#             */
/*   Updated: 2021/07/24 17:08:39 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

typedef struct s_rush
{
	char	*value;
	char	*name;
}				t_rush;

char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(const char *str);
void	ft_putstr(char *str);
void	ft_putchar(const char letter);
char	*ft_strcpy(char *dest, const char *src);
int		ft_parse(t_rush	**parse, char *filename);
t_rush	*ft_search_by_id(t_rush *pairs, int size, char *id);
int		ft_init_rush(t_rush *this, char *value, char *name);
int		ft_tab_strlen(const char *str);
int		error(void);
int		ft_tab_next_strlen(const char *str);
char	**ft_split(char *str, char b);
int		ft_strnumber(char param[]);
char	*ft_strdup(char *src);

#endif