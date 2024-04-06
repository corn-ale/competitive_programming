
int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 1)
		return 1;
    int curr;
	int j = 1;
	for (int i = 0; j < numsSize; j++)
	{
		curr = nums[i];
		for (; i < numsSize && curr == nums[i]; i++)
			;
		if (i == numsSize)
			break;
		nums[j] = nums[i];
	}
	return j;
}
