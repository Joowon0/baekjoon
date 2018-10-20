#include <iostream>
#include <vector>

using namespace std;

int main() {
  int num;
  cin >> num;
  
  vector<int> inNums(num);
  for(int i = 0; i < num; i++)
    cin >> inNums[i];

  vector<int> inc;
  for(int i = 0; i < num; i++) {
    int tmp = 0;
    for (int j = 0; j < i; j++)
      if (inNums[j] < inNums[i] && inc[j] > tmp)
	tmp = inc[j];

    inc.push_back(tmp + 1);
    //cout << i << " " << inNums[i] << " :  " << tmp+1 << endl;
  }

  vector<int> dec(num);
  for(int i = num-1; i >= 0; i--) {
    int tmp = 0;
    for (int j = num-1; j > i; j--)
      if (inNums[j] < inNums[i] && dec[j] > tmp)
	tmp = dec[j];

    dec[i] = tmp+1;
    //cout << i << " " << inNums[i] << " :  " << tmp+1 << endl;
  }

  int max = 0;
  for (int i = 0; i < num; i++) {
    //cout << i << " " << inNums[i] << " :  " << inc[i] << " + " << dec[i] << " : " << inc[i] + dec[i] -1  << endl;
    if (inc[i] + dec[i] > max)
      max = inc[i] + dec[i];
  }

  cout << max-1 << endl;
  
  return 0;
}
