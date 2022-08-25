#include <iostream>
#include <omp.h>
using namespace std;

static long num_steps = 100000000;
double step;

#define NUM_THREADS 4

int main()
{
    double before = omp_get_wtime();
    double pi = 0.0;
    step = 1.0 / (double)num_steps;

    omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
    {
        int id, nthrds;
        double x, sum = 0.0;

        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();

        for (int i = id; i < num_steps; i = i + nthrds)
        {
            x = (i + 0.5) * step;
            sum += 4.0 / (1.0 + x * x);
        }
#pragma omp critical
        pi += step * sum;
    }
    printf("\nValue of pi : %lf\n", pi);
    double after = omp_get_wtime();
    printf("Time elapsed(after parallelization): %lf\n", after - before);
}