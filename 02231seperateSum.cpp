#include <iostream>

using namespace std;

int main() {
  int madeNum, tempNum, numLen = 0;
  cin >> madeNum;
  tempNum = madeNum;
  
  // find out the length of num
  for (int i = 0; i < 7; i++) {
    if (tempNum == 0)
      break;

    tempNum /= 10;
    numLen ++;
  }

  
  // get minimum possibility
  int startNum = madeNum - numLen * 10;
  if (startNum < 0)
    startNum = 0;
  //cout << numLen << endl
  //     << startNum << endl;
  
  // for all range
  for (int i = startNum; i <= madeNum; i++) {
    int intoNum = i;
    int cnt = 1;
    //cout << "Num : " << i << endl;
    
    // for all status
    for (int j = 0; j < numLen; j++) {
      intoNum += ((i % (cnt * 10)) / cnt);
      //cout << ((i % (cnt * 10)) / cnt) << " " << intoNum <<endl;
      cnt *= 10;
    }
    //cout << "made : " << intoNum << endl << endl;

    if (intoNum == madeNum) {
      cout << i << endl;
      return 0;
    }
  }

  cout << 0 << endl;
  
  return 0;
}
