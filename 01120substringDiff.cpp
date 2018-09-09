#include <iostream>
#include <string.h>

using namespace std;

int findDiff (int indent, int cmpLen, char shortOne[], char longOne[]) {
  int diffs = 0;

  // cout << indent << endl;
  // for (int i = 0; i < cmpLen; i++)
  //   cout << shortOne[i];
  // cout << endl;
  // for (int i = 0; i < cmpLen; i++)
  //   cout << longOne[i+indent];
  // cout << endl;

  for (int i = 0; i < cmpLen; i++)
    if (shortOne[i] != longOne[i+indent])
      diffs++;

  return diffs;
}


int main() {
  char shortString[51];
  char longString[51];

  int shortLen, longLen;
  int lenDiff;

  cin >> shortString >> longString;
  
  shortLen = strlen(shortString);
  longLen = strlen(longString);
  lenDiff = longLen - shortLen;

  // cout <<strlen(shortString) << " " << strlen(longString) << endl;

  int minDiff = findDiff(0, shortLen, shortString, longString);
  for (int i = 1; i <= lenDiff; i++) {
    int tempDiff = findDiff(i, shortLen, shortString, longString);
    if (tempDiff < minDiff)
      minDiff = tempDiff;
  }

  cout << minDiff << endl;
  
  return 0;
}
