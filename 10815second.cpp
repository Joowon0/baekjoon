#include <stdio.h>


bool cards[20000000];

int main() {
  int cardNums, checkNums;

  //cin >> cardNums;
  scanf("%d", &cardNums);
  int temp;
  for (int i = 0; i < cardNums; i++) {
    //cin >> temp;
    scanf("%d", &temp);
    cards[temp + 10000000] = true;
  }

  //  cin >> checkNums;
  scanf("%d", &checkNums);
  for (int i = 0; i < checkNums; i++) {
    //    cin >> temp;
    scanf("%d", &temp);
    if (cards[temp + 10000000] == true)
      //      cout << "1 ";
      printf("1 ");
    else
      //      cout << "0 ";
      printf("0 ");
  }
  return 0;
  
}
