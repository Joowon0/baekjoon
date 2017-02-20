#include <stdio.h>
#include <string.h>

int main() {
  int caseNum;
  char dump, functions[100000], temp[300000];
  int arrNum, arr[100000], front, rear;
  bool isReverse, isError;

  scanf("%d", &caseNum);

  while(caseNum--) {
    // get inputs
    scanf("%s", functions);
    scanf("%d", &arrNum);
    scanf("%s", temp);

    int t = 0, n = 0;
    for (int i = 1; i < strlen(temp); i++) {
      if (temp[i] <= '9' && '0' <= temp[i])
	n = n * 10 + temp[i] - '0';
      else {
	arr[t++] = n;
	n = 0;
      }
    }
    
    front = 0; rear = arrNum - 1;
    isReverse = 0, isError = 0;


    // print for test
    /*
    printf("%s\n", functions);
    printf("%d\n", arrNum);
    printf("%d %d\n", front, rear);
    for (int i = 0; i < arrNum; i++)
      printf("%d ", arr[i]);
    printf("\n\n");
    */

    // act functions
    for (int i = 0; i < strlen(functions); i++) {
      if (functions[i] == 'R') { // reverse
	isReverse = !isReverse;
      }
      else if (functions[i] == 'D') { // drop
	if (front > rear) {
	  isError = 1;
	  break;
	}
	else if (!isReverse) {
	  front++;
	}
	else {
	  rear--;
	}
      }
    }

    // print result
    if (isError)
      printf("error\n");
    else if (front > rear)
      printf("[]\n");
    else {
      if (!isReverse) {
	printf("[");
	for (int i = front; i < rear; i++)
	  printf("%d,", arr[i]);
	printf("%d]\n", arr[rear]);
      }
      else {
	printf("[");
	for (int i = rear; i > front; i--)
	  printf("%d,", arr[i]);
	printf("%d]\n", arr[front]);
      }
    }
  }
  
  return 0;
}
