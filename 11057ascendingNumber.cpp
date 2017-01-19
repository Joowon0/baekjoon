#include <iostream>

using namespace std;

int main() {
  int inNum, memo[1001][10];

  cin >> inNum;

  for (int i = 0; i < 10; i++)
    memo[1][i] = 1;

  for (int i = 2; i <= inNum; i++) {
    memo[i][0] = memo[i-1][0];

    // for every number
    for (int n = 1; n < 10; n++) {
      // add [0..n]
      int temp = memo[i-1][0];
      
      for (int j = 1; j <= n; j++)
	temp = (temp + memo[i-1][j]) % 10007;

      memo[i][n] = temp % 10007;
    }
  }
  /*
  for (int i = 1; i <= inNum; i++) {
    for (int j = 0; j < 10; j++)
      cout << memo[i][j] << " ";
    cout << endl;
  }
  */

  int temp = 0;
  for (int i = 0; i < 10; i++)
    temp = (temp + memo[inNum][i]) % 10007;
  cout << temp % 10007 << endl;
  
  return 0;
}
