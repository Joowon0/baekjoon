#include <iostream>

using namespace std;

int main() {
  int caseNum;
  int antNum, stickLen, nth;
  int antIn[100000][2]; // [n][0] : ID
                        // [n][1] : position
  int antTemp[100000][2], antTemp2[100000][2];

  cin >> caseNum;

  while(caseNum--) {
    // get input
    cin >> antNum >> stickLen >> nth;

    for (int i = 0; i < antNum; i++) {
      cin >> antIn[i][1] >> antIn[i][0];
      antTemp[i][0] = 1;
      if (antIn[i][0] < 0)
	antTemp[i][0] = -1;
      antTemp[i][1] = antIn[i][1];
    }

    // calculate
    for (int sec = 1; true; sec++) {
      if (antTemp[0][1] !=  -1) {
	// if collision
	if (antTemp[0][1] == antTemp[1][1])
	  antTemp[0][0] *= -1;
	// go 1mm
	if (antTemp[0][0] == 1)
	  antTemp2[0][0] = antTemp[0][0] + 1;
	else
	  antTemp2[i][0] = antTemp[i][0] - 1;
      }
      // for every [i] and [i+1]
      for (int i = 1; i < antNum - 1; i++) {
	if (antTemp[i][1] != -1) { // skip fallen ants
	  // if collision
	  if (antTemp[i][1] == antTemp[i+1][1])
	    antTemp[i][0] *= -1;
	// go 1mm
	if (antTemp[i][0] == 1)
	  antTemp2[i][0] = antTemp[i][0] + 1;
	else
	  antTemp2[i][0] = antTemp[i][0] - 1;
	}
      }

      // check if fallen

      // copy antTemp2 to antTemp
    }
  }

  return 0;
}
