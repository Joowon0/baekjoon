#include <iostream>

using namespace std;

int main() {
  int caseNum;
  long long int memo[91][2]; // count case of 0
                   // [n][0] : [n] is 0
                   // [n][1] : [n] is 1

  cin >> caseNum;

  memo[1][0] = 0;
  memo[1][1] = 1;
  memo[2][0] = 1;
  memo[2][1] = 0;

  for (int i = 3; i<= caseNum; i++) {
    memo[i][0] = memo[i-1][0] + memo[i-1][1];
    memo[i][1] = memo[i-1][0];
  }

  /*
  for (int i = 1; i <= caseNum; i++)
    cout << memo[i][0] << " " << memo[i][1] << endl;
  */
  cout << memo[caseNum][0] + memo[caseNum][1] << endl;
  
  return 0;
}
