#include <iostream>
#include <algorithm>

using namespace std;

int nums [25];

int findCombiNum(int target, int start, int end) {
  if (target == 0 || target == nums[start])
    return 1;
  else {
    int counter = 0;
    for (int i = start; i < end && target >= nums[i]; i++) {
      int found =  findCombiNum(target - nums[i], i+1, end);
      counter +=found;

      // cout << target << " " << i << " : " << found << endl;
    }

    // cout << "Called target : " << target <<
    //   "\trange : [" << start << "~" << end << "]" <<
    //   "\tval : " << counter << endl;
      
    return counter;
  }
}

int main() {
  int numNum, targetNum;
  int negNum, posStart;

  cin >> numNum >> targetNum;

  for (int i = 0; i < numNum; i++)
    cin >> nums[i];

  sort(nums, nums + numNum);

  // find out number of negs and pos's start index
  int i;
  negNum = posStart = numNum;
  for (i = 0; i < numNum; i++) {
    if (0 <= nums[i]) {
      negNum = i;
      break;
    }
  }

  for (; i < numNum; i++) {
    if (0 < nums[i]) {
      posStart = i;
      break;
    }
  }

  //
  if (targetNum > 0)
    cout << findCombiNum(targetNum, posStart, numNum) << endl;
  

  cout << negNum << " " << posStart << endl;
  
  for (int i = 0; i < numNum; i++)
    cout << nums[i] << " ";
  
  return 0;
}
