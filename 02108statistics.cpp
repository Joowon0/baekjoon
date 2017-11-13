#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>

using namespace std;

int nums[500002];
int numApp[8002]; // num of appearance of i = > nums[i + 4000]

int main() {
  int caseNum;
  long long sum = 0;
  cin >> caseNum;

  for (int i = 0; i < caseNum; i++) {
    cin >> nums[i];
    sum += nums[i];
    numApp[nums[i]+4000]++;
  }

  sort(nums, nums+caseNum);

  int maxVal = *max_element(numApp,numApp+8001);
  //cout << "MAX : " << maxVal << endl;
  bool fndFirst = false, fndSnd = false;
  int  valFirst, valSnd;
  
  for (int i = 0; i < 8002; i++)
    if(numApp[i] == maxVal) {
      if (fndFirst == false) {
	valFirst = i - 4000;
	fndFirst = true;
      }
      else {
	valSnd = i - 4000;
	fndSnd = true;
	break;
      }	
    }
  

  // 1. Mean
  cout << floor((long double) sum / caseNum + 0.5) << endl;
  // 2. Middle
  cout << nums[caseNum/2] << endl;

  // 3.Most common (second smallest)
  if (fndFirst == false) {
    for(int i = 0; i < 100000; i++)
      cout << "ERROR"<< endl;
  }
  else if (fndSnd == false) {
    cout << valFirst << endl;
  }
  else
    cout << valSnd << endl;

  // 4. Range
  cout << nums[caseNum-1] - nums[0] << endl;
  
  return 0;
}
