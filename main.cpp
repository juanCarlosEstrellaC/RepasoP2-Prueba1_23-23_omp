#include <iostream>
#include <omp.h>

void imprimir(float v[], int N)
{
    for (int i = 0; i < N; ++i)
    {
        printf("%.1f ", v[i]);
    }
    printf("\n");
}

int main()
{
    int N = 9;
    printf("N: %d\n", N);

    float v[N];
    for (int i = 0; i < N; ++i)
    {
        v[i] = static_cast<float>(i);
    }
    //int numHilos = (N % 2 == 0) ? N / 2 : N / 2 + 1;
    int numHilos = N/2;
    printf("numHilos: %d\n", numHilos);
    imprimir(v, N);

    while (numHilos > 0)
    {
#pragma omp parallel default(none) shared(numHilos, N, v) num_threads(numHilos)
        {
            int idHilo = omp_get_thread_num();
            //printf("idHilo: %d\n", idHilo);
            if (idHilo + numHilos < N)
            {
                v[idHilo] = v[idHilo] + v[idHilo + numHilos];
            }
        }
        numHilos = numHilos / 2;

        if (numHilos == 1 & N%2 != 0){
            v[0] = v[0] + v[N-1];
        }
        imprimir(v, N);
    }
    return 0;
}
