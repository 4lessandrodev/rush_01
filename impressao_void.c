#include <unistd.h>
#include <stdio.h>

void	ftputchar(char c)
{
	write(1, &c, 1);
}

void	print_result(int matriz[6][6])
{
	int	colums;
	int	rows;

	colums = 1;
	while (colums <= 4)
	{
		rows = 1;
		while (rows <= 4)
		{
			ftputchar(matriz[colums][rows] + '0');
			rows++;
		}
		ftputchar('\n');
		colums++;
	}
}
