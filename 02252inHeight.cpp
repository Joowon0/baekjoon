#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int in[32002];

int main() {
  int studNum, inNum;

  vector< vector<int> > graph;
  priority_queue<int> q;

  // get input
  cin >> studNum >> inNum;
  graph.resize(studNum+1);
  int temp1, temp2;
  for (int i = 0; i < inNum; i++) {
    cin >> temp1 >> temp2;
    graph[temp1].push_back(temp2);
    in[temp2]++;
  }

  // initialize queue
  for (int i = 1; i <= studNum; i++)
    if (in[i] == 0)
      q.push(i);

  //for (int i = 0; i < q.size(); i++)
  //  cout << q[i] << " " ;
  //cout << endl;

  // check
  while(!q.empty()) {
    int top = q.top();
    q.pop();
    cout << top << " ";
    for (int i = 0; i < graph[top].size(); i++) {
      in[graph[top][i]]--;
      if(in[graph[top][i]] == 0) {
	q.push(graph[top][i]);
      }
	
    }
  }
    
    
  return 0;
}
