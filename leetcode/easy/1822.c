int signFunc(int x)
{
	if (x > 0)
		return 1;
	if (x < 0)
		return -1;
	return 0;
}

int arraySign(int* nums, int numsSize) {
	if (!nums || !numsSize)
		return 0;
	int product = nums[0];
	int currSign = signFunc(product);
	if (numsSize == 1)
		return currSign;
    for (int i = 1; i < numsSize; i++)
	{
		currSign *= signFunc(nums[i]);
		if (currSign == 0)
			return currSign;
	}
	return currSign;
}
