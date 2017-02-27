#include <iostream>

using namespace std;

int main() {
  int caseNum;
  int start, end, leng;
  int cnt, times;
  bool ifodd;

  cin >> caseNum;

  while(caseNum--) {
    cin >> start >> end;
    
    //initiate
    leng = end - start;
    cnt = 1; times = 0;
    ifodd = true;

    // calculate
    while(leng > 0) {
      times++;
      
      // add first time
      if (ifodd) {
	leng -= cnt;
	ifodd = false;
      }
      // add second time
      else {
	leng -= cnt;
	cnt++;
	ifodd = true;
      }
    }
    cout << times << endl;
  }
  
  return 0;
}
