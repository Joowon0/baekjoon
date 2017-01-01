#include <iostream>

using namespace std;

int main() {
  int caseNum, inNum;
  int checkFlag, countPrime = 0;

  cin >> caseNum;
  
  while (caseNum--) {
    cin >> inNum;

    checkFlag = 1;
    if (inNum == 1)
      checkFlag = 0;
    for (int i = 2; i < inNum; i++) {
      if (inNum % i == 0) {
	checkFlag = 0;
	break;
      }
   
    }
    if (checkFlag) {
      //cout << inNum << " is prime" << endl;
	countPrime++;
    }
    // else
      //cout << inNum << " is not prime" << endl;
  }
  cout << countPrime << endl;
  
  return 0;
}
