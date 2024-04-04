#include <string.h>
#include <stdbool.h>

bool makeEqual(char** words, int wordsSize) {
	int totalLen = 0;
    for (int i = 0; i < wordsSize; i++)
	{
		int currLen = strlen(words[i]);
		if (currLen < 1)
			return false;
		totalLen += currLen;
	}
	if (totalLen % wordsSize != 0)
		return false;
	int charCount[26];
	for (int i = 0; i < 26; i++)
		charCount[i] = 0;
	
	for (int i = 0; i < wordsSize; i++)
	{
		int currLen = strlen(words[i]);
		for (int j = 0; j < currLen; j++)
			charCount[(words[i][j]) - 'a']++;
	}

	for (int i = 0; i < 26; i++)
		if (charCount[i] % wordsSize != 0)
			return false;
	return true;
}
