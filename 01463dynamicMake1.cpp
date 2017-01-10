#include <iostream>

using namespace std;

int main () {
  long int numIn;
  //int base[100000][3];
  unsigned long long oldNums[3] = { 6000000000000000000, 6000000000000000000, 6000000000000000000}, newNums[3];
     // [n][0] : divide by 3
     // [n][1] : divide by 2
     // [n][2] : subtract 1
  long int i = 1;
  long int temp;

  cin >> numIn;

  if (numIn == 1) {
    cout << "0" << endl;
    return 0;
  }

  if (numIn % 3 == 0)
    oldNums[0] = numIn / 3;
  if (numIn % 2 == 0)
    oldNums[1] = numIn / 2;
  oldNums[2] = numIn - 1;

  while (i++) {
    // stop case
    if (oldNums[0] == 1)
      break;
    if (oldNums[1] == 1)
      break;
    if (oldNums[2] == 1)
      break;

    
    // print for test
    
    for (int i = 0; i < 3; i++)
      cout << oldNums[i] << " ";
    cout << endl;
    

    // DP newNums[0]
    
    if (oldNums[0] % 3 == 0)
      newNums[0] = oldNums[0] / 3;
     if (oldNums[1] % 3 == 0 && newNums[0] > oldNums[1] / 3)
      newNums[0] = oldNums[1] / 3;
    if (oldNums[2] % 3 == 0 && newNums[0] > oldNums[2] / 3)
      newNums[0] = oldNums[2] / 3;
    
    
    // DP newNums[1]
    if (oldNums[0] % 2 == 0)
      newNums[1] = oldNums[0] / 2;
    if (oldNums[1] % 2 == 0 && newNums[1] > oldNums[1] / 2)
      newNums[1] = oldNums[1] / 2;
    if (oldNums[2] % 2 == 0 && newNums[1] > oldNums[2] / 2)
      newNums[1] = oldNums[2] / 2;
    
    
    // DP newNums[2]
    newNums[2] = oldNums[0];
    if (newNums[2] > oldNums[1])
      newNums[2] = oldNums[1];
    if (newNums[2] > oldNums[2])
      newNums[2] = oldNums[2];
    newNums[2]--;

    // swap newNums to oldNums
    for (int i = 0; i < 3; i++)
      oldNums[i] = newNums[i];
  }
    
  cout << i-1 << endl;
  
  return 0;
}
