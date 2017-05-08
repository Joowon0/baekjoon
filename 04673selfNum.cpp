#include <iostream>

using namespace std;

bool mem[10000];

int main() {
  int temp;

  for (int i = 1; i < 10000; i++) {
    //cout << i << " : " << i / 1000 << i / 100 % 10 << i / 10 % 10 << i % 10
    //	 << " " << i + i/1000 + i/100%10 + i/10%10 + i%10 << endl;
    temp = i + i/1000 + i/100%10 + i/10%10 + i%10;
    
    if (temp < 10000)
      mem[temp] = true;
  }

  
  for (int i = 1; i < 10000; i++) {
    if (mem[i] == false)
      cout << i << endl;
  }
  
  return 0;
}
