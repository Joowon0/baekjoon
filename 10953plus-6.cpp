#include <stdio.h>

using namespace std;

int main() {
  int caseNum, x, y;

  scanf("%d", &caseNum);
  
  while(caseNum-- ) {
    scanf("%d,%d", &x, &y);
      
    printf("%d\n", x+y);
  }
  
  return 0;
}
