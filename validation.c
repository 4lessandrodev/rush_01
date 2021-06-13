//Regras: 4 x 4
/*
A extremidade que tem label 1 deve ser 4

[
	[[*][x][1][x][x][*]]
 	[[x][ ][4][ ][ ][x]]
 	[[1][4][ ][ ][ ][x]]
 	[[x][ ][ ][ ][4][1]]
 	[[x][ ][ ][4][ ][1]]
 	[[*][x][x][1][x][*]]
]

*/
/*
* @param matrix ponteiro da matriz
*/
void	put_max_on_label1(int **matrix)
{
	int	row;
	int	column;

	row = 1;
	column = 1;
	//direita e esquerda (linhas)
	while (row <= 4)
	{
		// linha direita [linha][coluna]
		if (matrix[row][5] == 1) 
		{
			matrix[row][4] = 4;
		}
		// row esquerda [row][coluna]
		if (matrix[row][0] == 1)
		{
			matrix[row][1] = 4;
		}
		row++;
	}
	// cima e baixo (colunas)
	while (column <= 4)
	{
		// baixo [linha][column]
		if (matrix[5][column] == 1)
		{
			matrix[4][column] = 4;
		}
		// cima [linha][column]
		if (matrix[0][column] == 1) 
		{
			matrix[1][column] = 4;
		}
		column++;
	}
}

 /*
Sempre que tiver 4 em uma extremidade e 1 no lado oposto 
tem-se uma sequência 
[
	[ ][x][1][x][x][ ]
	[x][ ][4][ ][ ][x]
	[x][ ][3][ ][ ][x]
	[4][1][2][3][4][1]
	[x][ ][1][ ][ ][x]
	[ ][x][4][x][x][ ]
]
*/
void	put_sequence_on_label1_4(int **matrix)
{
	int	row;
	int	column;

	row = 1;
	column = 1;

	while(column <= 4)
	{
		// cima esquerdo && baixo esquerdo [linha][column]
		if (matrix[0][column] == 1 && matrix[5][column] == 4)
		{
			matrix[1][column] = 4;
			matrix[2][column] = 3;
			matrix[3][column] = 2;
			matrix[4][column] = 1;
		}
		// baixo esquerdo && cima esquerdo [linha][column]
		if (matrix[5][column] == 1 && matrix[0][column] == 4)
		{
			matrix[1][column] = 1;
			matrix[2][column] = 2;
			matrix[3][column] = 3;
			matrix[4][column] = 4;
		}
		column++;
	}
	while(row <= 4)
	{
		// lateral esquerda cima && lateral direita cima
		// [row][coluna]
		if (matrix[row][5] == 1 && matrix[row][0] == 4)
		{
			matrix[row][1] = 1;
			matrix[row][2] = 2;
			matrix[row][3] = 3;
			matrix[row][4] = 4;
		}
		// lateral direita cima && lateral esquerda cima
		// [row][coluna]
		if (matrix[row][0] == 1 && matrix[row][5] == 4)
		{
			matrix[row][1] = 4;
			matrix[row][2] = 3;
			matrix[row][3] = 2;
			matrix[row][4] = 1;
		}
		row++;
	}
}
 /*
Sempre que o canto tiver o padrão de label 2 x 2 o valor do canto 
será 3. Exceto que tenha dois cantos com a label 2 x 2

[
	[ ][2][x][x][x][ ]
	[2][3][ ][ ][ ][x]
	[x][ ][ ][ ][ ][x]
	[x][ ][ ][ ][ ][x]
	[x][ ][ ][ ][ ][x]
	[ ][x][x][x][x][ ]
]
*/

void	put_3_on_corner(int **matrix)
{
	int	qtd_corner;

	qtd_corner = 0;

	if (matrix[0][1] == 2 && matrix[1][0] == 2)
	{
		qtd_corner++;
	}

	if (matrix[0][4] == 2 && matrix[1][5] == 2)
	{
		qtd_corner++;
	}

	if (matrix[5][4] == 2 && matrix[4][5] == 2)
	{
		qtd_corner++;
	}

	if (matrix[4][0] == 2 && matrix[5][1] == 2)
	{
		qtd_corner++;
	}
	if (qtd_corner == 1)
	{
		if (matrix[0][1] == 2 && matrix[1][0] == 2)
		{
			matrix[1][1] = 3;
		}

		if (matrix[0][4] == 2 && matrix[1][5] == 2)
		{
			matrix[1][4] = 3;
		}

		if (matrix[5][4] == 2 && matrix[4][5] == 2)
		{
			matrix[4][4] = 3;
		}

		if (matrix[4][0] == 2 && matrix[5][1] == 2)
		{
			matrix[4][1] = 3;
		}
	}
}

 /*
Sempre que a linha ou a coluna faltar apenas um número deve-se
preencher com o número faltante. A = 1

  x  1  x  x
x[ ][4][ ][ ]x
x[ ][A][ ][ ]x
1[4][3][2][1]4
4[1][2][3][4]1
  x  3  x  x
  */

void	put_last_number_column(int **matrix)
{
	int	numbers[4];
	int	column;
	int	row;
	int	qtd_zeros;
	int	index;
	int	fault_number;

	column = 1;
	fault_number = 0;
	row = 1;
	while (column <= 4)
	{
		row = 1;
		qtd_zeros = 0;
		index = 0;
		while (row <= 4)
		{
			if (matrix[row][column] == 0)
			{
				qtd_zeros++;
			}
			else
			{
				numbers[index] = matrix[row][column];
				index++;
			}
			row++;
		}
		if (qtd_zeros == 1)
		{
			fault_number = (10 - (numbers[0] + numbers[1] + numbers[2]));
			row = 1;
			while (row <= 4)
			{
				if (matrix[row][column] == 0)
				{
					matrix[row][column] = fault_number;
				}
				row++;
			}
		}
		column++;
	}
}

void	put_last_number_row(int **matrix)
{
	int	numbers[4];
	int	column = 1;
	int	row = 1;
	int	qtd_zeros;
	int	index;
	int	fault_number = 0;

	while (row <= 4)
	{
		column = 1;
		qtd_zeros = 0;
		index = 0;
		while (column <= 4)
		{
			if (matrix[row][column] == 0)
			{
				qtd_zeros++;
			}
			else
			{
				numbers[index] = matrix[row][column];
				index++;
			}
			column++;
		}
		if (qtd_zeros == 1)
		{
			fault_number = (10 - (numbers[0] + numbers[1] + numbers[2]));
			column = 1;
			while (column <= 4)
			{
				if (matrix[row][column] == 0)
				{
					matrix[row][column] = fault_number;
				}
				column++;
			}
		}
		row++;
	}
}

 /*
Coloca o 4 na posição correta sempre que tiver a label de um lado
com o valor 3 e na outra extremidade a label com valor 2

  x  x  3  x
x[ ][ ][ ][ ]x
2[ ][4][ ][ ]3
x[ ][ ][4][ ]x
x[ ][ ][ ][ ]x
  x  x  2  x
*/

void	put_four_3_2(int **matrix)
{
	int	column;
	int	row;

	while (column <= 4)
	{
		row = 1;
		while (row <= 4)
		{
			// colocar 4 validando columns [row][column]
			if (matrix[0][column] == 3 && matrix[5][column] == 2)
			{
				matrix[3][column] = 4;
			}
			if (matrix[0][column] == 2 && matrix[5][column] == 3)
			{
				matrix[2][column] = 4;
			}
			// colocar 4 validando rows [row][column]
			if (matrix[row][0] == 3 && matrix[row][5] == 2)
			{
				matrix[row][3] = 4;
			}
			if (matrix[row][0] == 2 && matrix[row][5] == 3)
			{
				matrix[row][2] = 4;
			}
			row++;
		}
		column++;
	}
}

 /*
Não pode existir número repetido para linha e column

  x  x  x  x
x[1][2][3][4]x
x[2][1][4][3]x
x[3][4][2][1]x
x[4][3][1][2]x
  x  x  x  x
*/

/*
Todos os lados devem somar 10 (colunas e linhas)

[01][02][03][04]10
[02][01][04][03]10
[03][04][02][01]10
[04][03][01][02]10
 10  10  10  10
*/