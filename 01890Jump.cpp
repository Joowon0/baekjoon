#include <iostream>

using namespace std;

unsigned long long size;
unsigned long long space[102][102];
unsigned long long times[102][102];

int print() {
  for (unsigned long long r = 0; r < size; r++) {
    for (unsigned long long c = 0; c < size; c++)
      cout << times[r][c] << " ";
    cout << endl;
  }
}

int main() {
  // get input
  cin >> size;
  for (unsigned long long r = 0; r < size; r++)
    for (unsigned long long c = 0; c < size; c++)
      cin >> space[r][c];

  // initialize
  times[0][0] = 1;
  
  // check step by step
  for (unsigned long long r = 0; r < size; r++) {
    for (unsigned long long c = 0; c < size; c++){
      // end point
      if (space[r][c] == 0) {
	cout << times[r][c] << endl;
	return 0;
      }	
      
      // check right
      if (space[r][c]+r < size)
	times[r + space[r][c]][c] += times[r][c];
      
      // check down
      if (space[r][c]+c < size)
	times[r][c + space[r][c]] += times[r][c];

      //cout <<endl;
      //cout << "r : " << r << "\tc : " << c << endl;
      //print();
    }
  }
  return 0;
}
