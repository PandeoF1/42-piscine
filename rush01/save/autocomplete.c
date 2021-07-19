/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsandre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:44:01 by vsandre           #+#    #+#             */
/*   Updated: 2021/07/17 19:21:18 by vsandre          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_autocomplete_line_to_down(int **grid, int column, int condition_number, int grid_size)
{
	int	j;
	int	cell_value;
	condition_number = 0;
	j = 1;
	cell_value = 1;
	while (j < grid_size - 1)
	{
		grid[j][column] = cell_value;
		cell_value++;
		j++;
	}
}

void	ft_autocomplete_line_to_up(int **grid, int column, int condition_number, int grid_size)
{
	int	cell_value;
	int	j;
	condition_number = 0;
	cell_value = 1;
	j = grid_size - 2;
	while (j > 0)
	{
		grid[j][column] = cell_value;
		cell_value++;
		j--;
	}
}

void	ft_autocoplete_line_to_right(int **grid, int row, int condition_number, int grid_size)
{
	int	cell_value;
	int	j;
	condition_number = 0;
	cell_value = 1;
	j = 1;
	while (j < grid_size - 1)
	{
		grid[row][j] = cell_value;
		cell_value++;
		j++;
	}
}

void	ft_autocoplete_line_to_left(int **grid, int row, int condition_number, int grid_size)
{
	int	cell_value;
	int	j;
	condition_number = 0;
	cell_value = 1;
	//j = grid_size - 2;
	j = condition_number;
	while (j > 0)
	{
		grid[row][j] = cell_value;
		cell_value++;
		j--;
	}
}

void	ft_complete_condition(int **grid, int condition_number, int grid_size)
{
	int	i;

	i = 0;
	while (i < grid_size)
	{
		if (grid[0][i] == condition_number)
			ft_autocomplete_line_to_down(grid, i, condition_number, grid_size);
		if (grid[grid_size - 1][i] == condition_number)
			ft_autocomplete_line_to_up(grid, i, condition_number, grid_size);
		if (grid[i][0] == condition_number)
			ft_autocoplete_line_to_right(grid, i, condition_number, grid_size);
		if (grid[i][grid_size - 1] == condition_number)
			ft_autocoplete_line_to_left(grid, i, condition_number, grid_size);
		i++;
	}
}

/*int main(void)
{
	int grid [6][6] = {
		{0,1,3,2,1,0},
		{1,0,0,0,0,1},
		{3,0,0,0,0,2},
		{2,0,0,0,0,2},
		{1,0,0,0,0,1},
		{0,4,2,1,2,0}
	};
	
	printGrid(grid);
	ft_complete_condition(grid, g_size - 2, g_size);
	printGrid(grid);
	return (0);
}*/