#include <iostream>

using namespace std;

int main() {
  int caseNum;
  int aX, aY, bX, bY;
  int circleNum, circle[50][3];
  int isIn[50][2];
  int tempDist, cnt;

  cin >> caseNum;

  while(caseNum--) {
    // get inputs
    cin >> aX >> aY >> bX >> bY;
    cin >> circleNum;
    for (int i = 0; i < circleNum; i++) {
      cin >> circle[i][0] >> circle[i][1] >> circle[i][2];
      isIn[i][0] = false;
      isIn[i][1] = false;
    }

    // fill in isIn[][]
    for (int i = 0; i < circleNum; i++) {
      tempDist = (aX - circle[i][0]) * (aX - circle[i][0])
	       + (aY - circle[i][1]) * (aY - circle[i][1]);
      if (tempDist < (circle[i][2] * circle[i][2]))
	isIn[i][0] = true;

      tempDist = (bX - circle[i][0]) * (bX - circle[i][0])
	       + (bY - circle[i][1]) * (bY - circle[i][1]);
      if (tempDist < circle[i][2] * circle[i][2])
	isIn[i][1] = true;
    }

    /*
    // print for test
    cout << endl;
    for (int i = 0; i < circleNum; i++)
      cout << isIn[i][0] << " " << isIn[i][1] << endl;
    cout << endl;
    */

    cnt = 0;
    for (int i = 0; i < circleNum; i++) {
      if (isIn[i][0] != isIn[i][1])
	cnt++;
    }
    cout << cnt << endl;
  }
  
  return 0;
}
