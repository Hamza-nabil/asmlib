#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#define FALSE 0
#define TRUE 1

ssize_t ft_write(int fd, const void *buf, size_t count);
long unsigned ft_strlen(char *s);
int ft_strcmp(const char *s1, const char *s2);
#endif