#include <iostream>
#include <omp.h>
#include <cstdlib>

using namespace std;

int main() {
    const int N = 1000;
    int A[N], B[N], R[N];

    // Inicializar arreglos con valores aleatorios
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

    // Suma paralela usando OpenMP
#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        R[i] = A[i] + B[i];
    }

    // Mostrar algunos resultados
    for (int i = 0; i < 10; i++) {
        cout << "A[" << i << "] = " << A[i]
            << " + B[" << i << "] = " << B[i]
            << " -> R[" << i << "] = " << R[i] << endl;
    }

    return 0;
}
