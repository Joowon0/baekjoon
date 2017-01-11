#include <iostream>
#include <string.h>

using namespace std;

int caseNum, buildingNum, ruleNum;
int buildingCost[1001], rules[100001][2]; // 1 is first index
int targetBuilding;
int memo[1001] ;



int countCost(int bNum) {
  // check if calculated b4
  if (memo[bNum] != 0) {
    return memo[bNum];
  }
  
  int findRule[100001], ruleTemp = 0; // 0 is first index
  // base case
  for (int i = 1; i <= ruleNum; i++) {
    if (rules[i][1] == bNum) { // check pre-required rules
      findRule[ruleTemp++] = rules[i][0];
    }
  }
  //cout << "bNum : " << bNum << " ruleTemp : " << ruleTemp << endl;
  if (ruleTemp == 0) {
    memo[bNum] = buildingCost[bNum];
    return buildingCost[bNum];
  }

  /*
  for (int i = 0; i < ruleTemp; i++)
    cout << findRule[i] << " ";
  cout << endl;
  */
  
  // DP
  int temp = countCost(findRule[0]), temp2;
  for (int i = 1; i < ruleTemp; i++) {
    temp2 = countCost(findRule[i]);
    if (temp < temp2)
      temp = temp2;
  }

  memo[bNum] = temp + buildingCost[bNum];
  /*
  cout << bNum << " : " << temp << " "
       << buildingCost[bNum] << " " << memo[bNum] << endl;
  */
  return memo[bNum];
}

int main() {
  cin >> caseNum;

  while(caseNum--) {
    cin >> buildingNum >> ruleNum;

    memset(buildingCost, 0, sizeof(int) * buildingNum );
    memset(memo, 0, sizeof(int) * buildingNum );
    memset(rules, 0, sizeof(int) * ruleNum * 2 );
    
    for (int i = 1; i <= buildingNum; i++)
      cin >> buildingCost[i];
    for (int j = 1; j <= ruleNum; j++)
      cin >> rules[j][0] >> rules[j][1];

    cin >> targetBuilding;

    cout << countCost(targetBuilding) << endl;
    
  }
  
  
  return 0;
}
