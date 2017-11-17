#include <iostream>
#include <vector>

using namespace std;

class node {
public :
  int otherNode, dist;
  node(int c, int d) : otherNode(c), dist(d) {}
};

int caseNum;
std::vector<node> links[10002];
// 0 - parent
// 1 - distance
int dp1[10002], dp2[10002];

int print() {
  for (int i = 1; i < caseNum; i++)
    for (int j = 0; j < links[i].size(); j++)
    cout << i << " : " << links[i][j].otherNode << "\tDist : " << links[i][j].dist<< endl;
}

int print2() {
  for (int i = 1; i <= caseNum; i++)
    cout << i << " : " << dp1[i] << endl;
}

int print3() {
  for (int i = 1; i <= caseNum; i++)
    cout << i << " : " << dp2[i] << endl;
}

int findFar(int node, int dist) {
  for (int i = 0; i < links[node].size(); i++)
    if (dp1[links[node][i].otherNode] == -1) {
      dp1[links[node][i].otherNode] = dist + links[node][i].dist;
      findFar(links[node][i].otherNode, dist + links[node][i].dist);
    }
}

int findFar2(int node, int dist) {
  for (int i = 0; i < links[node].size(); i++)
    if (dp2[links[node][i].otherNode] == -1) {
      dp2[links[node][i].otherNode] = dist + links[node][i].dist;
      findFar2(links[node][i].otherNode, dist + links[node][i].dist);
    }
}

int main() {
  cin >> caseNum;
 
  int parent, child, dist;
  for (int i = 0; i < caseNum-1; i++) {
    cin >> parent;
    
    cin >> child;
    while (child != -1) {
      cin >> dist;

      links[parent].push_back(node(child, dist));
      links[child].push_back(node(parent, dist));
      dp1[parent] = dp1[child] = -1;
      dp2[parent] = dp2[child] = -1;

      cin >> child;
    }
  }

  //print();

  dp1[0] = dp1[1] = 0;
  findFar(1, 0);

  //print2();

  int max = 0, maxNode = 1;
  for (int i = 1; i <= caseNum; i++)
    if (max < dp1[i]) {
      max= dp1[i];
      maxNode = i;
    }
  //cout << maxNode << endl;

  dp2[maxNode] = 0;
  findFar2(maxNode, 0);

  //print3();

  int max2 = 0, maxNode2 = 1;
  for (int i = 1; i <= caseNum; i++)
    if (max2 < dp2[i]) {
      max2 = dp2[i];
      maxNode2 = i;
    }
  //cout << maxNode2 << endl;
  cout << max2 << endl;
  
  return 0;
}
