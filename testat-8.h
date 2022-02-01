#ifndef testat_8
#define testat_8 1

typedef struct {
    int n;
    double* p;
} matrix;

matrix matrix_create(int);
// Generiert eine Matrix mit n Zeilen und n Spalten

void matrix_destroy(matrix);
// Gibt den Heap-Speicher der Matrix frei

double* matrix_element(matrix A, int z, int s);
// Adresse des Elements z/s in Matrix A
// Achtung, Mathematiker-Zaehlung 1 <= (z,s) <= A.n

double matrix_det(matrix);  // ToDo
// Berechnet Determinante der Matrix

matrix matrix_sub(matrix A, int i);  // ToDo
// Berechnet Untermatrix ohne Zeile 1 Spalte i
// Achtung, Mathematiker-Zaehlung 1 <= i <= A.n
#endif
