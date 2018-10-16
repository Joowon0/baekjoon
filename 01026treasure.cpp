#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int nums, temp;
  vector<int> first, second;
  vector<pair<int, int>> secondWindex;

  cin >> nums;
  for(int i = 0; i < nums; i++) {
    cin >> temp;
    first.push_back(temp);
  }
  for(int i = 0; i < nums; i++) {
    cin >> temp;
    second.push_back(temp);

    pair<int,int> pairTemp (temp, i);
    secondWindex.push_back(pairTemp);
  }

  sort(first.begin(), first.end());
  sort(second.begin(), second.end());

  int sums = 0;
  for(int i = 0; i < nums; i++) {
    //cout << first[i] << " " << second[nums - i - 1] << " " << 
    //	 first[i] * second[nums - i - 1] << endl;
    sums += first[i] * second[nums - i - 1];
  }

  cout << sums << endl;
  
  return 0;
}
