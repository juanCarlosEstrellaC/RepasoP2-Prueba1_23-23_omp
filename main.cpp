#include <iostream>
#include <iterator>
#include <omp.h>

int main()
{
    int v[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int numHilos = std::size(v) / 2;
    printf("numHilos: %d\n", numHilos);

    while (numHilos > 0){
#pragma omp parallel num_threads(numHilos)
        {
            int idHilo = omp_get_thread_num();
            printf("idHilo: %d\n", idHilo);
            v[idHilo] = v[idHilo] + v[idHilo + numHilos];
        }
        numHilos = numHilos / 2;

        for (int i = 0; i < std::size(v); ++i)
        {
            printf("%d ", v[i]);
        }
        printf("\n");
    }

    return 0;
}
