#include <stdlib.h>
#include <string.h>

void freeAll(char **s, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** divideString(char* s, int k, char fill, int* returnSize) {
    int len = strlen(s);
	char **res;
	
	if (len <= k)
	{
		res = malloc(sizeof(char*));
		*returnSize = 1;
	}
	else
	{
		*returnSize = len / k;
		if (len % k != 0)
			(*returnSize)++;
		res = malloc(sizeof(char*) * (*returnSize));
	}
	if (!res)
	{
		returnSize = 0;
		return NULL;
	}
	for (int i = 0, j = 0, l = 0; i < len && l < *returnSize; l++)
	{
		j = 0;
		res[l] = malloc(sizeof(char) * (k + 1));
		if (!res[l])
		{
			freeAll(res, l);
			return NULL;
		}
		for (; j < k && i < len; j++, i++)
			res[l][j] = s[i];
		if (i >= len && j < k)
			for (; j < k; j++)
				res[l][j] = fill;
		res[l][j] = '\0';
	}
	return res;
}
