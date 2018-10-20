// http://seungkwan.tistory.com/8

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int num;
  cin >> num;
  
  vector<int> inNums(num), ind;
  for(int i = 0; i < num; i++)
    cin >> inNums[i];

  int size = 0;
  vector<int> dp;
  dp.push_back(inNums[0]);
  ind.push_back(0);
  for(int i = 1; i < num; i++) {
    if(inNums[i] > dp[size]) {
      dp.push_back(inNums[i]);
      size++;
      ind.push_back(size);
    }
    else {
      for(int j = 0; j <= size; j++)
	if (dp[j] >= inNums[i]) {
	  dp[j] = inNums[i];
	  ind.push_back(j);
	  break;
	}
    }
    
    // cout << i << " " << inNums[i] << " : ";
    // for (int j = 0; j < dp.size(); j++)
    //   cout << dp[j] << " ";
    // cout << endl;
  }

  cout << size+1 << endl;

  // find out arr
  // for (int i = 0; i < ind.size(); i++)
  //   cout << ind[i] << " " ;
  // cout << endl;

  vector<int> LISarr;
  for(int i = num - 1; i >= 0; i--) {
    if (ind[i] == size) {
      LISarr.push_back(inNums[i]);
      size--;
      if (size == -1)
	break;
    }
    // cout << i << " " << size << " : ";
    // for(int i = LISarr.size()-1; i >= 0; i--)
    //   cout << LISarr[i] << " ";
    // cout << endl;
  }

  for(int i = LISarr.size()-1; i >= 0; i--)
    cout << LISarr[i] << " ";
  cout << endl;
  
  
  return 0;
}
