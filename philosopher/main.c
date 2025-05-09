/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:51:08 by miricci           #+#    #+#             */
/*   Updated: 2025/05/08 16:02:25 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosopher.h"

int x = 0;
pthread_mutex_t mutex;
// La differenza sostanziale tra processi e threads è che più threads possono fare parte dello stesso processo, e in quanto tali condividono lo spazio di memoria 

void    *routine(void *)
{
    int i = -1;
    while (++i < 10000000)
    {
        pthread_mutex_lock();
        x++;
    }
}
void    *routine2(void *)
{
    // x++;
    printf("x: %d\n", x);
}

int main(int ac, char **av)
{
    pthread_t t1;
    pthread_t t2;

    pthread_mutex_init(&mutex, NULL);    
    // pthread_create è la funzione della libreria pthread.h che crea il thread
    if (pthread_create(&t1, NULL, &routine, NULL))     // se va a buon fine returna 0
        return (1);
    if (pthread_create(&t2, NULL, &routine, NULL))
        return (2);
    // pthread_join aspetta che termini il thread specificato (tipo wait nei processi)
    if (pthread_join(t1, NULL))
        return (4);
    if (pthread_join(t2, NULL))
        return (5);
    printf("x: %d\n", x);
    pthread_mutex_destroy(&mutex, NULL);
    return (0);
}