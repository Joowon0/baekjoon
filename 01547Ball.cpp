#include <iostream>

using namespace std;

int main() {
  int caseNum;
  int a, b;
  int ballplace = 1;

  cin >> caseNum;

  while(caseNum--) {
    cin >> a >> b;

    if (a == ballplace)
      ballplace = b;
    else if (b == ballplace)
      ballplace = a;
    
  }

  cout << ballplace << endl;
  
  return 0;
}
