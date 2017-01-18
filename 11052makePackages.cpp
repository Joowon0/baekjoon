#include <iostream>

using namespace std;

int caseNum, costs[1001];
int memo[1001];

int cal(int x) {
  // basecase
  if (x == 1)
    return costs[1];

  // if calculated b4
  if (memo[x] != 0)
    return memo[x];

  // DP
  int temp, max;

  max = costs[x];
  for (int i = 1; i <= x / 2; i++) {
    temp = cal(i) + cal(x - i);
    if (max < temp)
      max = temp;
  }

  memo[x] = max;

  return max;
}


int main () {
  cin >> caseNum;

  for (int i = 1; i <= caseNum; i++)
    cin >> costs[i];

  cout <<cal(caseNum) << endl;
  
  return 0;
}
