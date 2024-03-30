class 1295 {
    public int findNumbers(int[] nums) {
        int len = nums.length;
		int res = 0;

		for (int i = 0; i < len; i++)
		{
			int j = 0;
			for (int n = nums[i]; n > 0; n /= 10, j++)
				;
			if (j % 2 == 0)
				res++;
		}
		return res;
    }
}