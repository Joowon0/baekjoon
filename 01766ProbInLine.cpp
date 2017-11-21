#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int in[2001];

int main() {
  int probNum, infoNum;
  vector< vector<int> > graph;
  // store num (x -1) 'cause we want small to big num
  priority_queue<int> q;

  // get input
  cin >> probNum >> infoNum;
  graph.resize(probNum+1);
  
  int temp1, temp2;
  for (int i = 0; i < infoNum; i++) {
    cin >> temp1 >> temp2;
    graph[temp1].push_back(temp2);
    in[temp2]++;
  }

  // initialize queue
  for (int i = 1; i <= probNum; i++)
    if (in[i] == 0)
      q.push(-i);

  // check
  while(!q.empty()) {
    int top = -q.top();
    q.pop();
    cout << top << " ";
    for (int i = 0; i < graph[top].size(); i++) {
      in[graph[top][i]]--;
      if (in[graph[top][i]] == 0)
	q.push(-graph[top][i]);
    }
  }
  cout << endl;
  
  return 0;
}
