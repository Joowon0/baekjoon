#include <iostream>

using namespace std;

unsigned long long asdf[1000][1000];

unsigned long long combi(int n, int k) {
  if (asdf[n][k] == 0) {
    asdf[n][k] = combi(n-1, k-1) % 10007 + combi(n-1, k) % 10007;
    asdf[n][k] %= 10007;
  }
  
  return asdf[n][k];
}

int main() {
  int n, k;
  unsigned long long myAnswer;

  cin >> n >> k;

  // base case combi(2, k)
  asdf[1][0] = 1;
  asdf[1][1] = 1;
  
  asdf[2][0] = 1;
  asdf[2][1] = 2;
  asdf[2][2] = 1;
  // base case combi(n, 0)
  for (int i = 3; i <= n; i++)
    asdf[i][0] = 1;
  // base case combi(n, n)
  for (int i = 3; i <= n; i++)
    asdf[i][i] = 1;
    
  myAnswer = combi( n, k);
  
  cout << myAnswer % 10007 << endl;
  
  return 0;
}
