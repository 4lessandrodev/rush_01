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
	int	col;

	row = 1;
	while (row <= 4)
	{
		col = 1;
		while (col <= 4)
		{
			if (row == 1 || row == 4) // primeira ou ultima linha da tabela
			{
				if (matrix[0][col] == 1) // label de cima
				{
					matrix[1][col] = 4;
				}
				if (matrix[5][col] == 1) // label de baixo
				{
					matrix[4][col] = 4;
				}
			}
			if (col == 1 || col == 4) // primeira ou ultima coluna da tabela
			{
				if (matrix[0][row] == 1) // label da esquerda
				{
					matrix[1][row] = 4;
				}
				if (matrix[5][row] == 1) // label da direita
				{
					matrix[4][row] = 4;
				}
			}
			col++;
		}
		row++;
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
	int	col;

	row = 1;
	while (row <= 4)
	{
		col = 1;
		while (col <= 4)
		{
			if (row == 1 || row == 4) // primeira ou ultima linha da tabela
			{
				if (matrix[0][col] == 1 && matrix[5][col] == 4)
				{
					matrix[1][col] = 4;
					matrix[2][col] = 3;
					matrix[3][col] = 2;
					matrix[4][col] = 1;
				}
				if (matrix[5][col] == 1 && matrix[0][col] == 4)
				{
					matrix[4][col] = 4;
					matrix[3][col] = 3;
					matrix[2][col] = 2;
					matrix[1][col] = 1;
				}
			}
			if (col == 1 || col == 4) // primeira ou ultima coluna da tabela
			{
				if (matrix[0][row] == 1 && matrix[5][row] == 4)
				{
					matrix[1][row] = 4;
					matrix[2][row] = 3;
					matrix[3][row] = 2;
					matrix[4][row] = 1;
				}
				if (matrix[5][row] == 1 && matrix[0][row] == 4)
				{
					matrix[4][row] = 4;
					matrix[3][row] = 3;
					matrix[2][row] = 2;
					matrix[1][row] = 1;
				}
			}
			col++;
		}
		row++;
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

 /*
Sempre que a label for 1 e o lado oposto for 2, a label 2 recebe
o valor de 3

  x  1  x  x
x[ ][4][ ][ ]x
x[ ][ ][ ][ ]x
1[4][ ][ ][3]2
x[ ][ ][ ][ ]x
  x  x  x  x
  */

 /*
Sempre que a label for 1 e o lado oposto for 3, haverá uma sequência
4,2,3,1: conforme o padrão abaixo 

  x  x  x  x
x[ ][ ][ ][ ]x
1[4][2][3][1]3
x[ ][ ][ ][ ]x
x[ ][ ][ ][ ]x
  x  x  x  x
*/

/*
Sempre que a label for 3 e o lado oposto for 1, haverá uma sequência
1,3,2,4: conforme o padrão abaixo 

  x  x  x  x
x[ ][ ][ ][ ]x
3[1][3][2][4]1
x[ ][ ][ ][ ]x
x[ ][ ][ ][ ]x
  x  x  x  x
  */

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

 /*
Não pode existir número repetido para linha e coluna

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