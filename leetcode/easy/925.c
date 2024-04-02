#include <stdbool.h>
#include <string.h>

bool isLongPressedName(char* name, char* typed) {
	int j = 0;
	int i = 0;
    for (; i < strlen(name); i++)
	{
		if (name[i] != typed[j])
			return false;
		for (; typed[j] != '\n' && name[i] && name[i] == typed[j]; j++)
			if (name[i + 1] == typed[j+1])
				i++;
	}
	if (j != strlen(typed))
		return false;
	return true;
}
