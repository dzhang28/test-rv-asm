#include <stdio.h>

#ifdef NO_INLINE
__attribute__((noinline))
#endif
double testFlrd(double *a, int index)
{
#ifdef USE_ASM
    asm volatile("flrd fa0, a0, a1, 3\n\t");
#else
    return a[index];
#endif
}

int main()
{
    double a[] = { 1.5, 2.25, 3.75, 4.375, 5.625, 6.125 };
    double r;
    int index;

    printf("Input the index: ");
    scanf("%d", &index);

    r = testFlrd(a, index);
    printf("result = %lf\n", r);

    return 0;
}


