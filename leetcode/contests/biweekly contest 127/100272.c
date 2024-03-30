

int minimumSubarrayLength(int* nums, int numsSize, int k)
{
	int curr = 0;
	for (int subLen = 0; subLen <= numsSize; subLen++)
	//increase subarray size
	{
		for (int i = 0; i < numsSize - subLen; i++)
		//find all substrings with given subLen
		{
			curr = 0;
			for (int start = i, end = i + subLen; start <= end; start++)
			{
				curr = curr | nums[start];
				if (curr >= k)
				{
					return (subLen + 1);
				}
			}
		}
	}
	return -1;
}