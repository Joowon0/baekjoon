#include <iostream>

using namespace std;

int main() {
  int caseNum;
  int endA, endB, targetA, targetB;
  long endPoint, tempA, tempB;

  cin >> caseNum;

  while (caseNum--) {
    cin >> endA >> endB >> targetA >> targetB;

    endPoint = endA * endB;
    tempA = targetA;
    tempB = targetB;

    while (1) {
      if (tempA > endPoint || tempB > endPoint) {
	cout << -1 << endl;
	break;
      }
      
      if (tempA == tempB) {
	cout << tempA << endl;
	break;
      }
      else if (tempA > tempB) {
	tempB += endB;
      }
      else {
	tempA += endA;
      }
    }
    
  }
  
  return 0;
}
