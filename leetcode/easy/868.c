#include <stdbool.h>

int binaryGap(int n) {
	int limit;
	int currDist;
	int maxDist;
	bool highBit;

	limit  = (sizeof(int) * 8) - 1;
	maxDist = 0;

	for (int i = 1, comparator = 1; i < limit; )
	{
		currDist = 1;
		highBit = false;
		for (; i < limit && !highBit; i++, comparator <<= 1)
			if ((n & comparator) != 0)
				highBit = true;
		if (!highBit)
			return maxDist;
		for (; i < limit && (n & comparator) == 0; i++, comparator <<= 1)
			currDist++;
		if (i == limit)
			return maxDist;
		if (currDist > maxDist)
			maxDist = currDist;
	}
	return maxDist;
}
