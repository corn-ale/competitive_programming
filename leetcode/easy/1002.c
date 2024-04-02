#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

void freeAll(char **words, int wordsSize)
{
	for (int i = 0; i < wordsSize; i++)
	{
		free(words[i]);
	}
	free(words);
}

char nextChar(int *charcount, char *chars)
{
	char c = '\0';
	for (int i = 0; i < 26; i++)
	{
		if (charcount[i] > 0)
		{
			(charcount[i])--;
			c = chars[i];
			break;
		}
	}
	return c;
}

void checkWord(char *word, char *chars, int *charcount, int* currCharcount)
{
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (word[i] == chars[j])
			{
				currCharcount[j]++;
				break;
			}
		}
	}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** words, int wordsSize, int* returnSize){
	*returnSize = 0;
	if (wordsSize == 0)
		return NULL;
		
	char chars[27];
	int charcount[26];
	int currCharcount[26];

	for (int i = 0; i < 26; i++)
		chars[i] = i + 'a';
	chars[26] = '\0';
	for (int i = 0; i < 26; i++)
		charcount[i] = 0;
	for (int i = 0; i < 26; i++)
		currCharcount[i] = 0;

	for (int i = 0; i < wordsSize; i++)
	{
		checkWord(words[i], chars, charcount, currCharcount);
		if (i == 0)
			for (int i = 0; i < 26; i++)
				currCharcount[i] = max(charcount[i], currCharcount[i]);
		else
			for (int i = 0; i < 26; i++)
				currCharcount[i] = min(charcount[i], currCharcount[i]);
		for (int i = 0; i < 26; i++)
			charcount[i] = currCharcount[i];
		for (int i = 0; i < 26; i++)
			currCharcount[i] = 0;
	}

	for (int i = 0; i < 26; i++)
		*returnSize += charcount[i];
	char **result = (char **)malloc(sizeof(char*) * (*returnSize));
	if (!result)
		return NULL;
	for (int i = 0; i < *returnSize; i++)
	{
		result[i] = (char *)malloc(sizeof(char) * (2));
		if (!result[i])
		{
			freeAll(result, i);
			return NULL;
		}
		result[i][0] = nextChar(charcount, chars);
		result[i][1] = '\0';
	}
	return result;
}

int main()
{
	int retsize = 0;
	int wordsize = 3;
	char *words[wordsize];
	char **res;
	words[0] = "bella";
	words[1] = "label";
	words[2] = "roller";
	res = commonChars(words, wordsize , &retsize);
	for (int i = 0; i < retsize; i++)
		printf("%s ", res[i]);
	freeAll(res, retsize);
	return 0;
}