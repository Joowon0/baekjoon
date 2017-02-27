#include <iostream>

using namespace std;

int main() {
  int caseNum;
  int start, end, leng;
  float half, times;

  int cnt;

  cin >> caseNum;

  while(caseNum--) {
    cin >> start >> end;
    //initiate
    leng = end - start;
    half = (float) leng / 2;
    cnt = 1; times = 0;

    //cout << leng << " " << half << endl;

    // calculate
    while(half > 0) {
      times++;
      //cout << times << " : " << half << " " << cnt << endl;
      if (cnt <= half) {
	half -= cnt;
	cnt++;
      }
      // the last of counting
      else{
	half *= 2;
	if (half == cnt - 2 || half == cnt - 1 || half == cnt)
	  times -= 0.5;
	break;
      }
    }
    cout << times * 2 << endl;
  }
  
  return 0;
}
