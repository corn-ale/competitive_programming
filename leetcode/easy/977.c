
#include <stdlib.h>
#include <stdbool.h>

void bubbleSort(int *nums, int numsSize)
{
	bool hadOp = true;
	while (hadOp)
	{
		hadOp = false;
		for (int i = 0; i < numsSize - 1; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				int tmp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = tmp;
				hadOp = true;
			}
		}
	}
}

/** 
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
	int *result;

	if (numsSize < 0)
		return NULL;
	*returnSize = numsSize;
	result = (int *)malloc(sizeof(int) * numsSize);
	if (!result)
		return NULL;
	for (int i = 0; i < numsSize; i++)
		result[i] = nums[i] * nums[i];
	bubbleSort(result, *returnSize);

	return result;
}