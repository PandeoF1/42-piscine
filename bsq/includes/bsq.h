/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 10:36:23 by tnard             #+#    #+#             */
/*   Updated: 2021/07/26 17:21:46 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

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

#endif