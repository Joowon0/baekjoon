#include <iostream>

using namespace std;

int main() {
  int n[8];
  bool b;
  
  for (int i = 0; i < 8; i++)
    cin >> n[i];

  // check ascending
  b = 1;
  for (int i = 1; i <= 8; i++) {
    if (n[i-1] != i) {
      b = 0;
      break;
    }
  }

  if (b == 1) {
    cout << "ascending" << endl;
    return 0;
  }

  // check descending
  b = 1;
  for (int i = 0; i < 8; i++) {
    if (n[i] != 8 - i) {
      b = 0;
      break;
    }
  }

  if (b == 1) {
    cout << "descending" << endl;
    return 0;
  }

  // else
  cout << "mixed" << endl;
  
  
  return 0;
}
