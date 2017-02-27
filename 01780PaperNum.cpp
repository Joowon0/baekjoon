#include <iostream>

using namespace std;

int mat[2500][2500];
int vals[3]; // vals[0] <- -1
             // vals[1] <-  0
             // vals[2] <-  1 


void calcul(int x, int y, int size) {
  if (size == 1) {
    vals[mat[x][y]+1]++;
    return;
  }
  
  int firstMatch = mat[x][y];
  bool ifSame = true;
  for (int i = x; i < x + size; i++) {
    for (int j = y; j < y + size; j++)
      if (mat[i][j] != firstMatch) {
	ifSame = false;
	break;
      }
    if (!ifSame)
      break;
  }

  // if all of numbers are same
  if (ifSame) {
    vals[mat[x][y]+1]++;
    return;
  }
  // check all 9 cases
  else {
    int newSize = size / 3;
    calcul(x, y, newSize);
    calcul(x + newSize, y, newSize);
    calcul(x + newSize * 2, y, newSize);
    
    calcul(x, y + newSize, newSize);
    calcul(x + newSize, y + newSize, newSize);
    calcul(x + newSize * 2, y + newSize, newSize);

    calcul(x, y + newSize * 2, newSize);
    calcul(x + newSize, y + newSize * 2, newSize);
    calcul(x + newSize * 2, y + newSize * 2, newSize);
  }	
}

int main () {
  int caseNum;

  vals[0] = vals[1] = vals[2] = 0;

  cin >> caseNum;
  for (int i = 0; i < caseNum; i ++)
    for (int j = 0; j < caseNum; j++)
      cin >> mat[i][j];

  calcul(0,0,caseNum);

  for (int i = 0; i < 3; i++)
    cout << vals[i] << endl;
  
  
  return 0;
}
