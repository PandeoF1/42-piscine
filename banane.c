int	ft_is_in_base(char *nbr, char *base_from)
{
	int	n;
	int	i;
	int	count;

	n = 0;
	i = 0;
	count = 0;
	while (nbr[n] == ' ' || (nbr[n] <= 13 && nbr[n] >= 9))
		n++;
	while (nbr[n] == '+' || nbr[n] == '-')
		n++;
	while (nbr[n])
	{
		while (base_from[i])
		{
			if (nbr[n] == base_from[i++])
				count++;
			else
				return (0);
		}
		n++;
	}
	if (count == 1)
		return (1);
}
