#include <stdio.h>

#ifdef NO_INLINE
__attribute__((noinline))
#endif
int testTst3(int value)
{
#ifdef USE_ASM
    asm volatile("tst a0, a0, 3\n\t");
#else
    return (value & 8) != 0 ? 1 : 0;
#endif
}

int main()
{
    int val, result;

    printf("Input the value: ");
    scanf("%d", &val);

    result = testTst3(val);
    printf("testTst3(value) = %d\n", result);

    return 0;
}


