#include <stdbool.h>

void	bubble(int * nums, int numsSize)
{
	int temp;
	bool changed = true;
	if (numsSize > 1)
	{
		while (changed)
		{
			changed = false;
			for (int i = 1; i < numsSize; i++)
			{
				if (nums[i] < nums[i - 1])
				{
					temp = nums[i];
					nums[i] = nums[i - 1];
					nums[i - 1] = temp;
					changed = true;
				}
			}
		}
	}
}

int findMaxK(int* nums, int numsSize) {
	
	bubble(nums, numsSize);

	for (int i = 0, j = numsSize - 1; i < numsSize;)
	{
		if (nums[i] > 0 || nums[j] < 0)
			return -1;
		while (i < numsSize && nums[i] * -1 > nums[j])
			i++;
		while (j >= 0 && nums[j] * -1 < nums[i])
			j--;
		if (nums[i] * -1 == nums[j])
			return nums[j];
	}
	return -1;
}
