#include <iostream>

using namespace std;

int base[1000001];

int make1(int x) {
  //cout << x << endl;
  if (x == 2)
    return 1;
  else if (x == 3)
    return 1;
  
  else {
    int temp = 600000000, x3 = 0, x2 = 0, x1 = 0;
    //cout << x << " " << x % 3 << endl;
    if (x % 3 == 0) {
      //cout << "YES" << endl;
      if (base[x / 3] != 0) {
	x3 = base[x / 3];
      }
      else {
	base[x/3] = make1(x / 3) + 1;
	x3 = base[x / 3];
      }
      if (temp > x3) // find min
	temp = x3;
    }
    if (x % 2 == 0) {
      if (base[x / 2] != 0) {
	x2 = base[x / 2];
      }
      else {
	base[x/2] = make1(x / 2) + 1;
	x2 = base[x/2];
      }
      if (temp > x2) // find min
	temp = x2;
    }
    if (base[x - 1] != 0) {
      x1 = base[x - 1];
    }
    else {
      base[x-1] = make1(x - 1) + 1;
      x1 = base[x-1];
    }
    
    if (temp > x1) // find min
      temp = x1;

    //cout << x << " "  << x3 << " " << x2 << " " << x1 << " " << temp << endl;

    return temp;
  }
}

int main () {
  int numIn;
  
  cin >> numIn;

  cout << make1(numIn) << endl;

  return 0;
}
