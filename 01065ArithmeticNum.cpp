#include <iostream>

using namespace std;

int main() {
  int inNum;

  cin >> inNum;

  if ( inNum < 100 )
    cout << inNum << endl;
  else {
    int cnt = 99;
    int n1000, n100, n10, n1;
    int diff;

    //cout << n1000 << endl << n100 << endl << n10 << endl << n1 << endl;

    if (inNum < 1000) {
      for (int i = 111; i <= inNum; i++) {
        n100  = i % 1000 / 100;
        n10   = i % 100 / 10;
        n1    = i % 10;
	
	if (n100 - n10 == n10 - n1){
	  //cout << n100 << n10 << n1 << endl;
	  cnt++;
	}
      }
      cout << cnt << endl;
    }
    else {
      for (int i = 111; i < 1000; i++) {
        n100  = i % 1000 / 100;
        n10   = i % 100 / 10;
        n1    = i % 10;
	if (n100 - n10 == n10 - n1) {
	  //cout << n100 << n10 << n1 << endl;
	  cnt++;
	}
      }
      for (int i = 1111; i <= inNum; i++) {
	n1000 = i / 1000;
        n100  = i % 1000 / 100;
        n10   = i % 100 / 10;
        n1    = i % 10;
	diff = n1000 - n100;
	if (n100 - n10 == diff && n10 - n1 == diff) {
	  //cout << n1000 << n100 << n10 << n1 << endl;
	  cnt++;
	}
      }
      cout << cnt << endl;
    }
  }
  
  return 0;
}
