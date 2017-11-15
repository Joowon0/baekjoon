#include <iostream>

using namespace std;

int caseNum;
int connection[100002][10002]; // index 0 - num of links
int parent[100002];

void print() {
  for (int i = 0; i < caseNum; i++) {
  }
}

int main() {
  
  cin >> caseNum;

  int temp1, temp2;
  for (int i = 0; i < caseNum; i++) {
    cin >> temp1 >> temp2;
    connection[temp1][0]++;
    connection[temp2][0]++;

    connection[temp1][connection[temp1][0]] = temp2;
    connection[temp2][connection[temp2][0]] = temp1;
  }

  
  
  return 0;
}
