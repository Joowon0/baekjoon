#include <stdio.h>
#include <string.h>

int rowNum, colNum;
int mapIn[501][501];
int memo[501][501];

int findWay(int r, int c) {
  //printf("%d %d\n", r, c);
  // if calculated b4
  if (memo[r][c] != -1)
    return memo[r][c];
  
  // base case
  //if (r == rowNum - 1 && c == colNum - 1)
  //  return 1;

  // DP
  int pathNum = 0;
  
  // right
  if (c + 1 <= colNum - 1 && mapIn[r][c] > mapIn[r][c+1])
    pathNum += findWay ( r, c + 1); 
 
  // down
  if (r + 1 <= rowNum - 1 && mapIn[r][c] > mapIn[r+1][c])
    pathNum += findWay ( r + 1, c);
  
  // up
  if (r - 1 >= 0 && mapIn[r][c] > mapIn[r-1][c])
    pathNum += findWay ( r - 1, c);
  // left
  if (c - 1 >= 0 && mapIn[r][c] > mapIn[r][c-1])
    pathNum += findWay ( r, c - 1);
  
  memo[r][c] = pathNum;
  //printf("return [%d][%d] = %d\n", r, c, pathNum);
  return pathNum;
}

int main() {
  // get inputs
  scanf("%d %d", &rowNum, &colNum);

  for (int i = 0; i < rowNum; i++)
    for (int j = 0; j < colNum; j++)
      scanf("%d", &mapIn[i][j]);

  // reset and base case
  memset( memo, -1, sizeof(int) * 501 * 501);
  memo[rowNum - 1][colNum - 1] = 1;

  // print for test
  /*
  for (int i = 0; i < rowNum; i++) {
    for (int j = 0; j < colNum; j++)
      printf("%d ", mapIn[i][j]);
    printf("\n");
  }
  */

  printf("%d\n", findWay(0,0));
  
  return 0;
}
