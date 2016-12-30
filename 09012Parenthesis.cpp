#include <iostream>
#include <string.h>

using namespace std;

int main() {
  int caseNum, cnt;
  char par[50];

  cin >> caseNum;
  while(caseNum--) {
    cin >> par;
    //cout << strlen(par) << endl;

    cnt = 0;
    for (int i = 0; i < strlen(par); i++) {
      if (par[i] == '(')
	cnt++;
      else {
	cnt--;

	if (cnt < 0) // cannot accept )(
	  cnt = -100;
      }
    }

    if (cnt == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
