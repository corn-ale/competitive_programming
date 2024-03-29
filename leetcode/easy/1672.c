
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize)
{
	int sum;
	int biggestsum = 0;

	for (int i = 0; i < accountsSize; i++)
	{
		sum = 0;
		for (int j = 0; j < *accountsColSize; j++)
			sum += accounts[i][j];
		if (sum > biggestsum)
			biggestsum = sum;
	}
	return biggestsum;
}
