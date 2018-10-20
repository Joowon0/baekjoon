// http://seungkwan.tistory.com/8

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int num;
  cin >> num;
  
  vector<int> inNums(num);
  for(int i = 0; i < num; i++)
    cin >> inNums[i];

  int size = 0;
  vector<int> dp;
  dp.push_back(inNums[0]);
  for(int i = 1; i < num; i++) {
    if(inNums[i] > dp[size]) {
      dp.push_back(inNums[i]);
      size++;
    }
    else {
      for(int j = 0; j <= size; j++)
	if (dp[j] >= inNums[i]) {
	  dp[j] = inNums[i];
	  break;
	}
    }
    
    // cout << i << " " << inNums[i] << " : ";
    // for (int j = 0; j < dp.size(); j++)
    //   cout << dp[j] << " ";
    // cout << endl;
  }

  cout << size+1 << endl;
  
  return 0;
}
