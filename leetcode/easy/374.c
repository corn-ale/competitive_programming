 
// Forward declaration of guess API.
// @param  num   your guess
// @return 	    -1 if num is higher than the picked number
//   			1 if num is lower than the picked number
//   			otherwise return 0
//int guess(int num);


int guessNumber(int n)
{
	unsigned int min = 1;
	unsigned int max = n;

	int try = (max + min) / 2;
	int ret;
	do {
		ret = guess(try);
		if (ret > 0)
		{
			if (min == try)
				try++;
			min = try;
			try = (min + max) / 2;
		}
		else if (ret < 0)
		{
			if (max == try)
				try--;
			max = try;
			try = (max + min) / 2;
		}
	} while (ret != 0);
	return try;
}