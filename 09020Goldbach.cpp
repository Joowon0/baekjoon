#include <stdio.h>

int main() {
  int caseNum, inNum;
  bool checkFlag[1000000]; // prime -> 0
  bool skipNum;
  int goldNums[5000][2], goldTemp;

  scanf("%d", &caseNum);

  for (int i = 2; i <= 10000; i++) {    
    for (int j = 2 * i; j <= 10000; j +=i) {
      checkFlag[j] = 1;
    }  
  } 

  while(caseNum--) {
    scanf("%d", &inNum);

    int i = 2, j = inNum-2;
    goldTemp = 0;
    
    for(; i <= j;) {
      skipNum = 0;
      
      // skip non-prime numbers
      if (checkFlag[i] == 1 || checkFlag[j] == 1)
	skipNum = 1;

      //printf("i : %d %d\tj : %d %d\tskip: %d\n", i, checkFlag[i], j, checkFlag[j], skipNum);

      // if not skip case, test if answer
      if (!skipNum && i + j == inNum) {
	goldNums[goldTemp][0] = i;
	goldNums[goldTemp][1] = j;
	goldTemp++;
      }

      // skip
      if (i+j > inNum)
	j--;
      else
	i++;
    }
    printf("%d %d\n", goldNums[goldTemp-1][0], goldNums[goldTemp-1][1]);
  }
  
  return 0;
}
