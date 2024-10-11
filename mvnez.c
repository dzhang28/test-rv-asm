#include <stdio.h>

#ifdef NO_INLINE
__attribute__((noinline))
#endif
int testCondMov(int condition, int value)
{
#ifdef USE_ASM
    asm volatile ("mvnez a0, a1, a0\n\t" :
                  "+r"(condition) :
                  "r"(value));
#else
    return condition != 0 ? value : 0;
#endif
}

int main()
{
    int cond, val, result;

    printf("Input the condition: ");
    scanf("%d", &cond);

    printf("Input the value: ");
    scanf("%d", &val);

    result = testCondMov(cond, val);
    printf("testCondMov(condition, value) = %d\n", result);

    return 0;
}
