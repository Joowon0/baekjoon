#include <stdio.h>
#include <vector>

using namespace std;

int costs[1001];
int memo[1001];
vector<int> prereq[1001]; // prereq[i] - list of builings to build i

int findCost(int target) {
  if (memo[target] > -1) // already counted
    return memo[target];
  else {
    int maxPreCost = findCost(prereq[target][0]);

    for (int i = 1; i < prereq[target].size(); i++) {
      int preCost = findCost(prereq[target][i]);

      if (maxPreCost < preCost )
	maxPreCost = preCost;
    }

    memo[target] = maxPreCost + costs[target];
    return memo[target];
  }
}

int main() {
  int caseNum, buildingNum, ruleNum;
  int targetNum;

  scanf("%d", &caseNum);

  while(caseNum--) {
    scanf("%d %d", &buildingNum, &ruleNum);

    for(int i = 0; i <= buildingNum; i++) {
      memo[i] = -1;
      prereq[i].clear();
    }

    int temp;
    for(int i = 1; i <= buildingNum; i++)
      scanf("%d", costs+i);

    int src, dst;
    while(ruleNum--) {
      scanf("%d %d", &src, &dst);
      prereq[dst].push_back(src);
    }

    // base case for no prerequisite
    for (int i = 1; i <= buildingNum; i++)
      if (prereq[i].size() == 0)
	memo[i] = costs[i];

    scanf("%d", &targetNum);

    printf("%d\n", findCost(targetNum));
  }
  
  
  return 0;
}
