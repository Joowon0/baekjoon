#include <stdio.h>

int main() {
  int caseNum;
  int tri[500][500], temp;

  scanf("%d", &caseNum);


  
  scanf("%d", &tri[0][0]);
  
  if (caseNum == 1) { 
    printf("%d", tri[0][0]);
    return 0;
  }
  else {
    for (int i = 1; i < caseNum; i++) {
      for (int j = 0; j < i + 1; j++) 
	scanf("%d", &tri[i][j]);
      
      // first one
      tri[i][0] += tri[i-1][0];
      // middle ones
      for (int j = 1; j < i; j++) {
	temp = tri[i-1][j-1];
	if (temp < tri[i-1][j])
	  temp = tri[i-1][j];
	tri[i][j] += temp;
      }
      // last one
      tri[i][i] += tri[i-1][i-1];
    }
    // print for test
    /*
    for (int i = 0; i < caseNum; i++) {
      for (int j = 0; j < i+1; j++) {
	printf("%d ", tri[i][j]);
      }
      printf("\n");
    }
    */

    temp = tri[caseNum-1][0];
    for (int i = 1; i < caseNum; i++) {
      if (temp < tri[caseNum-1][i])
	temp = tri[caseNum-1][i];
    }
    printf("%d\n", temp);
  }
  
  return 0;
}
