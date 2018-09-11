#include <iostream>
// #include <algorithm>

using namespace std;

int numOfNum, targetNum;
int inNums[25];
int counter = 0;

void dfs(int start, int sum) {
  if (start >= numOfNum)
    return;
  else {
    for (int i = start; i < numOfNum; i++) {
      // check if sum is same as target
      int iIncludeSum = sum + inNums[i];
      if (iIncludeSum == targetNum) {
	counter ++;
	 // cout << start << " " << sum << "\t"
	 //      << i << " : " << inNums[i] << endl;
      }

      // include i th num
      dfs( i+1, iIncludeSum);

      // don't include i th num -> next index

      // while (inNums[i] == inNums[i+1] && i < numOfNum)
      // 	i++;
    }
  }
}

int main() {
  cin >> numOfNum >> targetNum;

  for(int i = 0; i < numOfNum; i++)
    cin >> inNums[i];

  // sort( inNums, inNums + numOfNum);
  
  dfs( 0, 0);

  cout << counter << endl;
  
  return 0;
}
