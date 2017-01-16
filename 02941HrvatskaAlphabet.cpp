#include <iostream>
#include <string.h>

using namespace std;

int main() {
  char strIn[101];
  char alpha[8][4] = { "c=", "c-", "d-", "lj", "nj", "s=", "z=", "dz=" };
  int n = 0;
  bool b;

  cin >> strIn;

  for (int i = 0; i < strlen(strIn); i++) {
    b = 0;
    //cout << i << " " << strIn[i] << strIn[i+1]<< endl;
    for (int j = 0; j < 8; j++) {
      if (strIn[i] == alpha[j][0]
	  && i+1 < strlen(strIn) && strIn[i+1] == alpha[j][1]) {
	//cout << "two matched : " << alpha[j] << endl;
	if (j == 7 && i+2 < strlen(strIn) && strIn[i+2] == alpha[j][2]) {
	  i += 2;
	  n++;
	  b = 1;
	  break;
	}
	else if (j != 7) {
	  i += 1;
	  n++;
	  b = 1;
	  break;
	}
      }
    }
    if (b == 0) {
      //cout << "one matched : " << strIn[i] << endl;
      n++;
    }
  }
  cout << n << endl;
  
  return 0;
}
