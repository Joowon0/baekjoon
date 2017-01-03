#include <iostream>

using namespace std;

int asdf[1000][1000];

int combi(int n, int k) {
  if (k > n-k)
    k = n-k;

  // base case combi(n, 0)
  if (k == 0)
    return 1;
  else if (k == 1)
    return n;
  else if (n < 1000) {
    if (asdf[n][k] == 0) {
      asdf[n][k] = combi(n-1, k-1) + combi(n-1, k);
    } 
    return asdf[n][k];
  }
  else {
    return combi(n-1, k-1) + combi(n-1, k);
  }
}

int main() {
  int n, k;

  while(1) {
    cin >> n >> k;
    
    if (n == 0) // end
      break;
    
    cout << combi(n, k) << endl;
  }
  
  return 0;
}
