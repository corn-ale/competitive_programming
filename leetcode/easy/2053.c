#include <stdbool.h>
#include <string.h>

bool isSameString(char *s1, char *s2)
{
	if (strlen(s1) != strlen(s2))
		return false;
	for (int i = 0; i < strlen(s1) ; i++)
		if (s1[i] != s2[i])
			return false; 
	return true;
}

char* kthDistinct(char** arr, int arrSize, int k) {
	int distinctStrings[arrSize];
	int count = 0;
	int distLoc = 0;

	for (int i = 0; i < arrSize; i++)
		distinctStrings[distLoc] = 0;
	for (int i = 0; i < arrSize; i++)
	{
		bool isSame = false;
		for (int j = 0; j < arrSize; j++)
		{
			if (j == i)
				;
			
			else if (isSameString(arr[i], arr[j]))
			{
				isSame = true;
				break;
			}
		}
		if (!isSame)
		{
			distinctStrings[distLoc] = i;
			distLoc++;
		}
	}
	if (distLoc < k)
		return "";
	return (arr[distinctStrings[k - 1]]);
}
