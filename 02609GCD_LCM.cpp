//
// https://en.wikipedia.org/wiki/Euclidean_algorithm
//
#include <iostream>

using namespace std;

long long int lcm (long long int a, long long int b) {
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
  long long int a, b;
  long long int lc;
  
  cin >> a >> b;

  lc = lcm(a, b);

  cout << lc << endl;
  cout << a * (b / lc) << endl;
  
  
  return 0;
}
