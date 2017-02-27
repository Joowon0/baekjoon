#include <iostream>

using namespace std;

int main() {
  int caseNum;
  int width, height, nth;

  int rw, rh;

  cin >> caseNum;

  while(caseNum--) {
    cin >> height >> width >> nth;

    // find out room number
    for (rw = 1; nth > height; rw++)
      nth -= height;

    cout << nth;
    
    // print
    if (rw < 10)
      cout << "0";
    cout << rw << endl;
  }
  
  return 0;
}
