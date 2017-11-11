#include <iostream>

using namespace std;

int placeNum;
int place[3002][3];
int connect[5002][5002];
int info[5002][2]; // 0 - num of nodes that are connected
                   // 1 - group count num

int count(int place, int num) {
  if (info[place][1] == 0) {
    info[place][1] = num;
    for (int i = 0 ; i < info[place][0]; i++)
      count(connect[place][i], num);
  }
}

int main() {
  int caseNum;
  cin >> caseNum;
  
  while(caseNum--) {
    cin >> placeNum;
    //int x, y;
    for (int i = 0; i < placeNum; i++)
      cin >> place[i][0] >> place[i][1] >> place[i][2];
    for (int i = 0; i < 5002; i++)
      info[i][0] = info[i][1] = 0;

    // print test
    /*
    cout << caseNum+1 << endl;
    for (int i = 0; i < placeNum; i++)
      cout << place[i][0] << " " << place[i][1] << endl;
    */

    // check if connected
    for (int i = 0; i < placeNum; i++)
      for (int j = i+1; j < placeNum; j++) {
	  int len = (place[i][0] - place[j][0]) * (place[i][0] - place[j][0])
	    + (place[i][1] - place[j][1]) * (place[i][1] - place[j][1]);
	  int rangeSum = (place[i][2] + place[j][2]) * (place[i][2] + place[j][2]);

	  //cout << "i : " << i << "\tj : " << j << "\tlen : " << len << "\tr+r : " << place[i][2] + place[j][2] << endl;
	  if (len <= rangeSum) {
	    connect[i][info[i][0]] = j;
	    connect[j][info[j][0]] = i;
	    info[i][0]++;
	    info[j][0]++;
	  }
	}

    // print test2
    /*
    for (int i = 0; i < 5; i++) {
      cout << i << " - " << info[i][0] << " : ";
      for (int j = 0; j < info[i][0]; j++)
	cout << connect[i][j] << " ";
      cout << endl;
    }
    cout << endl;
    */

    // count group
    int c = 1;
    for (int i = 0; i < placeNum; i++) {
      if (info[i][1] == 0) {
	count(i, c++);
      }
    }

    // print test2
    /*
    for (int i = 0; i < 5; i++)
      cout << i << " : " << info[i][1] << endl;
    */
    
    cout << c - 1  << endl;
    //cout << endl;
  }
  
  return 0;
}
