#include <iostream>

using namespace std;

int main() {
  int numLen, base[101][10];
  int intOut = 0;

  cin >> numLen;

  if (numLen == 1) {
    cout << 9 << endl;
  }
  else {
    // basecase
    //base[1][0] = 0;
    for (int i = 1; i < 10; i++)
      base[1][i] = 1;
    // DP
    for (int i = 2; i <= numLen; i++) {
      base[i][0] = base[i-1][1];
      base[i][9] = base[i-1][8];

      for (int j = 1; j <= 8; j++) {
	base[i][j] = base[i-1][j-1] + base[i-1][j+1];
	base[i][j] %= 1000000000;
      }
    }

    //print for test
    /*
    for (int i = 1; i <= numLen; i++) {
      for (int j = 0; j < 10; j++)
	cout << base[i][j] << " ";
      cout <<endl;
    }
    */
    
    for (int i = 0; i < 10; i++) {
      
      //cout << base[numLen][i] << " " << intOut << " ";
      intOut += base[numLen][i];
      //cout << intOut << " ";
      intOut = intOut % 1000000000;
      //cout << intOut << endl;
    }
    cout << intOut % 1000000000 << endl;
    
  }
  
  return 0;
}
