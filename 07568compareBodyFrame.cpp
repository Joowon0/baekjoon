#include <iostream>

using namespace std;

// print for test
void print4Test(int num, int s[][3]) {
  for (int i = 0; i < num; i++) {
    for (int j = 0; j < 3; j++) {
      cout << s[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}


int main() {
  // get input
  int num;
  cin >> num;
  int size[num][3];

  for (int i = 0; i < num; i++) {
    cin >> size[i][0] >> size[i][1];
    size[i][2] = 1;
  }

  //print4Test(num, size);

  for (int i = 0; i < num; i++) {
    for (int j = 0; j < num; j++) {
      if (i != j) {
	if (size[i][0] < size[j][0] && size[i][1] < size[j][1])
	  size[i][2]++;
      }
    }
  }

  //print4Test(num, size);

  for (int i = 0; i < num; i++)
    cout << size[i][2] << " ";
  cout << endl;
  
  return 0;
}
