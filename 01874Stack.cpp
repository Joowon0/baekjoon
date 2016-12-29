#include <stdio.h>
#include <string>

using namespace std;


int main() {
  int caseNum, numArr[100000], numTemp = 0;
  int stack[100000], stackPtr = 0;
  string result = "";

  scanf("%d", &caseNum);
  
  for (int i = 0; i < caseNum; i++) {
    scanf("%d", &numArr[i]);
  }

  for (int i = 1; i <= caseNum; i++) {
    stack[++stackPtr] = i;
    //cout << "+" << endl;
    //printf("+\n");
    result += "+\n";
    
    while(stackPtr != 0 && stack[stackPtr] == numArr[numTemp]) {
      //printf("- %d\n", stack[stackPtr]);
      result += "-\n";
      stackPtr--;
      numTemp++;
    }
  }

  if (stackPtr == 0)
    printf("%s", result.c_str());
  else               // isn't this out of condition??
    printf( "NO\n"); // every number array with the condition make sense
  
  return 0;
}
