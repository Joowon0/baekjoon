#include <iostream>
#include <vector>
#include <algorithm>

#include <stdio.h>

using namespace std;

int main() {
  int cardNum, checkNums;
  vector<int> cards;

  //cin >> cardNum;
  scanf("%d", &cardNum);
  int temp;
  for (int i = 0; i < cardNum; i++) {
    //    cin >> temp;
    scanf("%d", &temp);
    cards.push_back(temp);
  }

  sort(cards.begin(), cards.end());
  //  cin >> checkNums;
  scanf("%d", &checkNums);
  int value;
  for (int i = 0; i < checkNums; i++) {
    //    cin >> value;
    scanf("%d", &value);
    if (binary_search(cards.begin(), cards.end(), value))
      //      cout << "1 ";
      printf("1 ");
    else
      //      cout << "0 ";
      printf("0 ");
  }

  
  return 0;
}
