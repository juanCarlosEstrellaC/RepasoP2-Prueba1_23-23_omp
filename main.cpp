#include <iostream>
#include <iterator>
#include <omp.h>

int main()
{
    int n = 8;
    
    int v[n];
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
    int numHilos = n / 2;
    printf("numHilos: %d\n", numHilos);

    while (numHilos > 0){
#pragma omp parallel num_threads(numHilos)
        {
            int idHilo = omp_get_thread_num();
            printf("idHilo: %d\n", idHilo);
            v[idHilo] = v[idHilo] + v[idHilo + numHilos];
        }
        numHilos = numHilos / 2;

        if (numHilos == 1 & n%2 != 0){
            v[0] = v[0] + v[n-1];
        }

        for (int i = 0; i < n; ++i)
        {
            printf("%d ", v[i]);
        }
        printf("\n");
    }
    return 0;
}
