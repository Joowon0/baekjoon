//
// read https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
//
#include <iostream>
#include <string>   // string type

using namespace std;

string a, b;
int memo[1001][1001], aLen, bLen;

string findLCS(int i, int j) {
  if (i == 0 || j == 0)
    return "";
  else if (a[i] == b[j])
    return findLCS(i-1, j-1) + a[i];
  else {
    if (memo[i-1][j] > memo[i][j-1])
      return findLCS(i-1,j);
    else
      return findLCS(i, j-1);
  }
}

int main() { 
  int temp;

  cin >> a >> b;

  a = " " + a;
  b = " " + b;
  
  // initiate
  aLen = a.length();
  bLen = b.length();
  for (int i = 0; i < aLen; i++) 
    memo[i][0] = 0;
  for (int i = 0; i < bLen; i++) 
    memo[0][i] = 0;

  //cout << a << endl << b << endl;
  for (int i = 1; i < aLen; i++) {
    for (int j = 1; j < bLen; j++) {
      //cout << i << a[i] << " " << j << b[j]  << " " <<( a[i] == b[j] ) << "  ";
      
      if (a[i] == b[j])
	memo[i][j] = memo[i-1][j-1] + 1;
      else {
	temp = memo[i-1][j];
	if (temp < memo[i][j-1])
	  temp = memo[i][j-1];
	memo[i][j] = temp;
      }
      
    }
  }

  cout << memo[aLen - 1][bLen - 1] << endl;
  cout << findLCS(aLen - 1, bLen - 1) << endl;
  
  return 0;
}
