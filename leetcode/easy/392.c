#include <stdbool.h>
#include <string.h>

bool isSubsequence(char* s, char* t) {
	int sLen = strlen(s);
	int tLen = strlen(t);

	int tIndex = 0;
	int sIndex = 0;
	for (; sIndex < sLen;)
	{
		if (t[tIndex] != s[sIndex])
		{
			for (; tIndex < tLen && t[tIndex] != s[sIndex]; tIndex++)
				;
			if (t[tIndex] == '\0')
				return false;
		}
		else if (t[tIndex] == s[sIndex])
		{
			tIndex++;
			sIndex++;
			if (t[tIndex] == '\0' && s[sIndex] != '\0')
				return false;
		}
	}
	return true;
}
