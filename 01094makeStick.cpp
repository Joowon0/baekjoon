#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int main() {
  int target, sticks[7], usingS[7];
  int i = 0;
  int sumTemp;

  cin >> target;

  memset(sticks, 0, sizeof(int) * 7);
  memset(usingS, 0, sizeof(int) * 7);
  sticks[6] = 1;
  usingS[6] = 1;

  while(1) {
    // end of splitting
    sumTemp = 0;
    for (int i = 1; i < 7; i++) {
      sumTemp += pow(2, i) * usingS[i];
      //cout << pow(2, i) << " " << usingS[i] << " " << sumTemp << endl;
    }
    if(sumTemp <= target) {
      //cout << sumTemp << endl;
      break;
    }

    
    // splitting
    int split;
    for (split = 1; split < 7; split++) {
      if (usingS[split] != 0) {
	usingS[split]--;
	split--;
	usingS[split]++;
	usingS[split]++;
	break;
      }	
    }
    
    // throwing away
    sumTemp = 0;
    for (int i = 1; i < 7; i++) {
      sumTemp +=  pow(2, i) * usingS[i];
    }
    sumTemp -= pow(2, split);
    if(sumTemp >= target)
      usingS[split]--;
  }

  // adding
  sumTemp = 0; int nStick = 0;
  for (int i = 6; i >= 0; i--) {
    if (sumTemp == target)
      break;

    for (int j = usingS[i]; j > 0; j--) {
      if (sumTemp + pow(2, i) * j <= target) {
	sumTemp += pow(2, i) * j;
	nStick += j;
	break;
      }
    }
    
  }

  cout << nStick << endl;
  
  return 0;
}
