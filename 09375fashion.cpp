#include <stdio.h>
#include <string.h>

int main() {
  int caseNum, clothNum;
  char clothIn[30], classIn[30];
  
  char clothClass[40][30];
  int clothClassNum[40], clothTotal;
  bool isIn;
  int countResult;
  

  scanf("%d", &caseNum);

  while(caseNum--) {
    scanf("%d", &clothNum);
    clothTotal = 0;

    while(clothNum--) {
      scanf("%s %s", clothIn, classIn);

      isIn = 0;
      for (int i = 0; i < clothTotal; i++) {
	if (!strcmp(classIn, clothClass[i])) {
	  clothClassNum[i]++;
	  isIn = 1;
	}
      }
      if (!isIn) { // add if not in clothClass[]
	strcpy(clothClass[clothTotal], classIn);
	clothClassNum[clothTotal] = 1;
	clothTotal++;
      }
      
    }
    // print for test
    /*
    for (int i = 0; i < clothTotal; i++)
      printf("%d %s\n", clothClassNum[i], clothClass[i]);
    printf("\n");
    */
    countResult = 1;
    for(int i = 0; i < clothTotal; i++) {
      countResult *= (clothClassNum[i] + 1);
      //printf("%d %d\n", countResult, clothClassNum[i]);
    }
    
    printf("%d\n", countResult-1);
  }
  
  return 0;
}
