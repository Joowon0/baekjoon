#include <stdio.h>

using namespace std;

int main() {
  int caseNum, x, y, cnt = 1;

  scanf("%d", &caseNum);
  
  while(caseNum-- ) {
    scanf("%d %d", &x, &y);
      
    printf("Case #%d: %d\n", cnt++, x+y);
  }
  
  return 0;
}
