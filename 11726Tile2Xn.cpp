#include <iostream>

using namespace std;

int main() {
  int target, memo[1001];

  cin >> target;

    
  memo[1] = 1;
  memo[2] = 2;

  for (int i = 3; i <= target; i++) {
    memo[i] = (memo[i-1] + memo[i-2]) % 10007;    
  }

  cout << memo[target] % 10007 << endl;
  
  return 0;
}
