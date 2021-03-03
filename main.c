#include "lib.h"

// int ft_strcmp(const char *s1, const char *s2)
// {
// 	int cmp;
// 	int rax;
// 	int i;

// 	i = 0;
// campare:
// 	cmp = s1[i] - s2[i];
// 	if (cmp > 0)
// 		goto greater;
// 	if (cmp < 0)
// 		goto lesser;
// 	if (s1[i] == 0)
// 		goto equal;
// 	increment :i++;
// 	goto campare;
// greater:
// 	rax = 1;
// 	return (rax);
// lesser :
// 	rax = -1;
// 	return (rax);
// equal:
// 	rax = 0;
// 	return (rax);
// }

int main(int argc, char const *argv[])
{
	printf("len = %d\n", ft_strcmp("xello", "hello"));
	printf("len = %d\n", strcmp("xello", "hello"));
	// printf("len = %lu\n", ft_strlen(NULL));
	return 0;
}