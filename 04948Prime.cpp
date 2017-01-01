#include <stdio.h>

using namespace std;

int main() {
  int a;
  bool checkFlag[1000000]; // prime -> 0
  int countPrime;

  for (int i = 2; i <= 2 * 123456; i++) {    
    for (int j = 2* i; j <= 2 * 123456; j +=i) {
      checkFlag[j] = 1;
    }  
  }

  while(1) {
    scanf("%d", &a);
    if (a == 0)
      break;

    countPrime = 0;
    
    for (int i = 2; i <= 2 * a; i++) {
      if (i > a && checkFlag[i] == 0) {
	//printf("%d is prime %d\n", i, countPrime);
	countPrime++;
      }    
    }
    printf("%d\n", countPrime);
  }
  
  return 0;
}
