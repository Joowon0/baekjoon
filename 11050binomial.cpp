#include <iostream>

using namespace std;

int main() {
  int n, k;
  unsigned long long numer = 1, deno = 1; 

  cin >> n >> k;

  for(int i = 0; i < k; i++)
    numer *= (n - i);
  for(int i = 2; i <= k; i++)
    deno *= i;
  //cout << numer << " " << deno << endl;

  cout << numer / deno << endl;
  
  return 0;
}
