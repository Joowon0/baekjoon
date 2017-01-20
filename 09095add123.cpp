#include <iostream>

using namespace std;

int cal123(int x) {
  // basecase
  if (x == 1)
    return 1;
  else if (x == 2)
    return 2;
  else if (x == 3)
    return 4;

  return cal123(x-1) + cal123(x-2) + cal123(x-3);
}

int main() {
  int caseNum, inNum;
  

  cin >> caseNum;

  while(caseNum--) {
    cin >> inNum;

    cout << cal123(inNum) << endl;
  }
  
  return 0;
}
