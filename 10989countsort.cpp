#include <stdio.h>
//#include <string.h>

int nums[10001];

int main() {
  int caseNum;
  int temp;

  scanf("%d", &caseNum);
  //memset(nums, 0, 10001);
  
  for (int i = 0; i < caseNum; i++) {
    scanf("%d", &temp);
    nums[temp]++;
  }

  for (int i = 0; i < 10001; i++) {
    //printf("%d %d\n", i, nums[i]);
    
    while(nums[i]--)
      printf("%d\n", i);
    
  }
  
  return 0;
}
