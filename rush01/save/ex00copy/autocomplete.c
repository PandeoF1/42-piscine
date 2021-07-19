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

int	ft_is_cell_empty(int cell_value)
{
	if (cell_value == 0)
		return (1);
	return (0);
}

int	ft_autocomplete_line_to_down(int **grid, int column, int condition_number)
{
	int	j;
	int	cell_value;

	j = 1;
	cell_value = 1;
	while (j < condition_number + 1)
	{
		if (ft_is_cell_empty(grid[j][column]) || grid[j][column] == cell_value)
			grid[j][column] = cell_value;
		else
			return (0);
		cell_value++;
		j++;
	}
	return (1);
}

int	ft_autocomplete_line_to_up(int **grid, int column, int condition_number)
{
	int	cell_value;
	int	j;

	cell_value = 1;
	j = condition_number;
	while (j > 0)
	{
		if (ft_is_cell_empty(grid[j][column]) || grid[j][column] == cell_value)
			grid[j][column] = cell_value;
		else
			return (0);
		cell_value++;
		j--;
	}
	return (0);
}

int	ft_autocoplete_line_to_right(int **grid, int row, int condition_number)
{
	int	cell_value;
	int	j;

	cell_value = 1;
	j = 1;
	while (j < condition_number + 1)
	{
		if (ft_is_cell_empty(grid[row][j]) || grid[row][j] == cell_value)
			grid[row][j] = cell_value;
		else
			return (0);
		cell_value++;
		j++;
	}
	return (1);
}

int	ft_autocoplete_line_to_left(int **grid, int row, int condition_number)
{
	int	cell_value;
	int	j;

	cell_value = 1;
	j = condition_number;
	while (j > 0)
	{
		if (ft_is_cell_empty(grid[row][j]) || grid[row][j] == cell_value)
			grid[row][j] = cell_value;
		else
			return (0);
		cell_value++;
		j--;
	}
	return (1);
}

int	ft_complete_condition(int **grid, int condition_number, int grid_size)
{
	int	i;

	i = 0;
	while (i < grid_size)
	{
		if (grid[0][i] == condition_number)
			if (!ft_autocomplete_line_to_down(grid, i, condition_number))
				return (0);
		if (grid[grid_size - 1][i] == condition_number)
			if (ft_autocomplete_line_to_up(grid, i, condition_number))
				return (0);
		if (grid[i][0] == condition_number)
			if (ft_autocoplete_line_to_right(grid, i, condition_number))
				return (0);
		if (grid[i][grid_size - 1] == condition_number)
			if (ft_autocoplete_line_to_left(grid, i, condition_number))
				return (0);
		i++;
	}
	return (1);
}
