#include <stdio.h>

int a= 0, b= 0;

int fib(int n) {
    if (n==0) {
        a++;
        return 0;
    } else if (n==1) {
        b++;
        return 1;
    } else {
      return fib(n-1) + fib(n-2);
    }
}

int main() {
  int caseNum, nth;

  scanf("%d", &caseNum);

  while(caseNum--) {
    scanf("%d", &nth);

    a = 0; b = 0;
    fib(nth);

    printf("%d %d\n", a, b);
  }
  
  return 0;
}
