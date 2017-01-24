#include <iostream>
#include <stdlib.h> // qsort

using namespace std;

int compare (const void * a, const void * b) {
  return ( (*(int*) a) - (*(int*) b) );
}

int main() {
  int caseNum;
  int antNum, stickLen, nth;
  int antIn[100000][2]; // [n][0] : ID
                        // [n][1] : position
  int antTemp[100000][2], antTemp2[100000][2];
  int inIdOrder[10000][2]; // [n][0] : abs (ID)
                           // [n][1] : index

  int cnt;
  bool ifEnd = 0;
  
  cin >> caseNum;

  while(caseNum--) {
    // get input
    cin >> antNum >> stickLen >> nth;

    cnt = 0;

    for (int i = 0; i < antNum; i++) {
      cin >> antIn[i][1] >> antIn[i][0];
      antTemp[i][0] = 1;
      if (antIn[i][0] < 0)
	antTemp[i][0] = -1;
      antTemp[i][1] = antIn[i][1];

      if (antIn[i][0] > 0)
	inIdOrder[i][0] = antIn[i][0] - 1;
      else
	inIdOrder[i][0] = (antIn[i][0] + 1);
      inIdOrder[i][1] = i;
    }

    // fill in inIdOrder[][]
    qsort (inIdOrder, antNum, sizeof(int) * 2, compare);

    for (int i = 0; i < antNum; i++)
      if (inIdOrder[i][0] < 0)
	inIdOrder[i][0] *= -1;

    /*
    // print for test
    for (int i = 0; i < antNum; i++) {
      cout << inIdOrder[i][0] << " " << inIdOrder[i][1] << endl;
    }
    
    for (int i = 0; i < antNum; i++) {
      cout << antTemp[i][1] << " " << antTemp[i][0] << "\t";
    }
    cout << endl;
    */

    // calculate
    for (int sec = 1; true; sec++) {
      // for every [i] and [i+1]
      for (int i = 0; i < antNum; i++) {
	if (antTemp[i][0] != 0) { // skip fallen ants
	  // if collision
	  // case1 : when at the same place
	  if (i != antNum -1 && antTemp[i+1][1] == antTemp[i][1]) {
	    antTemp[i][0] *= -1;
	    antTemp[i+1][0] *= -1;
	  }
	  /*
	  else if (i != antNum && antTemp[i][1] == antTemp[i-1][1]) {
	    antTemp[i][0] *= -1;
	    antTemp[i-1][0] *= -1;
	  }
	  */

	  // case2 : when about to collid in 0.5 sec
	  else if (i != 0 && antTemp[i+1][1] - antTemp[i][1] == 1 && antTemp[i+1][0] == -1 && antTemp[i][0] == 1) {
	    //cout << "collid : " << i << " " << i+1 << endl;
	    antTemp[i][0] *= -1;
	    antTemp[i+1][0] *= -1;
	    i ++;
	    break;
	  }
	  
	  
	  
	// go 1mm
	if (antTemp[i][0] == 1)
	  antTemp2[i][1] = antTemp[i][1] + 1;
	else
	  antTemp2[i][1] = antTemp[i][1] - 1;
	}
      }

      ifEnd = 0;
      
      // check if fallen
      for (int i = 0; i < antNum; i++) {
	if (antTemp[inIdOrder[i][1]][0] != 0 && (antTemp2[inIdOrder[i][1]][1] < 0 || antTemp2[inIdOrder[i][1]][1] > stickLen)) {
	  antTemp[inIdOrder[i][1]][0] = 0;

	  // check if ends
	  cnt++;

	  cout << cnt << " " << inIdOrder[i][1] << " " << antIn[inIdOrder[i][1]][0] << endl;
	  if (cnt == nth) {
	    ifEnd = 1;
	    cout << antIn[inIdOrder[i][1]][0] << endl;
	    break;
	  }
	}
      }

      if (ifEnd == 1)
        break;
	  

      // copy antTemp2 to antTemp
      for (int i = 0; i < antNum; i++) {
	//antTemp[i][0] = antTemp2[i][0];
	antTemp[i][1] = antTemp2[i][1];

	cout << antTemp[i][1] << " " << antTemp[i][0] << "\t";
      }
      cout << endl;
    }
  }

  return 0;
}
