//
// https://en.wikipedia.org/wiki/Euclidean_algorithm
//
#include <iostream>

using namespace std;

unsigned long long int lcm (unsigned long long int a, unsigned long long int b) {
  // sould be a > b
  if (a < b)
    return lcm(b, a);

  if (b == 0)
    return a;
  else if (a % b == 0)
    return b;
  else
    return lcm ( b, a%b);
  
}

int main() {
  unsigned long long int a, b;
  unsigned long long int lc;
  
  cin >> a >> b;

  lc = lcm(a, b);

  for (int i = 0; i < lc; i++)
    cout << 1;
  cout << endl;
  
  return 0;
}
