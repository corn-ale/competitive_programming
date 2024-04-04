#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void getFreq(char *word, int *freq)
{
	int len = strlen(word);
	for (int i = 0; i < len; i++)
		freq[word[i] - 'a']++;
}

bool checkAlmostEquivalent(char* word1, char* word2) {
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
	int freq1[26];
	int freq2[26];

	for (int i = 0; i < 26; i++)
	{
		freq1[i] = 0;
		freq2[i] = 0;
	}
	getFreq(word1, freq1);
	getFreq(word2, freq2);
	for (int i = 0, diff = 0; i < 26; i++)
	{
		diff = freq1[i] - freq2[i];
		if (diff > 3 || diff < -3)
			return false;
	}
	return true;
}

int main()
{
	checkAlmostEquivalent("hello", "abrakadabra");
	return 0;
}