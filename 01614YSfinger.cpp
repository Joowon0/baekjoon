#include <iostream>

using namespace std;

int main() {
  long long hurtFinger, maxtime;

  cin >> hurtFinger >> maxtime;

  long long totalTime;
  if (hurtFinger == 1 || hurtFinger == 5) {
    totalTime = maxtime * 8;
    if (hurtFinger == 5)
      totalTime += 4;
  }
  else {
    totalTime = (maxtime/2) * 8;
    if (maxtime % 2 == 0)
      totalTime += (hurtFinger - 1);
    else
      totalTime += (9 - hurtFinger);
    // 4 - 5
    // 3 - 6
    // 2 - 7
  }

  cout << totalTime << endl;
  
  return 0;
}
