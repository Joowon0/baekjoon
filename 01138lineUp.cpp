#include <iostream>
#include <string.h>

using namespace std;

int main() {
  int pplNum;
  int givenInfo[10];
  int lineOrder[10];

  cin >> pplNum;
  
  for (int i = 0; i < pplNum; i++)
    cin >> givenInfo[i];

  memset(lineOrder, 0, sizeof lineOrder);

  for (int i = 0; i < pplNum; i++) {
    for (int j = 0; j < pplNum; j++) {
      if (lineOrder[j] == 0) {
	// found place
	if (givenInfo[i] == 0) {
	  lineOrder[j] = i+1;
	  break;
	}
        // count taller person
	else
	  givenInfo[i]--;
      }
    }

    // for (int i = 0; i < pplNum; i++)
    //   cout << lineOrder[i] << " ";
    // cout << endl;
  }
  
  for (int i = 0; i < pplNum; i++)
    cout << lineOrder[i] << " ";
  return 0;
}
