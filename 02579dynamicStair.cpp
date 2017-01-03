#include <iostream>

using namespace std;

int main() {
  int stairNum, stair[301];
  int stairSum[301][2]; // [n][0] might stepped on [n-1]
                        // [n][1] not stepped on [n-1]
  int temp;

  cin >> stairNum;
  for (int i = 1; i <= stairNum; i++)
    cin >> stair[i];

  stairSum[1][0] = stair[1];
  stairSum[1][1] = stair[1];
  stairSum[2][0] = stair[2] + stairSum[1][0];
  stairSum[2][1] = stair[2];

  for (int i = 3; i <= stairNum; i++) {
    // fill stairSum[i][1] (not stepped on stair[i-1])
    temp = stairSum[i-2][0];
    if (temp < stairSum[i-2][1])
      temp = stairSum[i-2][1];
    stairSum[i][1] = stair[i] + temp;

    // fill stairSum[i][0] (might stepped on stair[i-2])
    if (temp < stairSum[i-1][1])
      temp = stairSum[i-1][1];
    stairSum[i][0] = stair[i] + temp;
  }

  temp = stairSum[stairNum][0];
  if (temp < stairSum[stairNum][1])
    temp = stairSum[stairNum][1];
  cout << temp << endl;
  //for (int i = 1; i <= stairNum; i++)
  //  cout << stairSum[i][0] << " " << stairSum[i][1] << endl;
  
  return 0;
}
