//
// read https://www.acmicpc.net/blog/view/28
//
#include <iostream>

using namespace std;

int main() {
  unsigned long long nth;
  int fib[1500000];

  cin >> nth;

  fib[0] = 0; fib[1] = 1;

  for (int i = 2; i < 1500000; i++) {
    fib[i] = fib[i-1] + fib[i-2];
    fib[i] %= 1000000;
  }

  nth %= 1500000;

  

  cout << fib[nth] << endl;
  
  return 0;
}
