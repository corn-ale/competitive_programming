#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

char *substr(char *s, int start, int len)
{
	if (!s || start < 0 || len < 1)
		return NULL;
	int slen = strlen(s);
	if (slen < start + len)
		len = slen - start;
	char *result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return NULL;
	for (int i = 0, j = start; i < len - 1 && j < slen; i++, j++)
		result[i] = s[j];
	result[len] = '\0';
	return result;
}

int isPresent(char *str, char **words, int wordCount)
{
	int len = strlen(str);
	for (int i = 0; i < wordCount; i++)
		if (strcmp(str, words[i]) == 0)
			return i;
	return -1;
}

void freeAll(char **str, int numOfWords)
{
	if (!str)
		return ;
	for (int i = 0; i < numOfWords; i++)
		free(str[i]);
	free(str);
	
}

void strToLower(char *str)
{
	int len = strlen(str);

	for (int i = 0; i < len; i++)
		str[i] = tolower(str[i]);
}

bool isWordEnd(char c)
{
	char end[] = " !?',;.\0";
	int len = strlen(end);

	for (int i = 0; i < len; i++)
		if (c == end[i])
			return true;
	return false;
}

int numOfWords(char *str)
{
	int len = strlen(str);
	int result = 0;
	bool started = false;

	for (int i = 0; i < len; i++)
	{
		if (!started && isalpha(str[i]))
			started = true;
		else if (started && isWordEnd(str[i]))
		{
			started = false;
			result++;
		}
	}
	return result;
}

char* mostCommonWord(char* paragraph, char** banned, int bannedSize) {
	int words;
	char **keys;
	char *word;
	int *values;
	int plen;
	int wordlen;
	int start;
	bool started;
	int keyLoc;
	int keyI;

    strToLower(paragraph);
	words = numOfWords(paragraph);
	values = malloc(sizeof(int) * words);
	keys = malloc(sizeof(char*) * words);
	if (!keys || !values)
		return NULL;
	plen = strlen(paragraph);
	wordlen = 0;
	started = false;
	start = 0;
	keyI = 0;

	for (int i = 0; i < plen; i++) //load words into hashmap
	{
		if (!started && isalpha(paragraph[i]))
		{
			started = true;
			start = i;
	printf("HERE\n");
		}
		else if (started && isWordEnd(paragraph[i]))
		{
			started = false;
			wordlen = i - start;
			word = substr(paragraph, start, wordlen);
			if (!word)
			{
				free(values);
				free(word);
				freeAll(keys, keyI);
				return NULL;
			}
			if (isPresent(word, banned, bannedSize) == -1) // if -1 -> not banned -> include in hashmap
			{
				//check if new word is in hashmap -> increase counter
				keyLoc = isPresent(word, keys, keyI);
				if (keyLoc != -1)
					values[keyLoc]++;
				//if not -> add word to hasmap and set counter to 1
				else
				{
					keys[keyI] = malloc(sizeof(char) * (wordlen + 1));
					if (!keys[keyI])
					{
						free(values);
						free(word);
						freeAll(keys, keyI);
						return NULL;
					}
					for (int j = 0; j < wordlen; j++, start++)
						keys[keyI][j] = start;
					keys[keyI][wordlen] = '\0';
					values[keyI] = 1;
					keyI++;
				}
			}
			free(word);
			word = NULL;
		}
	}
	//find hingest val is hashmap
	int max = 0;
	int maxLoc = 0;
	for (int i = 0; i < keyI; i++)
	{
		if (values[i] > max)
		{
			max = values[i];
			maxLoc = i;
		}
	}
	int resLen = strlen(keys[maxLoc]);
	char *result = malloc(sizeof(char) * (resLen + 1));
	for (int i = 0; i < resLen; i++)
		result[i] = keys[maxLoc][i];
	result[resLen] = '\0';
	free(values);
	freeAll(keys, words);
	return result;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("error: missing args\n");
		return -1;
	}
	char *paragraph = argv[1];
	char **banned = NULL;
	int bannedSize = 0; 
	if (argc > 2)
	{
		bannedSize = argc - 2;
		banned = malloc(sizeof(char*) * bannedSize);
		for (int i = 0; i < bannedSize; i++)
			banned[i] = argv[i + 2];
	}
	char *result = mostCommonWord(paragraph, banned, bannedSize);
	printf("paragraph: %s\n", paragraph);
	printf("banned:");
	for (int i = 0; i < bannedSize; i++)
		printf(" %s", banned[i]);
	printf("\nbannedSize: %d\n", bannedSize);
	printf("most common word: _%s_\n", result);
	if (banned)
		free(banned);
	if (result)
		free(result);
	return 0;
}