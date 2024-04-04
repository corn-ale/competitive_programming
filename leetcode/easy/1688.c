

int numberOfMatches(int n){
	int matches = 0;
	while (n > 1)
	{
		if (n % 2 == 0)
		{
			n /= 2;
			matches += n;
		}
		else
		{
			n = (n - 1) / 2 + 1;
			matches = matches + n - 1;
		}
	}
	return matches;
}
