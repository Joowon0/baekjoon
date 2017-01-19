//
// https://en.wikipedia.org/wiki/Euclidean_algorithm
//
//#include <iostream>
#include <stdio.h>
#include <stdlib.h>     /* qsort */

//using namespace std;

long long int lcm (long long int a, long long int b) {
  // sould be a > b
  if (a < b)
    return lcm(b, a);

  if (b == 0)
    return a;
  else if (a % b == 0)
    return b;
  else
    return lcm ( b, a%b);
  
}

int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

// num in       : a b c d
// equls to     : a+x1 a+x1+x2 a+x1+x2+x3 a+x1+x2+x3+x4
// what we want : a+x1 % z = a+x1+x2 % z = a+x1+x2+x3 % z + a+x1+x2+x3+x4 % z = ...
//                0 = x1 % z = x2 % z = x3 % z = x4 % z
//                z = factors( GCD(x1, x2, x3, x4) )
int main() {
  int caseNum;
  int nums[100], diff[100]; // diff[n] : nums[n+1] - nums[n]
  int lc;

  //cin >> caseNum;
  scanf("%d", &caseNum);

  for (int i = 0; i < caseNum; i++)
    scanf("%d", &nums[i]);
    //cin >> nums[i];
  qsort (nums, caseNum, sizeof(int), compare);
  for (int i = 0; i < caseNum - 1; i++)
    diff[i] = nums[i+1] - nums[i];

  /*
  // print for test
  for (int i = 0; i < caseNum - 1; i++)
    printf("%d ", diff[i]);
    //cout << diff[i] << " ";
  //cout << endl;
  printf("\n");
  */

  lc = diff[0];
  for (int i = 1; i < caseNum - 1; i++)
    lc = lcm(lc, diff[i]);

  /*
  // print for test
  cout << lc << endl;
  */

  for (int i = 2; i <= lc/2; i++)
    if (lc % i == 0)
      printf("%d ", i);
      //cout << i << endl;
  printf("%d\n", lc);
}
