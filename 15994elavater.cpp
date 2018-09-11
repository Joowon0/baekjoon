#include <iostream>
#include <vector>
#include <climits>
#include <string.h>
#include <algorithm>

using namespace std;

int height, elevatorNum;
vector <vector <int>> elevatorInfo;
int starts, target;
int elevatorConnection[100][100];
vector<vector<int>> reachCost;
int targetElevator[100], targetNum;
// used in shortLength()
int shortLen = INT_MAX;
int shortOrder[100];

int checkIfCross(int a, int b) {
  int aCounter = elevatorInfo[a][0];
  int aDiff    = elevatorInfo[a][1];
  
  int bStart = elevatorInfo[b][0];
  int bDiff  = elevatorInfo[b][1];
  
  while(aCounter <= height) {
    if ((aCounter - bStart) % bDiff == 0) {
      elevatorConnection[a][b] = 1;
      elevatorConnection[b][a] = 1;
      return aCounter;
    }
    aCounter += aDiff;
  }
  return -1;
}

int canbeReached(int elevatorNum, int floor) {
  if ((floor - elevatorInfo[elevatorNum][0]) % elevatorInfo[elevatorNum][1] == 0)
    return true;
  else
    return false;
}

void shortLength(int elevatorOrder[], int lenCounter, int lastElevator) {
  // base case : cannot reach
  if (lenCounter >= elevatorNum) {
    return;
  }
  
  for(int i = 0; i < elevatorNum; i++) {
    // pass if already visited
    if (elevatorOrder[i] != 0)
      continue;
    // pass if cannot reach
    if (elevatorConnection[lastElevator][i] == 0)
      continue;

    elevatorOrder[i] = lenCounter;
    // return if reached
    for (int j = 0; j < targetNum; j++)
      if (targetElevator[j] == i) {
	// update if shorter
	if (lenCounter < shortLen) {
	  shortLen = lenCounter;
	  for (int j = 0; j < elevatorNum; j++) // deep copy
	    shortOrder[j] = elevatorOrder[j];
	}
      }
    
    // check length for each possibility
    shortLength(elevatorOrder, lenCounter+1, i);
    
    // print for test
    // cout << "LEN : " << len << endl;
    // for(int j = 0; j < elevatorNum; j++)
    //   cout << elevatorOrder[j] << " ";
    // cout << endl;

    // turn back to original array for next time
    elevatorOrder[i] = 0;
  }
}

int main() {
  // get input
  cin >> height >> elevatorNum;

  elevatorInfo.resize(elevatorNum);
  reachCost.resize(elevatorNum);
  for (int i = 0; i < elevatorNum; i++) {
    int base, diff;
    cin >> base >> diff;
    elevatorInfo[i].push_back(base);
    elevatorInfo[i].push_back(diff);
    
    reachCost[i].resize(elevatorNum);
  }
  
  cin >> starts >> target;

  // check Connections
  for (int i = 0; i < elevatorNum; i++)
    for (int j = i + 1; j < elevatorNum; j++)
      checkIfCross( i, j);

  // find out target elevators
  targetNum = 0;
  for (int i = 0; i < elevatorNum; i++)
    if (canbeReached(i, target)) {
      targetElevator[targetNum] = i;
      targetNum++;
    }

  // cout << "<Target Elevators>" << endl;
  // for (int i = 0; i < targetNum; i++)
  //   cout << targetElevator[i] << " ";
  // cout << endl;
  
  // find the shortest length
  int elevatorOrder[elevatorNum];
  memset( elevatorOrder, 0, sizeof elevatorOrder);
  for (int i = 0; i < elevatorNum; i++)
    if (canbeReached(i, starts)) {
      elevatorOrder[i] = 1;
      shortLength(elevatorOrder, 2, i);
    }

  
  // print test
  // cout << height << " " << elevatorNum << endl;
  // for (int i = 0; i < elevatorNum; i++)
  //   cout << elevatorInfo[i][0] << " : " << elevatorInfo[i][1] << endl;
  // cout << starts << " ~ " << target << endl;
  
  // for (int i = 0; i < elevatorNum; i++) {
  //   for (int j = 0; j < elevatorNum; j++)
  //     cout << elevatorConnection[i][j] << " ";
  //   cout << endl;
  // }


  // make for result
  vector<vector<int>> orderNum; // (elevator order, elevator num)
  for (int i = 0; i < elevatorNum; i++)
    if (shortOrder[i] != 0) {
      vector<int> temp;
      temp.push_back(shortOrder[i]);
      temp.push_back(i+1);
      
      orderNum.push_back(temp);
    }

  sort(orderNum.begin(), orderNum.end());
  
  // cout << endl;
  cout << shortLen << endl;
  for (int i = 0; i < orderNum.size(); i++)
    cout << orderNum[i][1] << endl;
  // cout << endl;
  
  return 0;
}
