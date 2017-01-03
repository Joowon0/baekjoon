#include <stdio.h>

int main() {
  int inNum;
  int n2 = 0;
  int n5 = 0;

  scanf("%d", &inNum);

  for (int i = 1; i <= inNum; i++) {
    int x = i;
    while(x % 2 == 0) {
      x /= 2;
      n2++;
    }
    while(x % 5 == 0) {
      x /= 5;
      n5++;
    }
  }
    
  if ( n2 > n5 )
    printf("%d\n", n5);
  else
    printf("%d\n", n2);
  
  return 0;
}
