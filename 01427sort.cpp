#include <iostream>
#include <string.h>

using namespace std;

int nums[10];

int main() {
  char inNum[15];
  

  cin >> inNum;

  //cout << num << endl;
  //cout << strlen(inNum) << endl;;

  for (int i = 0; i < strlen(inNum); i++) {
    nums[inNum[i]-'0']++;
  }
  for (int i = 9; i >= 0; i--)
    while (nums[i]--)
      cout << i;
  cout << endl;
  
  return 0;
}
