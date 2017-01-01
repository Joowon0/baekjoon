#include <iostream>

using namespace std;

int main() {
  int num;

  cin >> num;

  int fiveNum = num/5;

  while(fiveNum >= 0) {
    if ((num - fiveNum * 5) % 3 == 0) {
      cout << fiveNum + (num - fiveNum * 5) / 3 << endl;
      return 0;
    }
    
    fiveNum--;
  }

  cout << "-1" << endl;
  
  return 0;
}
