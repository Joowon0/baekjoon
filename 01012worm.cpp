#include <iostream>
#include <cstring>

using namespace std;

int row, col;
int cabbages[55][55];

void print() {
  cout << endl;
  for (int i = 0; i <= row+1; i++) {
    for (int j = 0; j <= col+1; j++)
      cout << cabbages[j][i] << " ";
    cout << endl;
  }
  cout << endl;
}

int wormArea(int wormNum, int x, int y) {
  cabbages[x][y] = wormNum;

  // up
  if (cabbages[x][y-1] == -1)
    wormArea(wormNum, x, y-1);
  
  // down
  if (cabbages[x][y+1] == -1)
    wormArea(wormNum, x, y+1);
    
  // right
  if (cabbages[x-1][y] == -1)
    wormArea(wormNum, x-1, y);
  
  // left
  if (cabbages[x+1][y] == -1)
    wormArea(wormNum, x+1, y);
}



int main() {
  int caseNum;
  int cabbageNum;
  int tempX, tempY;

  cin >> caseNum;

  while (caseNum--) {
    memset(cabbages, 0, sizeof cabbages);
    cin >> col >> row;
    cin >> cabbageNum;

    while(cabbageNum--) {
      cin >> tempX >> tempY;
      cabbages[tempX+1][tempY+1] = -1;
    }

    //print();

    int wormNum = 0;
    for(int i = 1; i <= row; i++) {
      for (int j = 1; j <= col; j++) {
	if (cabbages[j][i] == -1) {
	  //cout << "call f in i : " << i << " j : " << j << endl;
	  wormArea(++wormNum, j, i);
	  //print();
	}
      }
    }

    cout << wormNum << endl;

   
  }
  
  return 0;
}
