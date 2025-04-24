#include <stdio.h>

int main(int ac, char **av, char **envp)
{
    (void)ac;
    (void)av;
    int i = 0;
    while (envp[i])
        printf("%s\n", envp[i++]);
    return (0);
}