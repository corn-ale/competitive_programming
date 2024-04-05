#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char* largestOddNumber(char* num) {
    int len = strlen(num);
	int lastOdd = -1;
	int i = 0;

	for (; i < len; i++)
		if ((num[i] - '0') % 2 == 1)
			lastOdd = i;
	if (lastOdd < 0)
		return "";

	char *biggestOdd = malloc(sizeof(char) * (lastOdd + 2));
	if (!biggestOdd)
		return NULL;
	int j = 0;
	for (; j < lastOdd + 1; j++)
		biggestOdd[j] = num[j];
	biggestOdd[j] = '\0';
	return biggestOdd;
}
