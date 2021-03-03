#include "lib.h"

#define STR "hello world!\n"
#define STR2 "hello world!", "hello friend :)"

int main(int argc, char const *argv[])
{

/*
** 	int ft_strcmp(const char *s1, const char *s2);
*/

	printf("strcmp =\t%d\n", strcmp(STR2));
	printf("ft_strcmp =\t%d\n", ft_strcmp(STR2));


	printf("strlen =\t%lu\n", strlen(STR));
	printf("ft_strlen =\t%lu\n", ft_strlen(STR));

	ft_write(0, STR, 13);
	return 0;
}