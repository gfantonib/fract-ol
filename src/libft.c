#include "../inc/fractol.h"

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
        unsigned int    z;

        z = 0;
        while ((s1[z] != '\0' || s2[z] != '\0') && n--)
        {
                if (s1[z] != s2[z])
                        return ((unsigned char)s1[z] - (unsigned char)s2[z]);
                z++;
        }
        return (0);
}
