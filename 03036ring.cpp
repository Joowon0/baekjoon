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
  int ringNum;
  int r1, rings[100];
  int lc;

  cin >> ringNum;

  cin >> r1;
  for (int i = 0; i < ringNum - 1; i++)
    cin >> rings[i];

  for (int i = 0; i < ringNum - 1; i++) {
    lc = lcm(r1, rings[i]);

    cout << (r1/lc) << "/" << (rings[i]/lc) << endl;
  }
  
  return 0;
}
