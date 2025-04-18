#pragma once
# include <stdlib.h>

size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s);
char *ft_str_realloc(char* str, size_t new_size);
size_t  ft_strlcat(char *dst, const char *src, size_t size);