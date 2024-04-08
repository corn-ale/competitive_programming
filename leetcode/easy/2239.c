
int findClosestNumber(int* nums, int numsSize) {
	int closest = nums[0];
	int absClosest = closest;
	if (absClosest < 0)
		absClosest = closest * (-1);
	for (int i = 1, curr; i < numsSize; i++)
	{
		curr = nums[i];
		if (curr < 0)
			curr *= -1;
		if (curr < absClosest)
		{
			closest = nums[i];
			absClosest = closest;
			if (closest < 0)
				absClosest = closest * -1;
		}
		else if (curr == absClosest && nums[i] > closest)
		{
			closest = nums[i];
			absClosest = closest;
			if (closest < 0)
				absClosest = closest * -1;
		}
	}
	return closest;
}
