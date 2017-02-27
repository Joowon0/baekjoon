#include <stdio.h>
//#include <iostream>
//#include <algorithm>

//using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}


void quickSort(int inArr[], int size) {
	if (size <= 1)	// base case 
		return;

	int pivotIndex = 0, pivotVal = inArr[0];	//pivot is the first one
	int frontIndex = 1, rearIndex = size - 1;
	for(int i = 1; i < size; i++) {
		if (inArr[i] < pivotVal)				// smaller than pivot => go to not fulled most left
			swap(inArr[i], inArr[frontIndex++]);
		else							// bigger than pivot -> go to not fulled most right
			swap(inArr[i--], inArr[rearIndex--]);

		if (frontIndex >= rearIndex || i >= rearIndex) {	//end sorting
				if (frontIndex > rearIndex || inArr[frontIndex] >= pivotVal) {	// ( frontIndex > rearIndex ) 
					frontIndex--;						// => two numbers and the first is bigger than the second
				}								// ( inArr[frontIndex] >= pivotVal )
				break;								// => sorting for the last number
			}
	}
	if (inArr[0] > inArr[frontIndex])	// when the first(pivot) is not the smallest
		swap(inArr[0], inArr[frontIndex]);

	quickSort(inArr, frontIndex);
	quickSort(inArr + (frontIndex + 1), size - frontIndex - 1 ); 
}

int main() {
  int caseNum;
  int inNum[1000001];

  //cin >> caseNum;
  scanf("%d", &caseNum);
  for (int i = 0; i < caseNum; i++)
    scanf("%d", &inNum[i]);
    //cin >> inNum [i];

  quickSort (inNum, caseNum);
  //sort(inNum, inNum + caseNum);

  for (int i = 0; i < caseNum; i++)
    printf("%d\n", inNum[i]);
    //cout << inNum[i] << endl;
  
  
  return 0;
}
