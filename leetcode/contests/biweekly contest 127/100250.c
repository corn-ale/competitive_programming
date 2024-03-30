
int minimumLevels(int* possible, int possibleSize)
{
	int daniel;
	if (possible[0])
		daniel = 1;
	else
		daniel = -1;
	int bob = 0;
	for (int i = 1; i < possibleSize; i++)
	{
		if (possible[i])
			bob++;
		else
			bob--;
	}
	if (daniel > bob)
		return 1;
	for (int i = 1; i < possibleSize - 1; i++)
	{
		if (possible[i])
		{
			daniel++;
			bob--;
		}
		else
		{
			daniel--;
			bob++;
		}
		if (daniel > bob)
			return i + 1;
	}
	return -1;
}