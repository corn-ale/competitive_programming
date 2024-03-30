#include <string.h>
#include <stdlib.h>

char *mergeAlternately(char * word1, char * word2)
{
	int len1 = strlen(word1);
	int len2 = strlen(word2);
	char *result = (char *)malloc((len1 + len2 + 1) * sizeof(char));

	int i = 0, j = 0;
	while (word1[j] != '\0' && word2[j] != '\0')
	{
		result[i++] = word1[j];
		result[i++] = word2[j++];
	}
	if (len1 > len2)
		for (; word1[j] != '\0'; i++, j++)
			result[i] = word1[j];
	else
		for (; word2[j] != '\0'; i++, j++)
			result[i] = word2[j];
	result[i] = '\0';
	return result;
}