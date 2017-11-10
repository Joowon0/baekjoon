#include <iostream>
#include <algorithm>

using namespace std;

int size;
int map[30][30];

int print() {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++)
      cout << map[i][j] << " ";
    cout << endl;
  }
}

int fillInNext(int r, int c, int n) {
  map[r][c] = n;
  int next = 1;
  
  // up
  if (r-1 >= 0 && map[r-1][c] == 1) {
    map[r-1][c] = n;
    next += fillInNext(r-1, c, n);
  }
    
  // down
  if (r+1 < size && map[r+1][c] == 1) {
    map[r+1][c] = n;
    next += fillInNext(r+1, c, n);
  }
  
  // left
  if (c-1 >= 0 && map[r][c-1] == 1) {
    map[r][c-1] = n;
    next += fillInNext(r, c-1, n);
  }
  
  // right
  if (c+1 < size && map[r][c+1] == 1) {
    map[r][c+1] = n;
    next += fillInNext(r, c+1, n);
  }

  //cout << "r : " << r << "\tc : " << c << "\t - " << next << endl;

  return next;
}

int main() {
  // get input
  cin >> size;
  char temp;
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) {
      cin >> temp;
      map[i][j] = temp - '0';
    }

  int count = 2;
  int arr[650];
  // check every place
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (map[i][j] == 1) {
	arr[count] = fillInNext(i,j,count);
	count++;
      }
    }
  }

  //print();

  // sort in ascending
  sort(arr, arr+count);
  
  cout << count - 2 << endl;
  for (int i = 2; i < count; i++)
    cout << arr[i] << endl;
  
  return 0;
}
