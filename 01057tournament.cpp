#include <iostream>

using namespace std;

int main() {
  int caseNum;
  int a, b;
  int i;

  cin >> caseNum >> a >> b;

  // b > a
  if (b < a) {
    i = b;
    b = a;
    a = i;
  }
    
  i = 1;
  while (caseNum > 1) {
    // end case
    if ( (b - a == 1) && a % 2 == 1 && b % 2 == 0) {
      cout << i << endl;
      break;
    }

    a = (a+1) / 2;
    b = (b+1) / 2;
    if (caseNum % 2 == 1)
      caseNum += 1;
    caseNum /= 2;

    //cout << caseNum << " " << a << " " << b << endl;
    i++;
  }
  
  return 0;
}
