//
// Created by Howe Robbin on 3/28/21.
//

#include "libft.h"

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
			return ((unsigned char)(*str1) - (unsigned char)(*str2));
	}
	return ((unsigned char)(*str1) - (unsigned char)(*str2));
}