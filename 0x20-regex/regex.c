#include "regex.h"
#include <sys/types.h>

int regex_match(char const *str, char const *pattern)
{
	ssize_t i = strlen(str) - 1, j = strlen(pattern) - 1;

	while (i > -1 && j > -1)
	{
		if (str[i] == pattern[j] || pattern[j] == '.')
		{
			i--;
			j--;
		}
		else if (pattern[j] == '*')
		{
			if (pattern[j-1] == str[i] || pattern[j-1] == '.')
				i--;
			else
				j -= 2;

		}
		else
			return (0);
	}
	if (i != -1)
		return (0);
	if (i == -1 && j != -1 && pattern[j] != '*')
		return (0);
	return (1);
}
