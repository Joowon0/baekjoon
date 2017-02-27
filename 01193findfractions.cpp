#include <iostream>

using namespace std;

int main() {
  int nth;
  int down = 1, up = 1;

  cin >> nth;

  for (int i = 0; i < nth - 1; i++) {
    // going up right
    if ((down + up) % 2 == 0) {
      if(up == 1) // end of the diagonal
	down++;
      else {
	up--;
	down++;
      }
    }
    // going down left
    else {
      if (down == 1) // end of the diagonal
	up++;
      else {
	up++;
	down--;
      }
    }
  }
  cout << up << "/" << down << endl;
  
  return 0;
}
