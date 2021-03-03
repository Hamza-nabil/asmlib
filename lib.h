#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

#define FALSE 0
#define TRUE 1
char *ft_strdup(const char *s);
char *ft_strcpy(char *dest, const char *src);
ssize_t ft_write(int fd, const void *buf, size_t count);
size_t ft_strlen(char *s);
int ft_strcmp(const char *s1, const char *s2);
#endif