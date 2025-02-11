#include "libft.h"

void    ft_free(char **s, int i)
{
    int j;
    if (i == -1)
    {
        j = 0;
        while (s[j])
        {
            free(s[j++]);
        }
    } else
    {
        while (--i >= 0)
        {
            printf("%d\n", i);
            free(s[i]);
        }
    }
    free(s);
}
/*
int main(void)
{
    int n_str = 5;
    int i = 0;
    char **array = (char **) malloc (sizeof(char *) * (n_str + 1));
    if (!array)
    return 1;
    while (i < n_str)
    {
        array[i] = (char *) malloc (sizeof(char) * 5);
        if(!array[i])
        return (ft_free(array, i), 1);
        array[i] = ft_memcpy(array[i], "ciao\0", 5);
        i++;
    }
    array[n_str] = 0;
    printf("array creato\n");
    ft_free(array, 3);
    return 0;
}
*/