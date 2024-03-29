
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool isPrefixString(char * s, char ** words, int wordsSize) //wordsSize = num of words
{
    int i = 0;
    int j = 0;
    int k = 0;

    if (s[i] != words[j][k])    //1st letter diff
        return false;
    while (s[i] != '\0')
    {
        if (s[i] != words[j][k])
            return false;
        i++;
        k++;
        if (!words[j][k])       //end of a word
        {
            k = 0;
            j++;
            if (j == wordsSize) //buff overflow/accessing memory after last word
            {
                if (s[i])
                    return false;
                else
                    return true;
            }
        }
    }
    if (k)                      //letter diff should be at start of a word
        return false;
    if (!j && words[j][k] != '\0')	//didnt reach end of 1st word
        return false;
	return true;
}

int	main()		//shitty main bcoz leetcode was breaking
{
	char	**words;
	bool	result;

	words = malloc(sizeof (char*) * 2);
	words[0] = malloc(sizeof(char) * 2);
	words[0] = "z";
	words[1] = NULL;

	result = isPrefixString("z", words, 20);
	if (result)
		write(1, "true\n", 4);
	else
		write(1, "false\n", 5);
}
