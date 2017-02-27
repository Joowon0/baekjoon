#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int caseNum;
  int inNum[1000000];

  cin >> caseNum;
  for (int i = 0; i < caseNum; i++)
    cin >> inNum [i];

  sort(inNum, inNum + caseNum);

  for (int i = 0; i < caseNum; i++)
    cout << inNum[i] << endl;
  
  
  return 0;
}
