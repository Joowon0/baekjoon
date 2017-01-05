#include <iostream>

using namespace std;

int main() {
  int a, b, c, temp;

  cin >> a >> b >> c;

  temp = b -a ;
  if (c-b > temp)
    temp = c- b;

  cout << temp - 1 << endl;
  
  return 0;
}
