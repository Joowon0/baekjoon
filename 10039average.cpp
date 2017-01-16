#include <iostream>

using namespace std;

int main() {
  int n[5], sum = 0;

  for (int i = 0; i < 5; i++) {
    cin >> n[i];
    if (n[i] < 40)
      n[i] = 40;
    sum += n[i];
  }

  cout << sum / 5 << endl;
  
  return 0;
}
