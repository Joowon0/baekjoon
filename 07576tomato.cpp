#include <iostream>

using namespace std;

int row, col;
int tomato[1000][1000];
int b4Num, newNum;
int que[1000000][2];
int newQue[1000000][2];

void print4Test() {
  // print for test
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << tomato[i][j] << " ";
    }
    cout << endl;
  }
}

void printQ() {
  for(int i = 0; i < b4Num; i++) {
    cout << "que [" << i << "] : ";
    cout << "tomato[" << que[i][0] << "][" << que[i][1] << "]" << endl;
  }
  cout << endl;
}

bool checkIfPossi(int r, int c) {
  if (r < row && c < col &&
      0 <= r && 0 <= c &&
      tomato[r][c] == 0)
    return true;
  else
    return false;
}

int main() {
  // get input
  cin >> col >> row;
  
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> tomato[i][j];
    }
  }

 

  // fill in initial queue
  b4Num = 0;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      if (tomato[i][j] == 1) {
	que[b4Num][0] = i;
	que[b4Num][1] = j;
	b4Num++;
      }

  //print4Test();
  //printQ();

  
  for (int count = 2; count < 1000000; count++) {
    //bool isChanged = false;
    newNum = 0;

    // fill in num
    for (int x = 0; x < b4Num; x++) {
      int i = que[x][0];
      int j = que[x][1];

      //cout << "i : " << i << "\tj : " << j << endl;
      
      // up
      if (checkIfPossi(i-1, j)) {
	tomato[i-1][j] = count;
	//isChanged = true;
	  
	newQue[newNum][0] = i-1;
	newQue[newNum][1] = j;
	//cout << "Put in i : " << i-1 << "\tj : " << j << endl;
	newNum++;
      }
      // down
      if (checkIfPossi(i+1, j)) {
	tomato[i+1][j] = count;
	//isChanged = true;

	newQue[newNum][0] = i+1;
	newQue[newNum][1] = j;
	//cout << "Put in i : " << i+1 << "\tj : " << j << endl;
	newNum++;
      }
      // left
      if (checkIfPossi(i, j-1)) {
	tomato[i][j-1] = count;
	//isChanged = true;

	newQue[newNum][0] = i;
	newQue[newNum][1] = j-1;
	//cout << "Put in i : " << i << "\tj : " << j-1 << endl;
	newNum++;
      }
      // right
      if (checkIfPossi(i, j+1)) {
	tomato[i][j+1] = count;
	//isChanged = true;

	newQue[newNum][0] = i;
	newQue[newNum][1] = j+1;
	//cout << "Put in i : " << i << "\tj : " << j+1 << endl;
	newNum++;
      }
    }
    
    // end point
    if (newNum == 0) {
      bool isEnd = true;
      for (int i = 0; i < row; i++) {
	for (int j = 0; j < col; j++) {
	  if (tomato[i][j] == 0) {
	    cout << -1 << endl;
	    return 0;
	  }
	}
      }
      // found all solution
      cout << count - 2 << endl;
      return 0;
    }


    // fill in que for next loop
    b4Num = newNum;
    for (int i = 0; i < b4Num; i++) {
      que[i][0] = newQue[i][0];
      que[i][1] = newQue[i][1];
    }

    //print4Test();
    //printQ();
  }
  
  return 0;
}
