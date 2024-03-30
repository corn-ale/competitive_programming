

int findMaxConsecutiveOnes(int* nums, int numsSize)
{
	int max = 0;
	int curr = 0;

	for (int i = 0; i < numsSize; i++)
	{
		for (; i < numsSize && nums[i]; curr++, i++)
			;
		if (curr > max)
			max = curr;
		curr = 0;
	}
	return max;
}
