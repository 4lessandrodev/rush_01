void	print_result(int matriz[6][6]);

int	main (void)
{
	int	matriz[6][6];
	int	k;
	int	m;

	k = 1;
	while (k <= 4)
	{
		m = 1;
		while (m <= 4)
		{
			matriz[k][m] = 1;
			m++;
		}
		k++;
	}
	print_result(matriz);
	return (0);
}
