#include <iostream>

using namespace std;

int queLen, popCase;
int popNums[50], count2N3 = 0;
int que[100000], f = 50000, r = 50000;

int pop() {
  f++;
}
int moveL() {
  que[r] = que[f];
  f++; r++;
  
  count2N3++;
}
int moveR() {
  f--; r--;
  que[f] = que[r];
  
  count2N3++;
}

int main() {
  // get input
  cin >> queLen >> popCase;
  for (int i = 0; i < popCase; i++)
    cin >> popNums[i];

  // fill in queue
  for (int i = 0; i < queLen; i++)
    que[f+i] = i+1;
  r = f + queLen;

  // print queue
  /*
  cout << "front : " << f << "\trear : " << r << endl;
  for (int i = f; i < r; i++)
    cout << que[i] << " ";
  cout << endl << endl;
  */

  int findPlace, ifFrontShorter;
  int moveTimes;
  for (int i = 0; i < popCase; i++) {
    // find which way is shorter
    ifFrontShorter = 1;
    for (int j = f; j < r; j++) {
      if (que[j] == popNums[i]) {
	findPlace = j;
	break;
      }
    }
    if (findPlace > (r+f)/2)
      ifFrontShorter = 0;
    /*
    cout << "try num : " << i << "\tpop num : " << popNums[i] << endl;
    cout << "front : " << f << "\trear : " << r << endl;
    for (int i = f; i < r; i++)
      cout << que[i] << " ";
    cout << endl;
    cout << "place : " << findPlace << "\tifFront : " << ifFrontShorter << endl << endl;
    */
    // rotate till find num
    if (ifFrontShorter) {
      moveTimes = findPlace - f;
      for (int j = 0; j < moveTimes; j++) {
	moveL();
      }
      pop();
    }
    else {
      moveTimes = r - findPlace;
      for (int j = 0; j < moveTimes; j++)
	moveR();
      pop();
    }
    /*
    for (int i = f; i < r; i++)
	cout << que[i] << " ";
    cout << endl;
    */
  }

  cout << count2N3 << endl;
  
  return 0;
}
