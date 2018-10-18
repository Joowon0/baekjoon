#include <stdio.h>
#include <vector>

using namespace std;

void mergeSort(int* nums, int start, int end) { 
  if (end - start <= 1)
    return;
  
  int halfIndex = (start + end) / 2;

  mergeSort(nums, start, halfIndex);
  mergeSort(nums, halfIndex, end);

  int* temp = new int[end-start];
  int x = 0;
  int i = start, j = halfIndex;
  while (i < halfIndex && j < end) {
    if (nums[i] < nums[j])
      temp[x++] = nums[i++];
    else
      temp[x++] = nums[j++];
  }

  while(i < halfIndex)
    temp[x++] = nums[i++];
  while(j < end)
    temp[x++] = nums[j++];

  i = start;
  x = 0;
  while(i < end)
    nums[i++] = temp[x++];

  // printf("called start : %d end : %d\n", start, end);
  // // printf("front[%d] : ", front.size());
  // // for(int i = 0; i < front.size(); i++)
  // //   printf("%d ", front[i]);
  // // printf("\n");

  // // printf("back[%d] : ", back.size());
  // // for(int i = 0; i < back.size(); i++)
  // //   printf("%d ", back[i]);
  // // printf("\n");
  
  // printf("returned[%d] : ", end - start);
  // for(int i = start; i < end; i++)
  //   printf("%d ", nums[i]);
  // printf("\n\n");
}

int main() {
  int num;
  scanf("%d", &num);
  
  int* ins = new int[num];
  for (int i = 0; i < num; i++)
    scanf("%d", &ins[i]);

  mergeSort(ins, 0, num);
  for (int i = 0; i < num; i++)
    printf("%d\n", ins[i]);
  return 0;
}
