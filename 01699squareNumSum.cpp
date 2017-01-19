#include <iostream>

using namespace std;

int inNum;
int squareSum[350], bound;
int memo[100001];

int cal(int x) {
  // if calculated b4
  if (memo[x] != 0)
    return memo[x];

  // DP
  int temp, sum = x;
  for (int i = 1; i < bound; i++) {
    if (squareSum[i] > x)
      break;

    temp = 1 + cal(x - squareSum[i]);
    if (sum > temp)
      sum = temp;
  }

  memo[x] = sum;
  return sum;
}

int main() {
  cin >> inNum;

  // fill in squareSum[]
  for (bound = 1; bound < 350; bound++) {
    squareSum[bound] = bound * bound;
    memo[squareSum[bound]] = 1; // basecase

    if (squareSum[bound] > inNum)
      break;
  }

  // print for test
  /*
  for (int i = 1; i <= bound; i++)
    cout << squareSum[i] << " ";
  cout << endl;
  */

  cout << cal(inNum) << endl;
  
  return 0;
}
