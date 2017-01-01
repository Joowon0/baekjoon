#include <stdio.h>

using namespace std;

int main() {
  int a, b;
  bool checkFlag[1000000];

  scanf("%d %d", &a, &b);

  for (int i = 2; i <= b; i++) {
    if (i >= a && checkFlag[i] == 0)
      printf("%d\n", i);
    
    for (int j = i; j <= b; j +=i) {
      checkFlag[j] = 1;
    }
    
  }
  
  return 0;
}
