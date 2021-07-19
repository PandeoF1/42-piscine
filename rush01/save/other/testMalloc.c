#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const int	GRID_SIZE = 4;

int	**ft_grid_random(int columns, int lines)
{
	int	**grid;
	int	i;
	int	j;

	i = 0;
	j = 0;
	grid = (int **) malloc(lines * sizeof(int *));
	while (i < lines)
		grid[i++] = (int *) malloc(columns * sizeof(int));
	i = 0;
	while (i < lines)
	{
		while (j < columns)
		{
			grid[i][j] = i + j;
			j++;
		}
		i++;
		j = 0;
	}
	j = 0;
	i = 0;
	while (i < lines)
	{
		while (j < columns)
		{
			printf(" %d ", grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
	return (0);
}

int	main(void)
{
	int	**grid;

	grid = ft_grid_random(GRID_SIZE, GRID_SIZE);
	//ft_print_grid(4, 4, grid);
	return (0);
}