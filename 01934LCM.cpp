//
// https://en.wikipedia.org/wiki/Euclidean_algorithm
//
#include <iostream>

using namespace std;

int lcm (int a, int b) {
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
  int caseNum;
  int a, b;
  int lc;

  cin >> caseNum;
  
  while(caseNum--) {
    cin >> a >> b;

    lc = lcm(a, b);

    cout << a * (b / lc) << endl;
  }
  
  return 0;
}
