public class _485_MaxConsecutiveOnes {
    public int findMaxConsecutiveOnes(int[] nums) {
		int len = nums.length;
		int max = 0;
		for (int i = 0; i < len; i++)
		{
			int curr = 0;
			for (; i < len && nums[i]; i++, curr++)
				;
			if (curr > max)
				max = curr;
		}
		return max;
    }
}
