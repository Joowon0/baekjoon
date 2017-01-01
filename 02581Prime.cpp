#include <iostream>

using namespace std;

int main() {
  int a, b;
  int sum = 0, min = -1;
  int checkFlag;

  cin >> a >> b;

  for (int i = a; i <= b; i++) {
    checkFlag = 0;
    if (i == 1)
      checkFlag = 1;
    for (int j = 2; j < i; j++) {
      if (i % j == 0) {
	checkFlag = 1;
	break;
      }
    }
    if (checkFlag == 0) {
      //cout << i << " is a prime" << endl;
      sum += i;
      if (min == -1)
	min = i;

    
    }
  }

  if (min == -1)
    cout << -1 << endl;
  else {
    cout << sum << endl
	 << min << endl;
  }
  return 0;
}
