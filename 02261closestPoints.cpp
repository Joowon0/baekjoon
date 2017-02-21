#include <stdio.h>
#include <math.h>

int dist (int p1[2], int p2[2]) {
  return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
}

int main() {
  int caseNum;
  int points[100000][2];
  int temp, min;

  scanf("%d", &caseNum);
  for (int i = 0; i < caseNum; i++)
    scanf("%d %d", &points[i][0], &points[i][1]);

  min = 400000000;
  for (int i = 0; i < caseNum; i++)
    for (int j = i+1; j < caseNum; j++) {
      /*
      printf("(%d, %d), \t(%d, %d) :\t%d\n",
	     points[i][0], points[i][1],
	     points[j][0], points[j][1],
	     dist(points[i], points[j]));
      */
      temp = dist(points[i], points[j]);
      if (min > temp)
	min = temp;
    }

  printf("%d\n", min);
  return 0;
}
