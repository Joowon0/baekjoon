#include <iostream>

using namespace std;

int main() {
  char s1[3] = {'0', '0', '0'}, s2[3] = {'0', '0', '0'};
  int x1, x2;

  cin >> s1 >> s2;

  x1 = (s1[2]-'0') * 100 + (s1[1]-'0') * 10 + (s1[0]-'0') * 1;
  x2 = (s2[2]-'0') * 100 + (s2[1]-'0') * 10 + (s2[0]-'0') * 1;

  if (x1 > x2)
    cout <<x1 << endl;
  else
    cout << x2 << endl;

  
  
  return 0;
}
