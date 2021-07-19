/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 09:47:21 by tnard             #+#    #+#             */
/*   Updated: 2021/07/17 09:47:22 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

int		error(void);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_checkarg(char *str, int size);
int		ft_getarg(char *str, int nb);
int		ft_is_num(char c);
int		sft_strlen(char *str);
int		**ft_init(int size, char *argv);
void	ft_show(int **tab, int size);
void	ft_putnbr(int nb);
int		ft_check(int **grid, int size);
void	ft_complete_condition(int **grid, int condition_number, int grid_size);
int		ft_solve(int **tab, int size);
int     **ft_clone_grid(int **grid, int grid_size);


typedef struct coordinates
{
    int x;
    int y;
} coordinates;

typedef struct node {
    struct node *parent;
    struct node **childs;
    int number_child;
    int **grid;
    int grid_size;
} node;

void    ft_init_grid_node(node *this, int **grid, int grid_size);
void    ft_generate_all_childs(node *this);

#endif
