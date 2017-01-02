#include <iostream>

using namespace std;

int main() {
  int nth;
  unsigned long long fib[10000];

  cin >> nth;

  fib[0] = 0; fib[1] = 1;
  fib[30] = 832040; fib[31]= 1346269;
  fib[60] = 1548008755920; fib[61] = 2504730781961;

  if (nth <30) {
    for (int i = 2; i <= nth; i++)
      fib[i] = fib[i-1] + fib[i-2];
  }
  else if (nth < 60) {
    for (int i = 32; i <= nth; i++)
      fib[i] = fib[i-1] + fib[i-2];
  }
  else {
    for (int i = 62; i <= nth; i++)
      fib[i] = fib[i-1] + fib[i-2];
  }

  cout << fib[nth] << endl;
  
  return 0;
}
