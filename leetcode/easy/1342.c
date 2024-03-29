
int numberOfSteps(int num)
{
	int i = 0;
	for (; num > 0; i++)
	{
		if (num % 2 == 0)
			num /= 2;
		else
			num--;
	}
	return i;
}