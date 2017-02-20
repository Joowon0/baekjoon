#include <iostream>

using namespace std;

bool m[64][64];

void compress(int x, int y, int val) {
  //cout << "[" << x << "][" << y << "] : " << val << endl;
  // if leng == 1
  if (val == 1) {
    cout << m[x][y];
    return;
  }

  // check if all of them is the same
  bool which = m[x][y], ifAll = true;
  
  for (int i = x; i < x+val; i++) {
    for (int j = y; j < y+val; j++) {
      if (m[i][j] != which) {
	ifAll = false;
	break;
      }
    }
    if (ifAll == false)
	break;
  }

  if (ifAll) {
    cout << which;
    return;
  }
  // all is not same
  // have to check 4 parts
  else {
    cout << "(";
    // leftup
    which = m[x][y]; ifAll = true;
    for (int i = x; i < x+val/2; i++) {
      for (int j = y; j < y+val/2; j++)
	if (m[i][j] != which) {
	  ifAll = false;
	  break;
	}
      if (ifAll == false)
	break;
    }
    if (ifAll)
      cout << which;
    else
      compress(x,y,val/2);

    // rightup
    which = m[x][y+val/2]; ifAll = true;
    for (int i = x; i < x+val/2; i++) {
      for (int j = y+val/2; j < y+val; j++)
	if (m[i][j] != which) {
	  ifAll = false;
	  break;
	}
      if (ifAll == false)
	break;
    }
    if (ifAll)
      cout << which;
    else
      compress(x,y+val/2,val/2);

    // leftdown
    which = m[x + val/2][y]; ifAll = true;
    for (int i = x+val/2; i < x+val; i++) {
      for (int j = y; j < y+val/2; j++)
	if (m[i][j] != which) {
	  ifAll = false;
	  break;
	}
      if (ifAll == false)
	break;
    }
    if (ifAll)
      cout << which;
    else
      compress(x+val/2,y,val/2);

    // rightdown
    which = m[x + val/2][y + val/2]; ifAll = true;
    for (int i = x+val/2; i < x+val; i++) {
      for (int j = y+val/2; j < y+val; j++)
	if (m[i][j] != which) {
	  ifAll = false;
	  break;
	}
      if (ifAll == false)
	break;
    }
    if (ifAll)
      cout << which;
    else
      compress(x+val/2,y+val/2,val/2);
    
    cout << ")";
  }
}



int main () {
  int caseNum;
  char t;
  
  cin >> caseNum;

  for (int i = 0; i < caseNum; i++)
    for (int j = 0; j < caseNum; j++) {
      cin >> t;
      if (t == '0')
	m[i][j] = false;
      else
	m[i][j] = true;
    }
  /*
  for (int i = 0; i < caseNum; i ++) {
    for (int j = 0; j < caseNum; j++)
      cout << m[i][j] << " ";
    cout << endl;
  }
  */
  compress(0,0,caseNum);
  cout << endl;
  
  return 0;
}
