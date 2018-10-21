#include <iostream>

using namespace std;

long long dp[31][31];

long long combi(int n, int k) {
  if (dp[n][k] != 0)
    return dp[n][k];
  else {
    if (k == 0 || n == k)
      dp[n][k] = 1;
    else if (k == 1)
      dp[n][k] = n;
    else
      dp[n][k] = combi(n-1, k-1) + combi(n-1, k);
    return dp[n][k];
  }
}

int main () {
  int nums;
  cin >> nums;

  while(nums--) {
    int left, right;
    cin >> left >> right;

    cout << combi(right, left) << endl;
  }
  
  return 0;
}
