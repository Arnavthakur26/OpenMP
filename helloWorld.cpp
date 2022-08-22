#include <iostream>
#include <omp.h>
using namespace std;

int main()
{

#pragma omp parallel
    {
        int ID = omp_get_thread_num();
        printf("Hello (%d) ", ID);
        printf("World (%d)\n", ID);
    }
}