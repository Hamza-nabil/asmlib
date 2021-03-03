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


	// char *s = strdup(STR);
	char *s = ft_strdup(STR);

	int fd = open("file_test", O_CREAT | O_WRONLY | O_RDONLY, 0666);
	printf("strcmp =\t%d\n", strcmp(STR2));
	printf("ft_strcmp =\t%d\n", ft_strcmp(STR2));

	printf("strlen =\t%lu\n", strlen(STR));
	printf("ft_strlen =\t%lu\n", ft_strlen(STR));

	printf("strcpy =\t%s\n", strcpy(s, "hello friend"));
	printf("strcpy =\t%s\n", ft_strcpy(s, "hello friend"));

	ft_write(fd, STR, 13);
	// write(0, STR, 13);
	close(fd);
	return 0;
}