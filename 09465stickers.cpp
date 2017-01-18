#include <iostream>

using namespace std;

int main() {
  int caseNum, length;
  int costs[100000][2], memo[100000][2];
  int temp, max, answer;

  cin >> caseNum;

  while(caseNum--) {
    cin >> length;

    for (int i = 0; i <length; i++)
      cin >> costs[i][0];
    for (int i = 0; i <length; i++)
      cin >> costs[i][1];

    // initiate
    memo[0][0] = costs[0][0]; memo[1][0] = costs[1][0] + costs[0][1];
    memo[0][1] = costs[0][1]; memo[1][1] = costs[1][1] + costs[0][0];

    for (int i = 2; i < length; i++) {
      // max of memo[i][0] and memo[i][1]
      max = memo[i-2][0];
      temp = memo[i-2][1];
      if (max < temp)
	max = temp;

      // fill in memo[i][0]
      memo[i][0] = max;
      if (max < memo[i-1][1])
	memo[i][0] = memo[i-1][1];
      memo[i][0] += costs[i][0];
      // fill in memo[i][1]
      memo[i][1] = max;
      if (max < memo[i-1][0])
	memo[i][1] = memo[i-1][0];
      memo[i][1] += costs[i][1];
    }
    /*
    // print for test
    for (int j = 0; j < length; j++)
      cout << memo[j][0] << " ";
    cout << endl;
    for (int j = 0; j < length; j++)
      cout << memo[j][1] << " ";
    cout << endl;
    */

    answer = memo[length-1][0];
    if (answer < memo[length-1][1])
      answer = memo[length-1][1];

    cout << answer << endl;
  }
  
  return 0;
}
