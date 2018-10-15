#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

int main() {
  int cardNums, checkNums;
  vector<int> cards;

  scanf("%d", &cardNums);
  int temp;
  for (int i = 0; i < cardNums; i++) {
    scanf("%d", &temp);
    cards.push_back(temp);
  }
  
  multiset<int> multi(cards.begin(), cards.end());

  scanf("%d", &checkNums);
  for (int i = 0; i < checkNums; i++) {
    scanf("%d", &temp);
    printf("%ld ", multi.count(temp));
  }
  
  return 0;
}
