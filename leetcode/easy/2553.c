#include <stdlib.h>

int countDigits(int *nums, int numsSize)
{
	int digits = 0;
	int curr;
	for (int i = 0; i < numsSize; i++)
	{
		curr = nums[i];
		for (; curr > 0; curr /= 10)
			digits++;
	}
	return digits;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* separateDigits(int* nums, int numsSize, int* returnSize) {
	if (numsSize < 1)
		return NULL;
	
	*returnSize = countDigits(nums, numsSize);
	int *result = (int *)malloc(sizeof(int) * (*returnSize));
	if (!result)
		return NULL;
	for (int i = numsSize - 1, j = *returnSize - 1; i >= 0; i--)
		for (; nums[i] > 0; nums[i] /= 10, j--)
			result[j] = nums[i] % 10;
	return result;
}
