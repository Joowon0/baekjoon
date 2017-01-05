#include <iostream>

using namespace std;

unsigned long long w[101];

unsigned long long whirl (int n) {
  if (n == 1 || n == 2 || n == 3)
    return 1;
  else if (n == 4 || n == 5)
    return 2;
  else {
    if (w[n-5] == 0)
      w[n-5] = whirl(n-5);
    if (w[n-1] == 0)
      w[n-1] = whirl(n-1);
    return w[n-5] + w[n-1];
  }
}

int main () {
  int caseNum, inNum;

  cin >> caseNum;
  while(caseNum--) {
    cin >> inNum;
    cout << whirl(inNum) << endl;
  }
  
  return 0;
}
