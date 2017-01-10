#include <stdio.h>

int main() {
  int caseNum, inVal[10001];
  int base[10001][2], temp;
  // base[n][0] - not included base[n-1][x]
  // base[n][1] - might included base[n-1][x]

  scanf("%d", &caseNum);

  for (int i = 0; i < caseNum; i++)
    scanf("%d", &inVal[i]);

  if (caseNum == 1)
    return inVal[0];
  else if (caseNum == 2)
    return inVal[0] + inVal[1];
  
  base[0][0] = inVal[0];
  base[0][1] = inVal[0];

  base[1][0] = inVal[1];
  base[1][1] = inVal[0] + inVal[1];

  for (int i = 2; i < caseNum; i++) {
    // base[n][0] - not included base[n-1][x]
    temp = base[i-2][0];
    if (temp < base[i-2][1])
      temp = base[i-2][1];

    base[i][0] = temp + inVal[i];

    // base[n][1] - might included base[n-1][x]
    if (temp < base[i-1][0])
      temp = base[i-1][0];

    base[i][1] = temp + inVal[i];
  }

  /*
  for (int i = 0; i < caseNum; i++)
    printf("%d : %d %d\n", i, base[i][0], base[i][1]);

  printf("%d %d %d\n", base[caseNum-2][1], base[caseNum-1][0], base[caseNum-1][1]);
  */
  temp = base[caseNum-1][1];
  if (temp < base[caseNum-2][1])
    temp = base[caseNum-2][1];
  
  printf("%d\n", temp);
  
  return 0;
}
