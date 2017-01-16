#include <iostream>

using namespace std;

int main () {
  int caseNum, numIn[100000];
  int memo[100000], maxTemp;

  // get input
  cin >> caseNum;
  for (int i = 0; i < caseNum; i++)
    cin >> numIn[i];

  // initiate
  memo[0] = numIn[0];
  if (memo[0] < 0)
    memo[0] = 0;
  maxTemp = memo[0];

  // DP
  for (int i = 1; i < caseNum; i++) {
    memo[i] = memo[i-1] + numIn[i];

    if (memo[i] < 0)
      memo[i] = 0;
    else if (maxTemp < memo[i])
      maxTemp = memo[i];

    //cout << i << " : " << memo[i] << endl;
  }
  if (maxTemp <= 0) { // when all numbers are below 0
    maxTemp = numIn[0];
    for (int i = 1; i < caseNum; i++) {
      //cout << maxTemp << " " << numIn[i] << " "<< (maxTemp < numIn[i]) << endl;
      if (maxTemp < numIn[i])
	  maxTemp = numIn[i];
    }
  }
  cout << maxTemp << endl;
  
  return 0;
}
