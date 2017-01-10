#include <stdio.h>

int main() {
  int caseNum, inVal[10001];
  int base[10001][3], temp;
  // base[n][0] - not included base[n-2][x] and base[n-1][x]
  // base[n][1] - not included base[n-1][x] but might include base[n-2][x]
  // base[n][2] - might included base[n-1][x] or base[n-2][x]

  scanf("%d", &caseNum);

  for (int i = 0; i < caseNum; i++)
    scanf("%d", &inVal[i]);

  if (caseNum == 1) {
    printf("%d\n", inVal[0]);
    return 0;
  }
  else if (caseNum == 2) {
    printf("%d\n", inVal[0] + inVal[1]);
    return 0;
  }

  base[0][0] = inVal[0];
  base[0][1] = inVal[0];
  base[0][2] = inVal[0];

  base[1][0] = inVal[1];
  base[1][1] = inVal[0] + inVal[1];
  base[1][2] = inVal[0] + inVal[1];

  base[2][0] = inVal[2];
  base[2][1] = inVal[0] + inVal[2];
  temp = inVal[0];
  if (temp < inVal[1])
    temp = inVal[1];
  base[2][2] = temp + inVal[2];

  for (int i = 3; i < caseNum; i++) {
    // base[n][0] - not included base[n-2][x] and base[n-1][x]
    temp = base[i-3][2];
    if (temp < base[i-3][1])
      temp = base[i-3][1];
    if (temp < base[i-3][0])
      temp = base[i-3][0];
    
    base[i][0] = temp + inVal[i];
    
    // base[n][1] - not included base[n-1][x] but might include base[n-2][x]
    if (temp < base[i-2][2])
      temp = base[i-2][2];
    if (temp < base[i-2][1])
      temp = base[i-2][1];
    if (temp < base[i-2][0])
      temp = base[i-2][0];

    base[i][1] = temp + inVal[i];
    
    // base[n][2] - might included base[n-1][x] or base[n-2][x]
    if (temp < base[i-1][1])
      temp = base[i-1][1];
    if (temp < base[i-1][0])
      temp = base[i-1][0];

    base[i][2] = temp + inVal[i];
  }

  /*
  for (int i = 0; i < caseNum; i++)
    printf("%d : %d %d %d\n", i, base[i][0], base[i][1], base[i][2]);

  printf("%d %d %d\n", base[caseNum-2][0], base[caseNum-2][1], base[caseNum-2][2]);
  printf("%d %d %d\n", base[caseNum-1][0], base[caseNum-1][1], base[caseNum-1][2]);
  */
  temp = base[caseNum-2][0];
  if (temp < base[caseNum-2][1])
    temp = base[caseNum-2][1];
  if (temp < base[caseNum-2][2])
    temp = base[caseNum-2][2];

  if (temp < base[caseNum-1][0])
    temp = base[caseNum-1][0];
  if (temp < base[caseNum-1][1])
    temp = base[caseNum-1][1];
  if (temp < base[caseNum-1][2])
    temp = base[caseNum-1][2];

  printf("%d\n", temp);
  
  return 0;
}
