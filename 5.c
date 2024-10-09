#include <stdio.h>
#include <omp.h>

double calcular_pi(int num_iteraciones) {
    double pi = 0.0;
    int i;

    #pragma omp parallel for reduction(+:pi) num_threads(3)
    for (i = 0; i < num_iteraciones; i++) {
        pi += (i % 2 == 0 ? 1.0 : -1.0) / (2.0 * i + 1.0);
    }

    return pi * 4.0;
}

int main() {
    int iteraciones = 1000000;
    double pi;

    pi = calcular_pi(iteraciones);

    printf("Valor aproximado de pi con %d iteraciones: %.15f\n", iteraciones, pi);

    return 0;
}
