#include <iostream>
#include <vector>

using namespace std;

int main() {
  int num;
  cin >> num;
  
  vector<int> inNums(num);
  for(int i = 0; i < num; i++)
    cin >> inNums[i];

  vector<int> dp;
  for(int i = 0; i < num; i++) {
    int tmp = 0;
    for (int j = 0; j < i; j++)
      if (inNums[j] < inNums[i] && dp[j] > tmp)
	tmp = dp[j];

    dp.push_back(tmp+inNums[i]);
    //cout << i << " " << inNums[i] << " : " << tmp+inNums[i] << endl;
  }

  int max = 0;
  for (int i = 0; i < dp.size(); i++)
    if (dp[i] > max)
      max = dp[i];

  cout << max << endl;
  
  return 0;
}
