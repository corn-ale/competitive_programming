#include <stdbool.h>
#include <string.h>

bool canConstruct(char* ransomNote, char* magazine)
{
	char *letters;
	int *ransomcount[26];
	int *magazinecount[26];

	letters = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 26; i++)
	{
		ransomcount[i] = 0;
		magazinecount[i] = 0;
	}
	int len = strlen(magazine);
	for (int i = 0; i < len; i++)
	{
		int j = 0;
		while (magazine[i] != letters[j])
			j++;
		magazinecount[j]++;
	}
	len = strlen(ransomNote);
	for (int i = 0; i < len; i++)
	{
		int j = 0;
		while (ransomNote[i] != letters[j])
			j++;
		ransomcount[j]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (ransomcount[i] > magazinecount[i])
			return false;
	}
	return true;
}
