#include <iostream>
#include <string.h> // memset
//#include <cstdlib>  // exit

using namespace std;

int memo[501][501], pureCost[501][501];
int fileCost[501];

//int i = 0;

int calCost(int start, int end) {
  //cout << endl << "checking [" << start << ":" << end << "]" << endl;
  //i++;

  //if (i >= 20)
  //  exit(1);
  
  // basecase
  if (start == end)
    return 0;
  else if (end - start == 1) {
    memo[start][end] = fileCost[start] + fileCost[end];
    return memo[start][end];
  }

  // check if calculated
  if (memo[start][end] != 0)
    return memo[start][end];

  // DP
  // check [start : i] + [i+1 : end]
  int mintemp, temp;
  mintemp = fileCost[start] + calCost(start+1, end) + pureCost[start+1][end] ;
  /*
  cout << "checking [" << start << ":" << end << "] :  ";
  cout << "[" << start << "] + [" << start+1 << " : " << end << "] : " << mintemp << endl << endl;
  */
  for (int i = start + 1; i < end; i++) {
    temp = (calCost(start, i) + calCost(i+1, end)) + pureCost[start][i] + pureCost[i+1][end];
    if (mintemp > temp)
      mintemp = temp;
    /*
    cout << "checking [" << start << ":" << end << "] :  ";
    cout << "[" << start << " : " << i << "] + [" << i+1 << " : " << end << "] : " << temp << endl << endl;
    */
  }
  /*
  temp = calCost(start, end-1) * 2 + fileCost[end];
  cout << "checking [" << start << ":" << end << "] : ";
  cout << "[" << start << " : " << end-1 << "] + ["
       <<  end << "] : " << temp << endl << endl;
  if (mintemp > temp)
    mintemp = temp;
  */
  memo[start][end] = mintemp;
  
  return mintemp;
}

int main() {
  int caseNum, fileNum;

  cin >> caseNum;
  
  while(caseNum--) {
    cin >> fileNum;

    for (int i = 0; i < fileNum; i++) {
      cin >> fileCost[i];
      pureCost[i][i] = fileCost[i];
    }

    memset ( memo, 0, sizeof(int) * 501 * fileNum );

    // [i : j] (i <= j < fileNum)
    
    for (int i = 0; i < fileNum; i++) {
      for (int j = i + 1; j < fileNum; j++) {
	pureCost[i][j] = pureCost[i][j-1] + fileCost[j];
      }
    }
    
    cout << calCost(0, fileNum-1) << endl;
  }
  return 0;
}
