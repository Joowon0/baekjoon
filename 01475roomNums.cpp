#include <iostream>
#include <string>

using namespace std;

int main() {
  string inNum;
  int needed[10], max = 0;

  for (int i = 0; i < 10; i++)
    needed[i] = 0;

  cin >> inNum;

  for (int i = 0; i < inNum.length(); i++)
    needed[inNum[i] - '0']++;

  needed[6] += needed[9];
  if (needed[6] % 2 == 1)
    needed[6]++;
  needed[6] /= 2;

  for (int i = 0; i < 9; i++)
    if (max < needed[i])
      max = needed[i];

  // print for test
  /*
  for (int i = 0; i < 10; i++)
    cout << needed[i] << " ";
  cout << endl;
  */
  cout << max << endl;
    
  return 0;
}
