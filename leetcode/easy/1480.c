#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize)
{
	int *sums;
	int sum;

	sum = 0;
	sums = (int *)malloc(numsSize * sizeof(int));
	if (!sums || numsSize < 1)
	{
		*returnSize = 0;
		return NULL;
	}
	*returnSize = numsSize;
	sums[0] = nums[0];
	for (int i = 1; i < numsSize; i++)
		sums[i] = nums[i] + sums[i - 1];
	return sums;
}

int main()
{
	int *nums;
	int *runningssum;
	int size;
	int returnSize;

	size = 5;
	returnSize = size;
	nums = (int *)malloc(size * sizeof(int));
	if (!nums)
		return 1;
	for (int i = 0; i < size; i++)
		nums[i] = size - i;
	
	printf("input: ");
	for (int i  = 0; i < size; i++)
		printf("%d ", nums[i]);
	printf("\n");

	runningssum = runningSum(nums, size, &returnSize);
	
	printf("output: ");
	for (int i = 0; i < returnSize; i++)
		printf("%d ", runningssum[i]);
	printf("\n");

	free(nums);
	free(runningssum);
	return 0;
}
