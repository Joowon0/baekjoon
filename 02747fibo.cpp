#include <iostream>

using namespace std;

int main() {
  int nth;
  int fib[45];

  cin >> nth;

  fib[0] = 0; fib[1] = 1;

  for (int i = 2; i <= nth; i++)
    fib[i] = fib[i-1] + fib[i-2];

  cout << fib[nth] << endl;
  
  return 0;
}
