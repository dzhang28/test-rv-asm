#include <stdio.h>

__attribute__((noinline))
int vtmaskc(int c, int v)
{
#ifndef MY_ASM
  return c != 0 ? v : 0;
#else
  __asm__ __volatile__ (
    "vt.maskc a0, a1, a0\n\t"
  );
#endif
}

int main()
{
  int cond, val;

  printf("Input the condition: ");
  scanf("%d", &cond);
  
  printf("Input the value: ");
  scanf("%d", &val);
  
  printf("vtmaskC(condition, value) = %d\n", vtmaskc(cond, val));

  return 0;
}
