#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int coinNum, target;
  int coinVal[500];
  int base[100000];

  cin >> coinNum >> target;

  for (int i = 0 ; i < coinNum; i++)
    cin >> coinVal[i];

  sort (coinVal, coinVal + coinNum);

  // print for test
  /*
  for (int i = 0; i < coinNum; i++)
    cout << coinVal[i] << " " ;
  cout << endl << endl;
  */
  
  // initiate with smallest one
  for (int i = 1; i < target + 1; i++) {
    if (i % coinVal[0] == 0)
      base[i] = 1;
  }
  
  // DP
  for (int i = 1; i < coinNum; i++) {
    base[coinVal[i]]++; 
    for (int j = coinVal[i] + 1; j < target + 1; j++) {
      base[j] += base[j-coinVal[i]];
    }
  }

  cout << base[target] << endl;
  
  
  return 0;
}
