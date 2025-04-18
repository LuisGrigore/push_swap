#include "./utils.h"

size_t  ft_strlen(const char *s)
{
        size_t  num;

        num = 0;
        while (s[num] != '\0')
        {
                num++;
        }
        return (num);
}

char    *ft_strdup(const char *s)
{
        char    *new_str;
        int             i;

        new_str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
        if (!new_str)
        {
                return (NULL);
        }
        i = 0;
        while (s[i])
        {
                new_str[i] = s[i];
                i++;
        }
        return (new_str);
}

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
        size_t          i;
        char            *d;
        const char      *s;

        if (dest == NULL && src == NULL && n != 0)
        {
                return (dest);
        }
        d = (char *)dest;
        s = (const char *)src;
        i = 0;
        while (i < n)
        {
                d[i] = s[i];
                i++;
        }
        return (dest);
}

char *ft_str_realloc(char* str, size_t new_size) {
    if (new_size == 0) {
        free(str);
        return NULL;
    }
    char* nuevo_str = (char*)malloc(new_size);
    if (!nuevo_str) {
        return NULL;
    }
    if (str) {
        size_t len_original = ft_strlen(str);
        size_t copiar_hasta = (len_original < new_size - 1) ? len_original : new_size - 1;
        ft_memcpy(nuevo_str, str, copiar_hasta);
        nuevo_str[copiar_hasta] = '\0';
        free(str);
    } else {
        nuevo_str[0] = '\0';
    }
    return nuevo_str;
}

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
        char                    *d;
        char                    *s;
        unsigned int    n;
        unsigned int    dlen;

        d = (char *)dst;
        s = (char *)src;
        n = size;
        while (n-- != 0 && *d != '\0')
                d++;
        dlen = d - dst;
        n = size - dlen;
        if (n == 0)
                return (dlen + ft_strlen(s));
        while (*s != '\0')
        {
                if (n != 1)
                {
                        *d++ = *s;
                        n--;
                }
                s++;
        }
        *d = '\0';
        return (dlen + (s - src));
}
