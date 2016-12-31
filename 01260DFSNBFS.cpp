#include <iostream>

using namespace std;

int nodeNum, linkNum, startNum;
int edge[1001][1001];
int DFS[1001], Dtemp = 0;
int BFS[1001], BtempR = 0; 

void DFSfunc(int start) {
  DFS[Dtemp++] = start;
  
  for (int i = 1; i < nodeNum + 1; i++) {
    // if it is linked
    if (i != start && edge[start][i] == 1) {
      //cout << "start checking " << i << endl;
      // if not visited
      int isChecked = 0;
      for (int j = 0; j < Dtemp; j++) {
	if (DFS[j] == i) {
	  isChecked = 1;
	  break;
	}
      }
      if (isChecked == 1) {
	//cout << "node " << i << " is checked before" << endl;
	continue;
      }
      else {
	//cout << "node " << i << " is not checked before" << endl;
	DFSfunc(i);
      }
    }
  }
}

void BFSfunc(int start) {
  int BtempF = 0;
  BFS[BtempR++] = start;

  while (BtempF != BtempR) {
    for (int i = 1; i < nodeNum+1; i++) {
      // if it is linked    
      if (i != BFS[BtempF] && edge[BFS[BtempF]][i] == 1) {
	//cout << endl << "start checking " << i << endl;
	// if not visited
	int isChecked = 0;
	for (int j = 0; j < BtempR; j++) {
	  if (BFS[j] == i) {
	    isChecked = 1;
	    break;
	  }
	}
	if (isChecked == 1) {
	  //cout << "node " << i << " is checked before" << endl;
	  continue;
	}
	else {
	  //cout << "node " << i << " is not checked before" << endl;
	  BFS[BtempR++] = i;
	}
      }
    }
    BtempF++;
  }
}

int main() {
  // get input
  int tempA, tempB;
  cin >> nodeNum >> linkNum >> startNum;

  for (int i = 0; i < linkNum; i++) {
    cin >> tempA >> tempB;

    edge[tempA][tempB] = 1;
    edge[tempB][tempA] = 1;
  }

  // print for check
  /*
  cout << "    1 2 3 4 5 6 7"<< endl;
  for (int i = 1; i < nodeNum + 1; i++) {
    cout << i << " : ";
    for (int j = 1; j < nodeNum + 1; j++) {
      cout << edge[i][j] << " ";
    }
    cout << endl;
  }
  */
  
  DFSfunc(startNum);
  for (int i = 0; i < Dtemp; i++)
    cout << DFS[i] << " ";
  cout << endl;

  BFSfunc(startNum);
  for (int i = 0; i < BtempR; i++)
    cout << BFS[i] << " ";
  cout << endl;
  
  return 0;
}
