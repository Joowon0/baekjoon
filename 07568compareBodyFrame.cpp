#include <iostream>
#include <stdlib.h>

using namespace std;

// print for test
void print4Test(int num, int s[][4]) {
  for (int i = 0; i < num; i++) {
    for (int j = 0; j < 4; j++) {
      cout << s[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int cmpHeight (const void * a, const void * b) {
  // if same height, compare weight
  if (*(int *)a == *(int *)b) {
    int num1 = *((int *)a + 1);
    int num2 = *((int *)b + 1);

    if (num1 < num2) return 1;
    else if (num1 > num2) return -1;
    else return 0;
  }
  // compare height
  else {
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2) return 1;
    if (num1 > num2) return -1;
    else return 0;
  }
}

// go back to original order
int cmpOrd (const void * a, const void * b) {
  int num1 = *((int *)a + 2);
  int num2 = *((int *)b + 2);
  if (num1 < num2) return -1;
  if (num1 > num2) return 1;
  else return 0;
}

int main() {
  // get input
  int num;
  cin >> num;
  int size[num][4];

  for (int i = 0; i < num; i++) {
    cin >> size[i][1] >> size[i][0];
    size[i][2] = i + 1;
    size[i][3] = 0;
  }

  //print4Test(num, size);

  qsort(size, num, sizeof(int) * 4, cmpHeight);

  //print4Test(num, size);

  int ord = 1;
  for (int i = 0; i < num - 1; i++) {
    // if prior is bigger than latter
    if (size[i][0] > size[i+1][0] && size[i][1] > size[i+1][1]) {
      size[i][3] = ord;
      ord = i + 2;
    }
    // if uncomparable
    else {
      size[i][3] = ord;
    }
  }
  //  if (size[num-2][0] > size[num-1][0] && size[num-2][1] > size[num-1][1])
  size[num-1][3] = ord;
  //else
  //size[num-1][3] = ord + 1;

  print4Test(num, size);

  qsort(size, num, sizeof(int) * 4, cmpOrd);

  print4Test(num, size);

  for (int i = 0; i < num; i++)
    cout << size[i][3] << " ";
  cout << endl;
  
  return 0;
}
