#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void setvalues(char *s1, char *s2, char *s3)
{
	char *fizz = "Fizz";
	char *buzz = "Buzz";
	char *fizzbuzz = "FizzBuzz";

	for (int i = 0; i <= 4; i++)
	{
		s1[i] = fizz[i];
		s2[i] = buzz[i];
	}
	for (int i = 0; i <= 8; i++)
		s3[i] = fizzbuzz[i];
}

char *itoa(int n)
{
	char *result;
	int digits;

	digits = 1;
	for (int tmp = n; tmp > 9; tmp /= 10, digits++)
		;
	result = (char *)malloc((digits + 1) * sizeof(char));
	for (int i = digits - 1, remainder = 0; n > 0; i--)
	{
		remainder = n % 10;
		n /= 10;
		result[i] = (char)(remainder + '0');
	}
	result[digits] = '\0';
	return result;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize)
{
	char **result;
	char *fizz;
	char *buzz;
	char *fizzbuzz;
	bool isfizz;
	bool isbuzz;


	result = (char **)malloc(n * sizeof(char *));
	fizz = (char *)malloc(5 * sizeof(char));
	buzz = (char *)malloc(5 * sizeof(char));
	fizzbuzz = (char *)malloc(9 * sizeof(char));
	setvalues(fizz, buzz, fizzbuzz);
	*returnSize = n;
    for (int start = 1, i = 0; i < n; start++, i++)
	{
		isfizz = false;
		isbuzz = false;
		if (start % 3 == 0)
			isfizz = true;
		if (start % 5 == 0)
			isbuzz = true;
		if (isfizz && isbuzz)
			result[i] = fizzbuzz;
		else if (isfizz)
			result[i] = fizz;
		else if (isbuzz)
			result[i] = buzz;
		else
			result[i] = itoa(start);
	}
	if (n < 15)
	{
		free(fizzbuzz);
		fizzbuzz = NULL;
	}
	if (n < 5)
	{
		free(buzz);
		buzz = NULL;
	}
	if (n < 3)
	{
		free(fizz);
		fizz = NULL;
	}
	return result;
}

int main()
{
	char **result;
	int size = 16;

	result = fizzBuzz(size, &size);

	for (int i = 0; i < size; i++)
		printf("%s, ", result[i]);
		printf("\n");
	
	if (size >= 15)
	{
		free(result[14]);
		result[14] = NULL;
	}
	if (size >= 5)
	{
		free(result[4]);
		result[4] = NULL;
	}
	if (size >= 3)
	{
		free(result[2]);
		result[2] = NULL;
	}
	for (int i = 0; i < size; i++)
	{
		if (result[i] != NULL && (i + 1) % 3 != 0 && (i + 1) % 5 != 0)
		{
			free(result[i]);
			result[i] = NULL;
		}
	}
	free(result);

	return 0;
}