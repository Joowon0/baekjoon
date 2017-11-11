#include <iostream>

using namespace std;

int nodeNum;
int arr[1002];
int dp[1002];

int checkAcc(int node, int num) {
  if (dp[node] == 0) {
    dp[node] =  num;
    checkAcc( arr[node], num);
  }
}

int print() {
  for (int i = 1; i <= nodeNum; i++)
    cout << i << " ";
  cout << endl;
  for (int i = 1; i <= nodeNum; i++)
    cout << dp[i] << " ";
  cout << endl << endl;
}

int main() {
  int caseNum;
  cin >> caseNum;

  while(caseNum--) {
    // get input
    cin >> nodeNum;
    for (int i = 1; i <= nodeNum; i++) {
      cin >> arr[i];
      dp[i] = 0;
    }

    // count for each node
    int count = 1;
    for (int i = 1; i <= nodeNum; i++) {
      if (dp[i] == 0) { // check if not accessed
        checkAcc(i, count);
	count++;
      }

      //cout << "i : " << i << endl;
      //print();
    }
    cout << count - 1 << endl;
  }
  
  return 0;
}
