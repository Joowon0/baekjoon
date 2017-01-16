//#include <iostream>
#include <stdio.h>
//#include <string>
#include <string.h>

//using namespace std;

int main() {
  char strIn[1000000];
  int c = 0;

  //cin >> strIn;
  scanf("%[^\n]", strIn);

  for (int i = 1; i < strlen(strIn); i++) {
    //cout << strIn[i];
    //printf("%c", strIn[i]);
    if (strIn[i] == ' ')
      c++;
  }

  //cout << c << endl;
  if (strIn[strlen(strIn)-1] != ' ')
    c++;
  printf("%d\n", c);
  
  return 0;
}
