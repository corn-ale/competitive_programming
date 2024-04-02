
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
	int evens = 0;
	*returnSize = 0;
	int *result = (int *) malloc(sizeof(int) * numsSize);
	if (!result)
		return NULL;
	*returnSize = numsSize;
	for (int i = 0; i < numsSize ; i++)
	{
		if (nums[i] % 2 == 0)
			evens++;
	}
	int j = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] % 2 == 0)
		{
			result[j] = nums[i];
			j++;
		}
		else
		{
			result[evens] = nums[i];
			evens++;
		}
	}
	return result;
}