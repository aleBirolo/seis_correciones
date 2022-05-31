/// Birolo ALejandro 36072015
#include "Cadena.h"

char *str_chr(char *s, int c)
{
    while (*s && *s!=(char)c)
        s++;

    return s;
}

char *str_rchr(char *s, int c)
{
    char *ini=s;

    while (*s)
        s++;
    s--;
    while ( *s && s>=ini && *s!=(char)c)
        s--;

    return s;
}

size_t str_len (const char *s)
{
    int n=0;

    while (*s)
    {
        s++;
        n++;
    }

    return n;
}

char *str_cpy(char *s1, const char *s2)
{
    char *ini=s1;
    while (*s2)
    {
        *s1=*s2;
        s1++;
        s2++;
    }

    return ini;
}
