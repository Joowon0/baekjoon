#include <iostream>

using namespace std;

int sums (int start, int end) {
  return (end - start + 1) * (end + start) / 2;
}

int main() {
  int sum, minLen;
  int a =  -1, b = 110;

  cin >> sum >>minLen;
  
  // search
  for (int i = 0; i <= sum; i++) {
    for (int j = i+1; j <= sum; j++) {
      int s = sums(i, j);
      /*
      cout << "memo[" << i << "][" << j << "] = " << s
	//<< (memo[i][j] == sum) << " " << (j-i >= minLen) << " " << (j-i < b-a)
	   << endl;
      */
      // find match
      if (s == sum && j-i >= minLen - 1 && j-i < b-a ) {
	a = i; b = j;
	break; // no more match in the row
      }
      // search other row
      else if (s > sum)
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
