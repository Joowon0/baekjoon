#include <stdio.h>

int cards[20000005];

int main() {
  int cardNums, checkNums;

  //cin >> cardNums;
  scanf("%d", &cardNums);
  int temp;
  for (int i = 0; i < cardNums; i++) {
    //cin >> temp;
    scanf("%d", &temp);
    cards[temp + 10000000]++;
  }

  //  cin >> checkNums;
  scanf("%d", &checkNums);
  for (int i = 0; i < checkNums; i++) {
    //    cin >> temp;
    scanf("%d", &temp);
    printf("%d ", cards[temp + 10000000]);
  }
  return 0;
  
}
