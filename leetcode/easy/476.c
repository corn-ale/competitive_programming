
int findComplement(int num) {
	int biggestBit = 0;
	int temp = num;
	int op = 1;

	for (; temp > 0; biggestBit++)
		temp = temp >> 1;
	for (int i = 1; i < biggestBit; i++)
	{
		op = op << 1;
		op += 1;
	}
	num = num ^ op;
	return num;
}
