/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsandre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:13:16 by vsandre           #+#    #+#             */
/*   Updated: 2021/07/18 11:13:33 by vsandre          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush01.h"
#include <stdio.h>



int ft_count_empty_cells(node *this)
{
    int i;
    int j;
    int size;
    int count;
    
    count = 0;
    size = this->grid_size;
    i = 1;
    while (i < size + 1)
    {
        j = 1;
        while (j < size + 1)
        {
            if (this->grid[i][j] == 0)
                count++;
            j++;
        }
        i++;
    }
    return count;
}

coordinates* ft_get_empty_cells(node *this)
{
    int empty_cells_size;
    int i;
    int j;
    coordinates* empty_coordinate;
    int count;

    count = 0;
    empty_cells_size = ft_count_empty_cells(this);
    empty_coordinate = malloc(sizeof(coordinates*) * empty_cells_size);
    i = 1;
    while (i < this->grid_size + 1)
    {
        j = 1;
        while (j < this->grid_size + 1)
        {
            if (this->grid[i][j] == 0)
            {
                coordinates tmp_coord = {i, j};
                empty_coordinate[count] = tmp_coord;
                printf("(%d,%d)", empty_coordinate[count].x, empty_coordinate[count].y);
                count++;
            }
            j++;  
        }
        i++;
    }
    return empty_coordinate;
}

int **ft_clone_grid(int **grid, int grid_size)
{
    int **copied_grid;
    int i;
    int j;

    i = 0;
    grid_size += 2;
    copied_grid = malloc(sizeof(int *) * (grid_size));
	while (i < grid_size)
		copied_grid[i++] = malloc(sizeof(int *) * (grid_size));
    i = 0;
    while (i < grid_size)
    {
        j = 0;
        while (j < grid_size)
        {
            copied_grid[i][j] = grid[i][j];
            j++;
        }
        i++;
    }
    return copied_grid;
}

void    ft_init_grid_node(node *this, int **grid, int grid_size)
{
    this->grid = ft_clone_grid(grid, grid_size);
    this->grid_size = grid_size;
}

int    ft_generate_all_childs(node *this)
{
    int i;
    int empty_cell_size;
    int counter;

    i = 0;
    empty_cell_size = ft_count_empty_cells(this);
    if (empty_cell_size)//todo ajouter && is_grid_valid_to_constraints
        return (1);  
    coordinates* empty_cells_coord;
    empty_cells_coord = ft_get_empty_cells(this);
    while (i < empty_cell_size)
    {

    }

    //genere tous les enfants
        //pour chaque enfant qui ne casse pas les regles
            //
            //genere les enfants
    //si aucune case n'est vide retourner la valeur
}
/*
node    *ft_generate_child(node *this, int line, int column, int value)
{

}*/