#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int graph[502][502];

int main() {
  int caseNum;
  cin >> caseNum;

  while (caseNum--) {
    // get input
    int nodeNum, changeNum;
    cin >> nodeNum;
    for(int i = 0; i <= nodeNum; i++)
      memset(graph+i, 0, sizeof(int) * (nodeNum+1));

    int temp;
    bool checkTemp[nodeNum+1] = {0,};
    for(int i = 0; i < nodeNum; i++) {
      cin >> temp;
      checkTemp[temp] = 1;
      for (int j = 1; j <= nodeNum; j++)
	if (checkTemp[j] == 0)
	  graph[temp][j] = 1;
    }

    cin >> changeNum;
    int temp1, temp2;
    for(int i = 0; i < changeNum; i++) {
      cin >> temp1 >> temp2;
      if (graph[temp1][temp2] && !graph[temp2][temp1]) {
	graph[temp1][temp2] = 0;
	graph[temp2][temp1] = 1;
      }
      else if (!graph[temp1][temp2] && graph[temp2][temp1]) {
	graph[temp1][temp2] = 1;
	graph[temp2][temp1] = 0;
      }
      else
	cout << "ERROR" << endl;
    }

    /*
    // print for test
    for (int i = 1; i <= nodeNum; i++) {
      for (int j = 1; j <= nodeNum; j++)
	cout << graph[i][j] << " ";
      cout << endl;
    }
    */

    // check if exception
    bool checkException[nodeNum+1] = {0,};
    bool checkFlag = 0;
    int countIn;
    for (int i = 1; i <= nodeNum; i++) {
      // count number of ones
      countIn = 0;
      for (int j = 1; j <= nodeNum; j++)
	if (graph[i][j])
	  countIn++;

      // check if ERROR
      if (!checkException[countIn])
	checkException[countIn] = 1;
      else {
	checkFlag = 1;
	break;
      }
    }
    if (checkFlag == 1) {
      cout << "IMPOSSIBLE" << endl;
    }
    else {
      // calculate (topological sorting starts here)
      int in[nodeNum+1] = {0,};
      queue <int> q;
      queue <int> result;
      
      for (int i = 1; i <= nodeNum; i++) {
	for (int j = 1; j <= nodeNum; j++) {
	  if (graph[i][j])
	    in[j]++;
	}
      }
      /*
      // print for test
      for (int i = 1; i <= nodeNum; i++)
	cout << i << " : " << in[i] << endl;
      cout << endl;
      */

      for (int i = 1; i <= nodeNum; i++)
	if (!in[i])
	  q.push(i);

      while(!q.empty()) {
	int top = q.front();
	q.pop();
	result.push(top);

	for (int i = 1; i <= nodeNum; i++) {
	  if (graph[top][i]) {
	    in[i]--;
	    if (!in[i])
	      q.push(i);
	  }
	}	
      }
      /*
      // print for test
      cout << "RESULT (" << q.size() << ") : ";
      for (int i = 0; i < nodeNum; i++) {
	cout << result.front() << " ";
	result.pop();
      }
      cout << endl << endl;
      */
      // print result
      if (result.size() != nodeNum)
	cout << "IMPOSSIBLE" << endl;
      else {
	for (int i = 0; i < nodeNum; i++) {
	  cout << result.front() << " ";
	  result.pop();
	}
	cout << endl;
      }
    }
  }
  
  return 0;
}
