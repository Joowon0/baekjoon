#include <iostream>

using namespace std;

int main() {
  int stringNum, brandNum;
  int brandCost[51][2]; // 0 - package / 1 - one by one

  int cheapestCost[2];
  int isPackageCheaper;
  int minCost;

  
  cin >> stringNum >> brandNum;

  for(int i = 0; i < brandNum; i++)
    cin >> brandCost[i][0] >> brandCost[i][1];

  // find cheapest cost among packages and ones
  cheapestCost[0] = brandCost[0][0];
  cheapestCost[1] = brandCost[0][1];
  for (int i = 1; i < brandNum; i++) {
    if (cheapestCost[0] > brandCost[i][0])
      cheapestCost[0] = brandCost[i][0];
    if (cheapestCost[1] > brandCost[i][1])
      cheapestCost[1] = brandCost[i][1];
  }

  // find cheapest with combines

  // case (1) : buying ones are cheaper than packages
  if (cheapestCost[0] > cheapestCost[1] * 6)
    cout << cheapestCost[1] * stringNum << endl;
  else {
    // case (2) : buying only packages is the cheapest
    int onlyPackage = cheapestCost[0] * (stringNum / 6 + 1);

    // case (3) : combinations are cheapest
    int packageNum = stringNum / 6;
    int onesNum = stringNum % 6;
    int combinations = cheapestCost[0] * packageNum
      + cheapestCost[1] * onesNum;

    if (onlyPackage < combinations)
      cout << onlyPackage << endl;
    else
      cout << combinations << endl;
  }
  
  return 0;
}
