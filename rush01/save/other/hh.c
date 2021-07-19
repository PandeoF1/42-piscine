#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct SkyScrapper SkyScrapper;

struct SkyScrapper
{
	int grid[4][4];
};

typedef struct Node Node;

struct Node
{
	SkyScrapper config;
	Node	**childs;
	int	nb_childs;
};

void    ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void    ft_print_grid(int   columns, int  lines, int  **grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < lines)
	{
		j = 0;
		while (j < columns)
		{
			ft_putchar(grid[i][j]);
			j++;
		}
		i++;
	}
	printf("Hello1");
}

int    **ft_grid_random(int  columns, int    lines)
{
	int *grid[lines];
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < lines)
	{
		while (j < columns)
		{
			grid[i] = malloc(sizeof(int*)*columns);
			grid[i][j] = i+j;
			printf("%d", grid[i][j]);
			j++;
		}
		printf("%d", grid[i][j]);
		i++;
	}
	return 0;
}

int main(void)
{
	int **grid = ft_grid_random(4,4);
	//ft_print_grid(4, 4, grid);
	return (0);
}