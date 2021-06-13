/**
[
	[0, 2, 1, 2, 3, 0], 
	[2, 3, 4, 0, 0, 2], 
	[2, 0, 0, 0, 0, 2], 
	[1, 4, 0, 0, 0, 4], 
	[4, 1, 2, 3, 4, 1], 
	[0, 2, 3, 2, 1, 0]
]
 */
// [linha][coluna]
const matrix:Array<Array<number>> = [
	[0,2,1,2,3,0],
	[2,0,0,0,0,2],
 	[2,0,0,0,0,2],
 	[1,0,0,0,0,4],
 	[4,0,0,0,0,1],
	[0,2,3,2,1,0] 
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
console.log(matrix);



// [linha][coluna]
/**
 * 
const matriz:Array<Array<number>> = [
	[0,1,2,3,4,0],
	[5,6,7,8,9,10],
 	[11,13,14,15,16,17],
 	[18,19,20,21,22,23],
 	[24,25,26,27,28,29],
	[0,30,31,32,33,0] 
];

 */