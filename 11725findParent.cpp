#include <stdio.h>
#include <iostream>
#include <vector>

int caseNum;
//int linkNum[100002];
std::vector<int> links[100002];
int parent[100002];
/*
void print() {
  for (int i = 1 ; i <= caseNum ; i++) {
    cout << i << " : ";
    for (int j = 0; j < linkNum[i]; j++)
      cout << links[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

void print2() {
  for (int i = 1; i <= caseNum; i++)
    cout << i << " : " << parent[i] << endl;
}
*/
void findRoot(int par) {
  for (int i = 0; i < links[par].size(); i++)
    if (parent[links[par][i]] == 0) {
      parent[links[par][i]] = par;
      findRoot(links[par][i]);
    }
}

int main() {
  scanf("%d", &caseNum);

  int temp1, temp2;
  for (int i = 0; i < caseNum-1; i++) {
    scanf("%d %d", &temp1, &temp2);
    links[temp1].push_back(temp2);
    links[temp2].push_back(temp1);
    /*
    links[temp1][linkNum[temp1]] = temp2;
    links[temp2][linkNum[temp2]] = temp1;
    linkNum[temp1]++;
    linkNum[temp2]++;
    */
  }

  //print();

  parent[1] = 1;
  findRoot(1);

  //print2();


  for (int i = 2; i <= caseNum; i++)
    printf("%d\n", parent[i]);
  
  return 0;
}
