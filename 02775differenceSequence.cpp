#include <iostream>

using namespace std;

int main() {
  int caseNum;
  int apartment[15][15];
  int floor, room;

  // initiate
  for (int i = 0; i < 15; i++) {
    apartment[0][i] = i;
    apartment[i][0] = 0;
  }

  // fill in
  for (int i = 1; i < 15; i++) {
    for (int j = 1; j < 15; j++) {
      apartment[i][j] = apartment[i-1][j] + apartment[i][j-1];
    }
  }
  /*
  for (int i = 0; i < 15; i++) {
    for (int j = 1; j < 15; j++)
      cout << apartment [i][j] << " ";
    cout << endl;
  }
  */
  
  cin >> caseNum;

  while(caseNum--) {
    cin >> floor >> room;

    cout << apartment[floor][room] << endl;
  }
  
  
  return 0;
}
