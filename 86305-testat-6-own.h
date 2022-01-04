#ifndef testat_6
#define testat_6 1

typedef struct  {
   double a;
   double b;
   double c;
} polynom;

void bsort(
   void *base,
   size_t nel,
   size_t width,
   int (*compar)(const void *, const void *)
);

int cmp_polynom(const void *p1, const void  *p2);
void print_polynome(polynom p[], int n);

#endif