#include <iostream>

using namespace std;

int main() {
  int caseNum;
  int fileNum, fileCost[501];
  int memo[501][501][2]; // [n][m][0] : sum includeing [n][m]
                         // [n][m][1] : number of sum of [n][m]
  int temp0, temp1, temp;
  
  cin >> caseNum;

  while(caseNum--) {
    cin >> fileNum;

    for (int i = 0; i < fileNum; i++)
      cin >> fileCost[i];

    // initiate
    memo[0][0][0] = fileCost[0];
    for (int i = 1; i < fileNum; i++) {
      memo[i][i][0] = fileCost[i];
      //memo[i][i][1] = 1;
      memo[i-1][i][0] = fileCost[i-1] + fileCost[i];
    }
    // DP

    for (int i = 0; i < fileNum; i++) {
      // check [0:j] +([j+1:i-1] + [i:i]) (0 <= j <= i-2)
      for (int j = 0; j < i-1; j++) {
	temp = memo[0][j][0] + memo[j+1][i-1][0] * 2 + fileCost[i] * 2;
	if (j+1 != i-1)
	  temp += memo[j+1][i-1][0];
	if (temp0 < temp)
	  temp0 = temp;
	
	cout << j << " " << i << " : " << temp << " " << temp0 << "\t";
	cout << memo[0][j][0] << " " << memo[j+1][i-1][0] << " " << fileCost[i] << endl;
	
	memo[j][i][0] = temp;
      }
    }
    
    
    // print for test
    cout << endl;
    for (int i = 0; i < fileNum; i++) {
      for (int j = 0; j < fileNum; j++) {
	cout << i << " " << j << " : " << memo[i][j][0] << " \t";
      }
      cout << endl;
    }

    temp0 = 4294967296 - 1;
    //temp1 = 0;
    // check [0:i] + [i+1:fileNum-1]
    cout << endl;
    for (int i = 0; i < fileNum; i++) {
      temp = memo[0][i][0] + memo[i+1][fileNum-1][0];
      if (0 != i)
	temp = memo[0][i][0];
      if (i+1 != fileNum-1)
	temp = memo[i+1][fileNum-1][0];
      
      if (temp0 > memo[0][i][0] + memo[i+1][fileNum-1][0])
	temp0 =  memo[0][i][0] + memo[i+1][fileNum-1][0];
      cout << "[0:" << i << "] + [" << i+1 << ":" << fileNum-1 << "] : "
	   <<  temp << endl;
    }
  }
  
  return 0;
}
