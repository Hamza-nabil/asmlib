#include "lib.h"

#define STR "hello world!\n"
#define STR2 "hello world!", "hello friend :)"

char *my_strdup(const char *s)
{
	int len;
	char *ret;

	len = ft_strlen(s);
	len++;

	ret = malloc(len);
	strcpy(ret, s);
	return ret;
}

int main(int argc, char const *argv[])
{

	// char *s = strdup("hello world");
	char *s = ft_strdup("hello world");

	/*
** 	int ft_strcmp(const char *s1, const char *s2);
*/

	printf("strcmp =\t%d\n", strcmp(STR2));
	printf("ft_strcmp =\t%d\n", ft_strcmp(STR2));

	printf("strlen =\t%lu\n", strlen(STR));
	printf("ft_strlen =\t%lu\n", ft_strlen(STR));

	// printf("strlcpy =\t%s\n", s);
	printf("strcpy =\t%s\n", strcpy(s, "hello friend"));
	printf("strcpy =\t%s\n", ft_strcpy(s, "hello friend"));

	// ft_write(0, STR, 13);
	return 0;
}