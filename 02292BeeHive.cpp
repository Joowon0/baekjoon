#include <iostream>

using namespace std;

int main() {
  long long inNum, sumNum = 0, sumStart = 2;;

  cin >> inNum;

  if (inNum == 1)
    cout << 1 << endl;
  else {
    for (int i = 2; ; i++ ) {
      sumNum += 6;

      //cout << i << " : " << sumNum << " " << sumStart << " " << sumStart + sumNum << endl;
      
      if ( sumStart <= inNum && inNum < sumStart + sumNum ) {
	cout << i << endl;
	break;
      }

      sumStart += sumNum;
    }
  }
  
  return 0;
}
