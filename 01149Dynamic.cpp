#include <stdio.h>

int main() {
  int caseNum;
  int rIn, gIn, bIn;
  int base[1000][3], temp;

  scanf("%d", &caseNum);
  
  scanf("%d %d %d", &rIn, &gIn, &bIn);
  base[0][0] = rIn;
  base[0][1] = gIn;
  base[0][2] = bIn;
  
  for (int i = 1; i < caseNum; i++) {
    scanf("%d %d %d", &rIn, &gIn, &bIn);

    // calcul r
    temp = base[i-1][1];
    if (temp > base[i-1][2])
      temp = base[i-1][2];
    base[i][0] = temp + rIn;

    // calcul g
    temp = base[i-1][0];
    if (temp > base[i-1][2])
      temp = base[i-1][2];
    base[i][1] = temp + gIn;

    // calcul b
    temp = base[i-1][0];
    if (temp > base[i-1][1])
      temp = base[i-1][1];
    base[i][2] = temp + bIn;
    
  }

  temp = base[caseNum-1][0];
  if (temp > base[caseNum-1][1])
    temp =  base[caseNum-1][1];
  if (temp >  base[caseNum-1][2])
    temp = base[caseNum-1][2];

  printf("%d\n", temp);
  
  return 0;
}
