//#include <iostream>
#include <stdio.h>

//using namespace std;

int main() {
  int month, day;
  int totalDays = 0;

  char weeks[7][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  int days[12] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

  //cin >> month >> day;
  scanf("%d %d", &month, &day);

  for (int i = 1; i < month; i++)
    totalDays += days[i];
  totalDays += day;

  //cout << totalDays << endl;
  //cout << totalDays % 7 << weeks[totalDays % 7 - 1] << endl;
  //cout << weeks[totalDays % 7] << endl;
  for (int i = 0; i < 3; i++)
    printf("%c", weeks[totalDays % 7][i]);
  // don't know why this should be print like this
  
  return 0;
}
