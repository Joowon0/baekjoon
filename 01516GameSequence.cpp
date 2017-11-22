#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int totalCost[502];
int arrowIn[502]; // num of node that is not calculated

int main() {
  int caseNum;
  vector<int> ownCost;
  vector<vector <int> > prerequisite; // for cost calculation
  vector<vector <int> > outGraph;     // for calcul sequence
  queue<int> q;


  // get input
  cin >> caseNum;
  ownCost.push_back(-1);
  prerequisite.resize(caseNum+1);
  outGraph.resize(caseNum+1);

  int temp;
  for (int i = 1; i <= caseNum; i++) {
    cin >> temp;
    ownCost.push_back(temp);

    cin >> temp;
    while ( temp != -1 ) {
      prerequisite[i].push_back(temp);
      outGraph[temp].push_back(i);
      arrowIn[i]++;
      cin >> temp;
    }
  }

  // initialize
  for (int i = 1; i <= caseNum; i++)
    if (arrowIn[i] == 0)
      q.push(i);


  // check
  while(!q.empty()) {
    // remove from queue
    int top = q.front();
    //cout << "TOP : " << top << endl;
    q.pop();

    // calculate total cost for top
    int maxCount = 0;
    for(int i = 0; i < prerequisite[top].size(); i++) {
      if (maxCount < totalCost[prerequisite[top][i]])
	maxCount = totalCost[prerequisite[top][i]];
    }
    //totalCount += ownCost[top];
    totalCost[top] = maxCount + ownCost[top];

    // put (in == 0) node in queue
    for (int i = 0; i <  outGraph[top].size(); i++) {
      arrowIn[outGraph[top][i]]--;
      if (arrowIn[outGraph[top][i]] == 0)
	q.push(outGraph[top][i]);
    }
  }

  // print resuilt
  for (int i = 1; i <= caseNum; i++)
    cout << totalCost[i] << endl;
  
  return 0;
}
