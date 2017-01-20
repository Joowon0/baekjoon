#include <iostream>

using namespace std;

int main() {
  int sum, minLen;
  int memo[101][101];
  int a =  -1, b = 110;

  cin >> sum >>minLen;

  // sum from num i to num j (i <= j)
  for (int i = 0; i < 101; i++) {
    memo[i][i] = i;
    for (int j = i+1; j < 101; j++) {
      memo[i][j] = memo[i][j-1] + j;
      //cout << "memo[" << i << "][" << j << "] = " << memo[i][j] << endl;
    }
  }
  /*
  // print for test
  for (int i = 0; i < 10; i++) {
    for (int j = 1; j < 10; j++)
      cout << memo[i][j] << "\t";
    cout << endl;
  }
  */
  
  // search
  for (int i = 0; i <= sum && i < 101; i++) {
    for (int j = i+1; j <= sum && j < 101; j++) {
      /*
      cout << "memo[" << i << "][" << j << "] = " << memo[i][j]
	   << " [" << a << "][" << b << "] "
	   << (memo[i][j] == sum) << " " << (j-i >= minLen) << " " << (j-i < b-a)
	   << endl;
      */
      // find match
      if (memo[i][j] == sum && j-i >= minLen - 1 && j-i < b-a ) {
	a = i; b = j;
	break; // no more match in the row
      }
      // search other row
      else if (memo[i][j] > sum)
	break;
    }
  }
  //cout << a << " " << b << endl;

  if (a != -1 && b != 110) {
    for (int i = a; i <= b; i++)
      cout << i << " ";
  }
  else {
    cout << -1;
  }
  cout << endl;
  
  return 0;
}
