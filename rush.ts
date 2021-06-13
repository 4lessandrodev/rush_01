
//https://www.typescriptlang.org/play
/**
[
	[0, 2, 1, 2, 3, 0], 
	[2, 3, 4, 0, 0, 2], 
	[2, 0, 0, 0, 0, 2], 
	[1, 4, 3, 2, 1, 4], 
	[4, 1, 2, 3, 4, 1], 
	[0, 2, 3, 2, 1, 0]
]
*/
// [linha][coluna]
const matrix:Array<Array<number>> = [
	[0,2,4,3,1,0],
	[3,0,0,0,0,1],
 	[3,0,0,0,0,2],
 	[1,0,0,0,0,4],
 	[2,0,0,0,0,2],
	[0,2,1,3,3,0] 
];

function	put_max_on_label1(matrix: Array<Array<number>>)
{
	let linha = 1;
	let coluna = 1;
	//direita e esquerda (linhas)
	while (linha <= 4)
	{
		// linha direita [linha][coluna]
		if (matrix[linha][5] == 1) 
		{
			matrix[linha][4] = 4;
		}
		// linha esquerda [linha][coluna]
		if (matrix[linha][0] == 1)
		{
			matrix[linha][1] = 4;
		}
		linha++;
	}
	// cima e baixo (colunas)
	while (coluna <= 4)
	{
		// baixo [linha][coluna]
		if (matrix[5][coluna] == 1)
		{
			matrix[4][coluna] = 4;
		}
		// cima [linha][coluna]
		if (matrix[0][coluna] == 1) 
		{
			matrix[1][coluna] = 4;
		}
		coluna++;
	}
}
put_max_on_label1(matrix);

function	put_sequence_on_label1_4(matrix: Array<Array<number>>)
{
	let linha = 1;
	let coluna = 1;

	while(coluna <= 4)
	{
		// cima esquerdo && baixo esquerdo [linha][coluna]
		if (matrix[0][coluna] == 1 && matrix[5][coluna] == 4)
		{
			matrix[1][coluna] = 4;
			matrix[2][coluna] = 3;
			matrix[3][coluna] = 2;
			matrix[4][coluna] = 1;
		}
		// baixo esquerdo && cima esquerdo [linha][coluna]
		if (matrix[5][coluna] == 1 && matrix[0][coluna] == 4)
		{
			matrix[1][coluna] = 1;
			matrix[2][coluna] = 2;
			matrix[3][coluna] = 3;
			matrix[4][coluna] = 4;
		}
		coluna++;
	}
	while(linha <= 4)
	{
		// lateral esquerda cima && lateral direita cima
		// [linha][coluna]
		if (matrix[linha][5] == 1 && matrix[linha][0] == 4)
		{
			matrix[linha][1] = 1;
			matrix[linha][2] = 2;
			matrix[linha][3] = 3;
			matrix[linha][4] = 4;
		}
		// lateral direita cima && lateral esquerda cima
		// [linha][coluna]
		if (matrix[linha][0] == 1 && matrix[linha][5] == 4)
		{
			matrix[linha][1] = 4;
			matrix[linha][2] = 3;
			matrix[linha][3] = 2;
			matrix[linha][4] = 1;
		}
		linha++;
	}
}
put_sequence_on_label1_4(matrix);
/*
 [
	[0, 1, 3, 2, 3, 0], 
 	[1, 4, 0, 0, 0, 3], 
 	[2, 3, 0, 0, 0, 2], 
 	[2, 2, 0, 0, 0, 2],
 	[3, 1, 0, 0, 4, 1], 
 	[0, 4, 2, 2, 1, 0]
 ] 
 */


function	put_3_on_corner(matrix: Array<Array<number>>)
{
	let	qtd_corner;

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
			console.log("acessou");
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

put_3_on_corner(matrix);




// [linha][coluna]
/**
 /*
Coloca o 4 na posição correta sempre que tiver a label de um lado
com o valor 3 e na outra extremidade a label com valor 2

[0][x][x][3][x][0]
[x][ ][ ][ ][ ][x]
[2][ ][4][ ][ ][3]
[x][ ][ ][4][ ][x]
[x][ ][ ][ ][ ][x]
[0][x][2][x][ ][0]
*/
function put_four_3_2(matrix: Array<Array<number>>)
{
	let coluna = 1;
	let linha;
	while (coluna <= 4)
	{
		linha = 1;
		while (linha <= 4)
		{
			// colocar 4 validando colunas [linha][coluna]
			if (matrix[0][coluna] == 3 && matrix[5][coluna] == 2)
			{
				matrix[3][coluna] = 4;
			}
			if (matrix[0][coluna] == 2 && matrix[5][coluna] == 3)
			{
				matrix[2][coluna] = 4;
			}
			// colocar 4 validando linhas [linha][coluna]
			if (matrix[linha][0] == 3 && matrix[linha][5] == 2)
			{
				matrix[linha][3] = 4;
			}
			if (matrix[linha][0] == 2 && matrix[linha][5] == 3)
			{
				matrix[linha][2] = 4;
			}
			linha++;
		}
		coluna++;
	}
}

put_four_3_2(matrix);
console.log(matrix);

/**
 
[
	[0, 2, 4, 3, 1, 0], 
	[3, 0, 1, 3, 4, 1], 
	[3, 0, 2, 4, 0, 2], 
	[1, 4, 3, 2, 1, 4], 
	[2, 3, 4, 1, 0, 2], 
	[0, 2, 1, 3, 3, 0]
] 

 */