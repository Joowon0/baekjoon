#include <iostream>

using namespace std;

int compNum, inNum;
int link[10002][10002];
int info[10002][2]; // 0 - num of data
                    // 1 - num of comp to hack

void print() {
  for (int i = 1; i <= compNum; i++) {
    cout << "Comp : " << i << "\tData : " << info[i][0] << "\tHack : " << info[i][1] << endl;
    for (int j = 0; j < compNum; j++)
      cout << link[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

int checkHackNum (int num) {
  // if counted before
  if (info[num][1] != -1)
    return info[num][1];
  // if no availalbe computers
  else if (info[num][0] == 0) {
    info[num][1] = 1;
    return 1;
  }
  // count number of computers
  else {
    int hack = 1;
    for (int i = 0; i < info[num][0]; i++)
      hack += checkHackNum(link[num][i]);
    
    info[num][1] = hack;
    return hack;
  }
}

int main() {
  // get input
  int from, to;
  cin >> compNum >> inNum;
  for (int i = 1; i <= compNum; i++)
    info[i][1] = -1;
  for (int i = 0; i < inNum; i++) {
    cin >> to >> from;
    link[from][info[from][0]++] = to;
  }  

  int max = checkHackNum(1);
  // check from front
  for (int i = 2; i <= compNum; i++) {
    int temp = checkHackNum(i);
    if (max < temp)
      max = temp;
  }

  // print if max
  for (int i = 1; i <= compNum; i++)
    if (max == info[i][1])
      cout << i << " ";
  cout << endl;

  //print();
  
  return 0;
}
