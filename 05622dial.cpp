#include <iostream>
#include <string.h>

using namespace std;

int main() {
  char str[30];
  int sum = 0, temp;

  cin >> str;

  for (int i = 0; i < strlen(str); i++) {
    if (str[i] < 'S')
      temp = ((str[i]-'A') / 3+2) + 1; 
    else if (str[i] < 'Z') 
      temp = ((str[i]-'A'-1) / 3+2) + 1;
    else
      temp = 10;
    
    sum += temp;
    
    //cout << str[i] << " " << (str[i]-'A') << endl;
    /*
    if (str[i] < 'S')
      cout << str[i] << " " <<(str[i]-'A') << " " << ((str[i]-'A') / 3+2) << endl;
    else if (str[i] < 'Z') {
      cout << str[i] << " " <<((str[i]-'A')- 1) << " "<< ((str[i]-'A'-1) / 3+2) << endl;
    }
    else
      cout << 11 << endl;
    */
  }

  cout << sum << endl;
  
  return 0;
}
