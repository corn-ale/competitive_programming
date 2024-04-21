
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
	int *result = malloc(sizeof(int) * 2);
	int *values = malloc(sizeof(int) * numsSize);

	if (!result || !values)
		return NULL;
	*returnSize = 2;

	for (int i = 0; i < numsSize; i++)
		values[i] = 0;
	for (int i = 0; i < numsSize; i++)
		values[nums[i] - 1]++;
	for (int i = 0; i < numsSize; i++)
	{
		if (values[i] == 0)
			result[1] = i + 1;
		if (values[i] == 2)
			result[0] = i + 1;
	}
	return result;
}
