#include <stdio.h>

int busCost[1000][1000]; // if no bus, 100000
int cityNum, busNum;
int srcCity, dstCity;
int tempA, tempB, tempC;

int rec_findMinCost(int arrivedCity, bool ifVisit[]) {
  // base case
  if (arrivedCity == srcCity-1)
    return 0;

  // recursive
  int minCost = 1000000;
  for (int i = 0; i < cityNum; i++)
    if (!ifVisit[i] && busCost[i][arrivedCity] < 1000000) {
      ifVisit[i] = true;
      int temp = rec_findMinCost(i, ifVisit) + busCost[i][arrivedCity];

      if (temp < minCost)
	minCost = temp;

      //printf("i : %d, arrCity : %d, cost: %d, temp : %d, min: %d\n",
      //	     i+1, arrivedCity+1, busCost[i][arrivedCity], temp, minCost);
      
      ifVisit[i] = false;
    }

  return minCost;
}

int main() {  
  scanf("%d %d", &cityNum, &busNum);

  // initialize
  for (int i = 0; i < cityNum; i++) {
    for (int j = 0; j < cityNum; j++)
      busCost[i][j] = 1000000;
  }

  // get inputs
  while(busNum--) {
    scanf("%d %d %d", &tempA, &tempB, &tempC);
    if (busCost[tempA-1][tempB-1] > tempC)
      busCost[tempA-1][tempB-1] = tempC;
  }
  scanf("%d %d", &srcCity, &dstCity);

  bool ifVisit[cityNum];
  for (int i = 0; i < cityNum; i++)
    ifVisit[i] = false;
  ifVisit[dstCity-1] = true;
  
  // print for test
  /*
  for (int i = 0; i < cityNum; i++) {
    for (int j = 0; j < cityNum; j++)
      printf("%d ", busCost[i][j]);
    printf("\n");
  }
  */

  printf("%d\n", rec_findMinCost(dstCity-1, ifVisit));

  
  return 0;
}
