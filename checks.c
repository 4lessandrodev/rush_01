void	check_1(int *num, int i, int *val) //coloca 4 em todos os lados
{
	int n;

	if (*(num + i) == 1 && i < 4)
		n = i;
	else if (*(num + i) == 1 && i > 3 && i < 8)
		n = i + 12;
	else if (*(num + i) == 1 && i > 7 && i < 12)
		n = (i - 8) * 4;
	else if (*(num + i) == 1 && i > 11)
		n = (i - 11) * 4 - 1;
	*(val + n) = 4;
}

void	check_4(int *num, int i, int *val) //Coloca 1, 2 e 3 em todas as linhas. O 4 não coloca pois já passou no check_1
{
	int n;

	if (*(num + i) == 4 && i < 4)
	{
		n = i;
		*(val + n) = 1;
		*(val + n + 4) = 2;
		*(val + n + 8) = 3;
	}
	else if (*(num + i) == 4 && i > 3 && i < 8)
	{
		n = i + 12;
		*(val + n) = 1;
		*(val + n - 4) = 2;
		*(val + n - 8) = 3;
	}
	else if (*(num + i) == 4 && i > 7 && i < 12)
	{
		n = (i - 8) * 4;
		*(val + n) = 1;
		*(val + n + 1) = 2;
		*(val + n + 2) = 3;
	}
	else if (*(num + i) == 4 && i > 11)
	{
		n = (i - 11) * 4 - 1;
		*(val + n) = 1;
		*(val + n - 1) = 2;
		*(val + n - 2) = 3;
	}
}

void	check_3_2(int *num, int i, int *val) //Coloca um 4 na posição correcta caso tenha um 3 em uma ponta e 2 na outra.
{
	int n;

	if (*(num + i) == 3 && *(num + i + 4) == 2 && i < 4)
		n = i + 8;
	else if (*(num + i) == 3 && *(num + i - 4) == 2 && 3 < i && i < 8)
		n = i - 8;
	else if (*(num + i) == 3 && *(num + i + 4) == 2 && 7 < i && i < 12)
		n = (i - 8) * 4 + 2;
	else if (*(num + i) == 3 && *(num + i - 4) == 2 && i > 11)
		n = (i - 11) * 4 - 3;
	*(val + n) = 4;
}

void	check_1_2(int *num, int i, int *val) //Coloca um 3 na ultima.
{
	int n;

	if (*(num + i) == 1 && *(num + i + 4) == 2 && i < 4)
		n = i + 12;
	else if (*(num + i) == 1 && *(num + i - 4) == 2 && 3 < i && i < 8)
		n = i - 12;
	else if (*(num + i) == 1 && *(num + i + 4) == 2 && 7 < i && i < 12)
		n = (i - 8) * 4 + 3;
	else if (*(num + i) == 1 && *(num + i - 4) == 2 && i > 11)
		n = (i - 11) * 4 - 1;
	*(val + n) = 3;
}

void	check_3_2_last_3(int *num, int i, int *val) //Coloca 4 na posição correta caso tenha 3 em uma ponta e 2 na outra.
{
	int n;

	if (*(num + i) == 3 && *(num + i + 4) == 2 && i < 4 && *(val + (i - 11) * 4 - 1) == 3)
	{
		n = i;
		*(val + n) = 1;
		*(val + n + 4) = 2;
	}
	else if (*(num + i) == 3 && *(num + i - 4) == 2 && 3 < i && i < 8 && *(val + i - 8) == 3)
		{
		n = i - 8;
		*(val + n) = 1;
		*(val + n - 4) = 2;
		}
	else if (*(num + i) == 3 && *(num + i + 4) == 2 && 7 < i && i < 12 && *(val + (i - 8) * 4) == 3)
		{
		n = (i - 8) * 4;
		*(val + n) = 1;
		*(val + n + 1) = 2;
		}
	else if (*(num + i) == 3 && *(num + i - 4) == 2 && i > 11 && *(val + (i - 11) * 4 - 1) == 3)
		{
		n = (i - 11) * 4 - 1;
		*(val + n) = 1;
		*(val + n - 1) = 2;
		}
}

int		check_repeat(int *val) //Busca números repetidos comparando a soma 10
{
	if (10 == (*(val) + *(val + 1) + *(val + 2) + *(val + 3)))
		return (1);
	else if (10 == (*(val + 4) + *(val + 5) + *(val + 6) + *(val + 7)))
		return (1);
	else if (10 == (*(val + 8) + *(val + 9) + *(val + 10) + *(val + 11)))
		return (1);
	else if (10 == (*(val + 12) + *(val + 13) + *(val + 14) + *(val + 15)))
		return (1);
	else if (10 == (*(val) + *(val + 4) + *(val + 8) + *(val + 12)))
		return (1);
	else if (10 == (*(val + 1) + *(val + 5) + *(val + 9) + *(val + 13)))
		return (1);
	else if (10 == (*(val + 2) + *(val + 6) + *(val + 10) + *(val + 14)))
		return (1);
	else if (10 == (*(val + 3) + *(val + 7) + *(val + 11) + *(val + 15)))
		return (1);
	else
		return (0);
}

void	check_fill()
